#pragma once

#include "Entity.h"


class Projectile : public Entity
{
public:
    float movement_speed = 1.5;
    int attack_damage = 1;

    enum Direction
    {
        l, r, u, d
    };
    Direction direction;

    Projectile();
    void update();
};
