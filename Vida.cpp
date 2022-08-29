#include "Vida.h"
using namespace sf;


Vida::Vida()
{
    _textura.loadFromFile("vida.png");

    //agregar textura al sprite
    _sprite.setTexture(_textura);

    //modificamos el punto de agarre del sprite 
    _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
}

void Vida::update()
{

}

void Vida::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}

void Vida::respawn()
{
    //ponemos una posicion aleatoria para nuestro power(esmeralda)
    //_sprite.setPosition(std::rand()%700 + _sprite.getGlobalBounds().width, std::rand()%500 + _sprite.getGlobalBounds().height);
    _sprite.setPosition(std::rand() % 700 + _sprite.getGlobalBounds().width, std::rand() % 500 + _sprite.getGlobalBounds().height);
}

int Vida::get_valor()
{
    return this->valor;
}

sf::FloatRect Vida::getBounds() const
{
    return _sprite.getGlobalBounds();
}
