#include <stdlib.h>
#include "Power.h"

Power::Power()
{
    _texture.loadFromFile("esmeralda.png");

    //agregar textura al sprite
    _sprite.setTexture(_texture);

    //modificamos el punto de agarre del sprite 
    _sprite.setOrigin(_sprite.getGlobalBounds().width/2,_sprite.getGlobalBounds().height/2);
}

void Power::update()
{

}

void Power::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}

void Power::respawn()
{
    //ponemos una posicion aleatoria para nuestro power(esmeralda)
    //_sprite.setPosition(std::rand()%700 + _sprite.getGlobalBounds().width, std::rand()%500 + _sprite.getGlobalBounds().height);
    _sprite.setPosition(std::rand() % 700 + _sprite.getGlobalBounds().width, std::rand() % 500 + _sprite.getGlobalBounds().height);
}

sf::FloatRect Power::getBounds() const
{
    return _sprite.getGlobalBounds();
}

