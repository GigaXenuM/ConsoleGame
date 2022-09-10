#pragma once

#include "item.h"

#include "utils/utils.h"

#include <SFML/Graphics.hpp>

using Utils::State;

namespace Scene
{
class Player : public Item, public sf::CircleShape
{
public:
    Player();
    Utils::State movingEnabled();
    void setMovingEnabled(State enabled);

private:
    State _movingEnabled{ Utils::State::Disable };
};
} // namespace Scene
