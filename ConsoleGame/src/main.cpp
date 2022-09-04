#include "scene/scene.h"

#include <Windows.h>

int main()
{
	Scene scene;
	scene.addPlayer({ 'A', 'D', 'S', 'W' });
	scene.addPlayer({ VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP });
	scene.run();
}