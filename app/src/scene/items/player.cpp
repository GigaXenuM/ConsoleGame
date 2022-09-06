#include "player.h"

namespace Scene
{
Player::Player() : sf::CircleShape{ 20 }
{
    setFillColor(sf::Color(255, 123, 45));
}
} // namespace Scene
