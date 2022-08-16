#include "Proyectil.h"

Proyectil::Proyectil()
{
    _velocidad = { 2,-2 };
    _textura.loadFromFile("daño.png");
    //agregar textura al sprite
    _sprite.setTexture(_textura);

    _sprite.setTextureRect({ 153, 0, 47, 45 });

    //modificamos el punto de agarre del sprite 
    _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
}
void Proyectil::update(Vector2i pos, Vector2i mouse_pos)
{
    _velocidad.x = (pos.x - mouse_pos.x)/100;
    _velocidad.y = (pos.y - mouse_pos.y) / 100;
    //sf::Vector2f velocidad = { 0.5,0.5 };
    _sprite.move(_velocidad);
}


void Proyectil::draw(RenderTarget& target, RenderStates states)const
{
    target.draw(_sprite, states);
}

void Proyectil::respawn(Vector2i pos)
{
    //ponemos una posicion aleatoria para nuestro power(esmeralda)
    _sprite.setPosition(pos.x,pos.y);

   

    //_sprite.setPosition(std::rand() % 700 + _sprite.getGlobalBounds().width, std::rand() % 500 + _sprite.getGlobalBounds().height);
}

sf::FloatRect Proyectil::getBounds() const
{
    return _sprite.getGlobalBounds();
}
