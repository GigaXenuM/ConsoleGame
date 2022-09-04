#include <iostream>
#include <thread>
#include <chrono>
#include <conio.h>
#include <Windows.h>
#include <vector>

struct Point
{
	int x{ 0 };
	int y{ 0 };
};

class Player
{
public:
	Player(Point position, std::vector<char> controllKeys) : _position{ std::move(position) }, _controllKeys{ std::move(controllKeys) }
	{
		_controllKeys.reserve(4);
	}
	void setPosition(Point position)
	{
		_position = std::move(position);
	}

	Point position()
	{
		return _position;
	}

	void setControllKeys(char left, char right, char down, char up)
	{
		_controllKeys.clear();
		_controllKeys = { left , right , down , up };
	}
	std::vector<char> controllKeys()
	{
		return _controllKeys;
	}

private:
	Point _position;
	char _left, _right, _up, _down;
	std::vector<char> _controllKeys;
};

class Game
{
public:
	Game(int width = 100, int height = 25) : _gameMap{ new char* [height] }, _width{ width }, _height{ height }
	{
		for (size_t i = 0; i < height; ++i)
		{
			_gameMap[i] = new char[width];
		}

		for (size_t i = 0; i < height; ++i)
		{
			for (size_t j = 0; j < width - 1; ++j)
			{
				if (i == 0 || i == height - 1 || j == 0 || j == width - 2)
					_gameMap[i][j] = '#';
				else
					_gameMap[i][j] = ' ';
			}
			_gameMap[i][width - 1] = '\0';
		}
	}

	~Game()
	{
		for (auto* player : _players)
			delete player;

		for (size_t i = 0; i < _height; ++i)
		{
			delete[] _gameMap[i];
		}
		delete[] _gameMap;
	}

	void run()
	{
		std::thread t([&]() {while (true)
		{
			for (size_t i = 0; i < _height; ++i)
			{
				char playerName{ 'A' };
				for (auto* player : _players)
				{
					_gameMap[player->position().y][player->position().x] = playerName++;
				}
				std::cout << _gameMap[i] << std::endl;
			}

			for (auto player : _players)
			{

				if (GetAsyncKeyState(player->controllKeys()[0]))
				{
					_gameMap[player->position().y][player->position().x] = ' ';
					if (player->position().x > 2)
						player->setPosition({ player->position().x - 2 , player->position().y });
				}
				if (GetAsyncKeyState(player->controllKeys()[1]))
				{
					_gameMap[player->position().y][player->position().x] = ' ';
					if (player->position().x < _width - 4)
						player->setPosition({ player->position().x + 2 , player->position().y });
				}
				if (GetAsyncKeyState(player->controllKeys()[2]))
				{
					_gameMap[player->position().y][player->position().x] = ' ';
					if (player->position().y < _height - 2)
						player->setPosition({ player->position().x , player->position().y + 1 });
				}
				if (GetAsyncKeyState(player->controllKeys()[3]))
				{
					_gameMap[player->position().y][player->position().x] = ' ';
					if (player->position().y > 1)
						player->setPosition({ player->position().x , player->position().y - 1 });
				}
			}

			std::this_thread::sleep_for(std::chrono::microseconds(10000));
		}});
		t.join();
	}

	void addPlayer(std::vector<char> controllKeys)
	{
		_players.push_back(new Player({ 20, 10 }, std::move(controllKeys)));
	}
private:
	std::vector<Player*> _players;
	char** _gameMap{ nullptr };
	int _width{ 0 };
	int _height{ 0 };
};

int main()
{
	Game game;
	game.addPlayer({ 'A', 'D', 'S', 'W' });
	game.addPlayer({ VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP });
	game.run();
}