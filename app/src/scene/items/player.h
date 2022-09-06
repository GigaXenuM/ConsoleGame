#pragma once

#include "item.h"

#include <SFML/Graphics.hpp>

namespace Scene
{
class Player : public Item, public sf::CircleShape
{
public:
    Player();
};
} // namespace Scene
