#include "Player.h"

Player::Player()
{
    rect.setSize(Vector2f(32,45));
    rect.setPosition(200, 200);
}

void Player::update()
{
    sp.setPosition(rect.getPosition());
}

void Player::movement()
{
    movement_offset = 0.2;

    if (Keyboard::isKeyPressed(Keyboard::Left)) {
        direction = Player::l;
        sp.setTextureRect(IntRect(walk_counter*32,50,32,45));
        rect.move(-movement_offset,0);
    }
    if (Keyboard::isKeyPressed(Keyboard::Right)) {
        direction = Player::r;
        sp.setTextureRect(IntRect(walk_counter*32,100,32,45));
        rect.move(movement_offset,0);
    }
    if (Keyboard::isKeyPressed(Keyboard::Up)) {
        direction = Player::u;
        sp.setTextureRect(IntRect(walk_counter*32,145,32,45));
        rect.move(0,-movement_offset);
    }
    if (Keyboard::isKeyPressed(Keyboard::Down)) {
        direction = Player::d;
        sp.setTextureRect(IntRect(walk_counter*32,0,32,45));
        rect.move(0,movement_offset);
    }
    walk_counter++;
    if (walk_counter > 3) walk_counter = 0;
}
