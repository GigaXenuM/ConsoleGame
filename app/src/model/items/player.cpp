#include "player.h"

namespace Model
{
Player::Player(Point position) : _position{ std::move(position) }
{
}

void Player::setPosition(Point position)
{
    _position = std::move(position);
}

Point Player::position() const
{
    return _position;
}
} // namespace Model
