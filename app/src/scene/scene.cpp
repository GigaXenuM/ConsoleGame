#include "scene.h"

#include "player.h"
#include "item/bitcoin.h"

#include <iostream>
#include <Windows.h>
#include <thread>

Scene::Scene(int width, int height) : _gameMap{ new char* [height] }, _width{ width }, _height{ height }
{
	for (int i = 0; i < _height; ++i)
	{
		_gameMap[i] = new char[_width];
	}

	for (int i = 0; i < _height; ++i)
	{
		for (int j = 0; j < _width - 1; ++j)
		{
			if (i == 0 || i == _height - 1 || j == 0 || j == _width - 2)
				_gameMap[i][j] = '#';
			else
				_gameMap[i][j] = ' ';
		}
		_gameMap[i][_width - 1] = '\0';
	}
}

Scene::~Scene()
{
	for (auto* player : _players)
		delete player;
	for (auto* bitCoin : _bitCoins)
		delete bitCoin;

	for (int i = 0; i < _height; ++i)
	{
		delete[] _gameMap[i];
	}
	delete[] _gameMap;
}

void Scene::run()
{
	std::thread t([&]() {while (true)
	{
		for (int i = 0; i < _height; ++i)
		{
			char playerName{ 'A' };
			for (auto* player : _players)
			{
				_gameMap[player->position().y()][player->position().x()] = playerName++;
			}
			std::cout << _gameMap[i] << std::endl;
		}

		for (auto* item : _players)
		{
			auto* player{ dynamic_cast<Player*>(item) };
			if (player == nullptr)
				continue;

			if (GetAsyncKeyState(player->controllKeys()[0]))
			{
				_gameMap[player->position().y()][player->position().x()] = ' ';
				if (player->position().x() > 2)
					player->setPosition({ player->position().x() - 2 , player->position().y() });
			}
			if (GetAsyncKeyState(player->controllKeys()[1]))
			{
				_gameMap[player->position().y()][player->position().x()] = ' ';
				if (player->position().x() < _width - 4)
					player->setPosition({ player->position().x() + 2 , player->position().y() });
			}
			if (GetAsyncKeyState(player->controllKeys()[2]))
			{
				_gameMap[player->position().y()][player->position().x()] = ' ';
				if (player->position().y() < _height - 2)
					player->setPosition({ player->position().x() , player->position().y() + 1 });
			}
			if (GetAsyncKeyState(player->controllKeys()[3]))
			{
				_gameMap[player->position().y()][player->position().x()] = ' ';
				if (player->position().y() > 1)
					player->setPosition({ player->position().x() , player->position().y() - 1 });
			}
		}

		std::this_thread::sleep_for(std::chrono::microseconds(10000));
	}});
	t.join();
}

void Scene::addPlayer(const std::vector<char>& controllKeys)
{
	_players.push_back(new Player({ 20, 10 }, controllKeys));
}

void Scene::addBitCoins()
{
	Point position{ 0, 0 };

	_bitCoins.push_back(new BitCoin(std::move(position), 5));
}