#include "mainwindow.h"

#include "scene/controller/controller.h"

MainWindow::MainWindow(unsigned int width, unsigned int height, std::string title)
    : sf::RenderWindow{ sf::VideoMode({ width, height }), title },
      _sceneController{ std::make_shared<Scene::Controller>(this) }
{
}

void MainWindow::render()
{
    while (isOpen())
    {
        sf::Event event;
        while (pollEvent(event))
        {
            filterEvent(event);
        }

        clear(sf::Color(129, 211, 88));

        draw(_player);

        display();
    }
}

void MainWindow::filterEvent(sf::Event event)
{
    if (event.type == sf::Event::Closed)
        close();
    if (event.type == sf::Event::KeyPressed)
        keyPressEvent(event.key);
    if (event.type == sf::Event::KeyReleased)
        keyReleaseEvent(event.key);
}

void MainWindow::keyPressEvent(sf::Event::KeyEvent key)
{
    float speed = 5;

    if (key.code == sf::Keyboard::A)
        _player.move({ -speed, .0 });
    if (key.code == sf::Keyboard::D)
        _player.move({ +speed, .0 });
    if (key.code == sf::Keyboard::W)
        _player.move({ .0, -speed });
    if (key.code == sf::Keyboard::S)
        _player.move({ .0, +speed });
}

void MainWindow::keyReleaseEvent(sf::Event::KeyEvent /*unused*/)
{
}
