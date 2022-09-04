#include "scene/scene.h"

#include <Windows.h>

int main()
{
	Scene game;
	game.addPlayer({ 'A', 'D', 'S', 'W' });
	game.addPlayer({ VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP });
	game.run();
}