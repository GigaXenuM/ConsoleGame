#include "mainwindow.h"

#include <SFML/Graphics.hpp>

MainWindow::MainWindow(unsigned int width, unsigned int height, std::string title)
    : _window{ std::make_shared<sf::RenderWindow>(sf::VideoMode({ width, height }), title) }
{
}

void MainWindow::render()
{
    while (_window->isOpen())
    {
        sf::Event event;
        while (_window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                _window->close();
        }
        // Отрисовка окна
        _window->display();
    }
}
