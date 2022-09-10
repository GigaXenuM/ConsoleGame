#include "mainwindow.h"

#include "scene/controller/controller.h"

#include "utils/utils.h"

using Utils::State;

MainWindow::MainWindow(unsigned int width, unsigned int height, std::string title)
    : sf::RenderWindow{ sf::VideoMode({ width, height }), title },
      _sceneController{ std::make_shared<Scene::Controller>(this) }
{
    for (size_t i = 0; i < 512; ++i)
        _keys[i] = false;
    _player.setPosition({ static_cast<float>(width / 2), static_cast<float>(height / 2) });
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

        updatePlayer();
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
    _keys[key.code] = true;
}

void MainWindow::keyReleaseEvent(sf::Event::KeyEvent key)
{
    _keys[key.code] = false;
}

void MainWindow::updatePlayer()
{
    float speed{ 0.01f };
    if (_keys[sf::Keyboard::A])
        _player.move({ -speed, .0f });
    if (_keys[sf::Keyboard::D])
        _player.move({ speed, .0f });
    if (_keys[sf::Keyboard::W])
        _player.move({ .0f, -speed });
    if (_keys[sf::Keyboard::S])
        _player.move({ .0f, speed });
}
