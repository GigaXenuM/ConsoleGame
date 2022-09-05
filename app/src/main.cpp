#include "mainwindow.h"

#include <Windows.h>

int main()
{
    MainWindow mainWindow{ 640, 480, "GARIK" };

    mainWindow.render();
    //    Scene scene;
    //    scene.addPlayer({ 'A', 'D', 'S', 'W' });
    //    scene.addPlayer({ VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP });
    //    scene.run();
}
