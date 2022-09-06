#pragma once

#include "model/controller/controller.h"

#include <memory>

class MainWindow;

namespace Scene
{
class Item;

class Controller
{
public:
    Controller(MainWindow *mainWindow);

    void updateItem(Item *item);

private:
    std::shared_ptr<Model::Controller> _modelController;

    MainWindow *_mainWindow{ nullptr };
};
} // namespace Scene
