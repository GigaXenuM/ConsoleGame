#pragma once

#include "item/iitem.h"
#include "item/point.h"

#include <vector>

class Player : public IItem
{
public:
	Player(Point position, std::vector<char> controllKeys);

	void setPosition(Point position) override;
	Point position() const override;

	void setControllKeys(char left, char right, char down, char up);
	std::vector<char> controllKeys() const;

private:
	Point _position;
	std::vector<char> _controllKeys;
};

