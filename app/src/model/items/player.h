#pragma once

#include "iitem.h"
#include "model/point.h"

#include <vector>

namespace Model
{
class Player : public IItem
{
public:
    Player(Point position);

    void setPosition(Point position) override;
    Point position() const override;

private:
    Point _position;
};
} // namespace Model
