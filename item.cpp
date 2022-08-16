#include "item.h"
#include <stdlib.h>


Item::Item()
{
    _texture.loadFromFile("moneda.png");

    //agregar textura al sprite
    _sprite.setTexture(_texture);

    //modificamos el punto de agarre del sprite 
    _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
}

void Item::update()
{

}

void Item::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}

void Item::respawn()
{
    //ponemos una posicion aleatoria para nuestro item(anillo)
    _sprite.setPosition(std::rand() % 700 + _sprite.getGlobalBounds().width, std::rand() % 500 + _sprite.getGlobalBounds().height);
}

sf::FloatRect Item::getBounds() const
{
    return _sprite.getGlobalBounds();
}