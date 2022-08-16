#pragma once
#include "SFML/Graphics.hpp"
#include "Collisionable.h"

class Item : public sf::Drawable, public Collisionable
{
    sf::Sprite _sprite;
    sf::Texture _texture;

public:
    Item();
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void respawn();
    sf::FloatRect getBounds() const override;
};
