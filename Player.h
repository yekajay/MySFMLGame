#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <deque>
#include <list>
#include <vector>
#include "Entity.h"

using namespace std;
using namespace sf;


class Player : public Entity
{
public:
    float movement_offset = 0;
    int walk_counter = 0;
    int attack_damage = 5;

    enum Direction
    {
        l, r, u, d
    };
    Direction direction = Player::d;

    Player();
    void update();
    void movement();
};
