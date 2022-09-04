#pragma once
#include "item/iitem.h"
#include <vector>

class Scene
{
public:
	Scene(int width = 100, int height = 25);
	~Scene();

	void run();

	void addPlayer(std::vector<char> controllKeys);
private:
	void addBitCoins();

	std::vector<IItem*> _players;
	std::vector<IItem*> _bitCoins;
	char** _gameMap{ nullptr };
	int _width{ 0 };
	int _height{ 0 };
};

