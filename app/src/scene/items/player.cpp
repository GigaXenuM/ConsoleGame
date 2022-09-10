#include "player.h"

namespace Scene
{
Player::Player() : sf::CircleShape{ 20 }
{
    setFillColor(sf::Color(255, 123, 45));
}

void Player::setMovingEnabled(Utils::State enabled)
{
    _movingEnabled = enabled;
}

Utils::State Player::movingEnabled()
{
    return _movingEnabled;
}
} // namespace Scene
