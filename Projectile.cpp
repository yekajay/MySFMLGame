#include "Projectile.h"

Projectile::Projectile()
{
    rect.setSize(Vector2f(8,8));
    rect.setFillColor(Color::Red);
}

void Projectile::update()
{
    if (direction == Projectile::l) {
        rect.move(-movement_speed,0);
    }
    if (direction == Projectile::r) {
        rect.move(movement_speed,0);
    }
    if (direction == Projectile::u) {
        rect.move(0,-movement_speed);
    }
    if (direction == Projectile::d) {
        rect.move(0,movement_speed);
    }
}
