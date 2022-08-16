#pragma once
#include "SFML/Graphics.hpp"

//Clase abstracta para programar las colisiones la interfaz de colisones
class Collisionable
{
public:
    virtual sf::FloatRect getBounds() const = 0;
    bool isCollisionable(Collisionable& col) const;
};