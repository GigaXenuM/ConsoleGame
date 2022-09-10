#pragma once

#include "scene/items/player.h"

#include <SFML/Graphics.hpp>

#include <memory>
#include <string>
#include <vector>

namespace Scene
{
class Controller;
} // namespace Scene

class MainWindow : sf::RenderWindow
{
public:
    MainWindow(unsigned int width, unsigned int height, std::string title);
    ~MainWindow() = default;

    void render();

private:
    void filterEvent(sf::Event event);
    void keyPressEvent(sf::Event::KeyEvent event);
    void keyReleaseEvent(sf::Event::KeyEvent event);
    void updatePlayer();

    std::shared_ptr<Scene::Controller> _sceneController;

    Scene::Player _player;
    bool _keys[512];
    std::vector<int> _controlKeys;
};
