#pragma once
#include <vector>

struct Point
{
	int x{ 0 };
	int y{ 0 };
};

class Player
{
public:
	Player(Point position, std::vector<char> controllKeys);

	void setPosition(Point position);
	Point position();

	void setControllKeys(char left, char right, char down, char up);
	std::vector<char> controllKeys();

private:
	Point _position;
	std::vector<char> _controllKeys;
};

