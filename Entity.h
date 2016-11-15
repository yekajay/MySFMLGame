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

using namespace std;
using namespace sf;


class Entity
{
public:
    RectangleShape rect;
    Sprite sp;
    Text tx;
};
