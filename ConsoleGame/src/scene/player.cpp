#include "player.h"

Player::Player(Point position, std::vector<char> controllKeys) : _position{ std::move(position) }, _controllKeys{ std::move(controllKeys) }
{
	_controllKeys.reserve(4);
}

void Player::setPosition(Point position)
{
	_position = std::move(position);
}

Point Player::position()
{
	return _position;
}

void Player::setControllKeys(char left, char right, char down, char up)
{
	_controllKeys.clear();
	_controllKeys = { left , right , down , up };
}

std::vector<char> Player::controllKeys()
{
	return _controllKeys;
}
