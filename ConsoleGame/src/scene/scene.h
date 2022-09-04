#pragma once

#include <thread>
#include "player.h"

class Scene
{
public:
	Scene(int width = 100, int height = 25);
	~Scene();

	void run();

	void addPlayer(std::vector<char> controllKeys);
private:
	std::vector<Player*> _players;
	char** _gameMap{ nullptr };
	int _width{ 0 };
	int _height{ 0 };
};

