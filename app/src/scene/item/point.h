#pragma once

class Point
{
public:
	Point(int x, int y) : _x{ x }, _y{ y }
	{
	}

	Point() = default;
	Point(const Point& point) = default;

	int x() const
	{
		return _x;
	}
	int y() const
	{
		return _y;
	}
private:
	int _x{ 0 };
	int _y{ 0 };
};