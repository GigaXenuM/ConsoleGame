#include "mainwindow.h"

#include <Windows.h>

int main()
{
    MainWindow mainWindow{ 640, 480, "GARIK" };

    mainWindow.render();
}
