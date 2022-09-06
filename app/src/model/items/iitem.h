#pragma once

class Point;

class IItem
{
public:
	virtual void setPosition(Point position) = 0;
	virtual Point position() const = 0;
};

