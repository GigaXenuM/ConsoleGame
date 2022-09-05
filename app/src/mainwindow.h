#pragma once

#include <memory>
#include <string>

namespace sf
{
class RenderWindow;
} // namespace sf

class MainWindow
{
public:
    MainWindow(unsigned int width, unsigned int height, std::string title);

    void render();

private:
    std::shared_ptr<sf::RenderWindow> _window;
};
