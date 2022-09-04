#pragma once

#include "iitem.h"
#include "point.h"

class BitCoin : public IItem
{
public:
	BitCoin(Point position, int pointCount);

	void setPosition(Point position) override;
	Point position() override;

	int pointCount();
private:
	int _pointCount{ 0 };
	Point _position;
};

