#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Projectile.h"
#include <string>
#include <sstream>

using namespace std;
using namespace sf;


int mlin(int, char const**)
{
    RenderWindow win{VideoMode(700, 500), "Canvas 1"};

    Image icon;
    if (!icon.loadFromFile("icon.png")) {
        return EXIT_FAILURE;
    }
    win.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    Texture texturePlayer;
    if (!texturePlayer.loadFromFile("moving.png")) {
        return EXIT_FAILURE;
    }

    Font font;
    if (!font.loadFromFile("sansation.ttf")) {
        return EXIT_FAILURE;
    }
    Text text{"Hi", font, 180};
    text.setFillColor(Color::Black);

    Music music;
    if (!music.openFromFile("nice_music.ogg")) {
        return EXIT_FAILURE;
    }
    //music.play();

    Player p1;
    p1.sp.setTexture(texturePlayer);
    p1.sp.setTextureRect(IntRect(0,0,32,45));

    vector<Projectile> vProjectile;
    Projectile proj;

    while (win.isOpen())
    {
        Event event;
        while (win.pollEvent(event))
        {
            if (event.type == Event::Closed) {
                win.close();
            }

            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Q) {
                win.close();
            }
        }
        win.clear();

        if (Keyboard::isKeyPressed(Keyboard::Space)) {
            proj.rect.setPosition(p1.rect.getPosition());
            proj.direction = (Projectile::Direction)p1.direction;
            vProjectile.push_back(proj);
        }

        for (auto it = vProjectile.begin(); it != vProjectile.end(); ++it) {
            it->update();
            win.draw(it->rect);
        }

        p1.movement();
        p1.update();

        win.draw(p1.sp);
        win.display();
    }

    return EXIT_SUCCESS;
}
