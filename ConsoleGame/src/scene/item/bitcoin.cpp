#include "bitcoin.h"

#include <memory>

BitCoin::BitCoin(Point position, int pointCount) : _position{ std::move(position) }, _pointCount{ pointCount }
{
}

void BitCoin::setPosition(Point position)
{
	_position = std::move(position);
}

Point BitCoin::position()
{
    return _position;
}

int BitCoin::pointCount()
{
	return _pointCount;
}
