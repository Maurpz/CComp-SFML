#include "Personaje.h"
using namespace std;
using namespace std;

Personaje::Personaje()
{ 
    _frame = 0;
    _velocidad = {4,4};


    _textura.loadFromFile("chari_sheet.png");
    //agregar textura al sprite
    _sprite.setTexture(_textura);
    _sprite.setTextureRect({ 4, 0, 62, 60 });

    //modificamos el punto de agarre del sprite 
    _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);

    
    //agregando arma
    t_arma.loadFromFile("cuchillo.png");
    _arma.setTexture(t_arma);
    _arma.setOrigin(_arma.getGlobalBounds().width / 2, _arma.getGlobalBounds().height);
    _arma.setScale(0.09, 0.09);
    
}

void Personaje::update()
{
    sf::Vector2f velocidad = { 0,0 };
    //_frame += 0.2;
    //_sprite.setTextureRect({ 0 + int(_frame) * 64,0,62,60 });

    if (_frame >= 4) {
        _frame = 0;
    }
    //recogiendo los eventos de movimiento
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        velocidad.y=-_velocidad.y;
        _sprite.setTextureRect({ 0 + int(_frame) * 64,197,62,60 });
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        velocidad.y = +_velocidad.y;
        _sprite.setTextureRect({ 0 + int(_frame) * 64,0,62,60 });
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        velocidad.x = -_velocidad.x;
        _sprite.setTextureRect({ 0 + int(_frame) * 64,77,62,60 });
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        velocidad.x = +_velocidad.x;
        _sprite.setTextureRect({ 0 + int(_frame) * 64,141,62,50 });
    }
    else {
        _sprite.setTextureRect({ 0 + int(_frame) * 64,0,62,60 });
    }
    

    //gira el sprite de manera que mire a donde camina
    _sprite.move(velocidad);
    
    if (velocidad.x < 0||velocidad.y<0) {
        //_sprite.setScale(1, 1);
        _frame += 0.2;
    }
    else if (velocidad.x > 0|| velocidad.y >0) {
        //_sprite.setScale(-1, 1);
        _frame += 0.2;

    }

    


    //delimitar margenes de la pantalla
    if (_sprite.getGlobalBounds().left < 0) {
        _sprite.setPosition(_sprite.getOrigin().x, _sprite.getPosition().y);
    }
    if (_sprite.getGlobalBounds().top < 0) {
        _sprite.setPosition(_sprite.getPosition().x,_sprite.getOrigin().y);
    }
    if (_sprite.getGlobalBounds().left + _sprite.getGlobalBounds().width > 800) {
        _sprite.setPosition(800 -( _sprite.getGlobalBounds().width -_sprite.getOrigin().x), _sprite.getPosition().y);
    }
    if (_sprite.getGlobalBounds().top + _sprite.getGlobalBounds().height > 600) {
        _sprite.setPosition(_sprite.getPosition().x, 600 + (_sprite.getGlobalBounds().height- _sprite.getOrigin().y));
    }
}

void Personaje::draw(RenderTarget& target, RenderStates states)const
{
    target.draw(_sprite, states);
}
/*
void Personaje::navajazo(RenderTarget& target, RenderStates states) {
    target.draw(_arma, states);

}
*/
sf::FloatRect Personaje::getBounds() const
{
    return _sprite.getGlobalBounds();
}

void Personaje::hited()
{
}

void Personaje::agregarVelocidad(float velocidad)
{
    _velocidad.x += velocidad;
    _velocidad.y += velocidad;

}

int Personaje::getVida()
{
    return this->vida_jugador;
}

void Personaje::operator()(Vida obj)
{
    this->vida_jugador += obj.get_valor();
}

void Personaje::da�o()
{
    this->vida_jugador -= 1;
}


Vector2i Personaje::obtener_pos() 
{
    sf::Vector2i pos;
    pos.x = int(_sprite.getPosition().x);
    pos.y= int(_sprite.getPosition().y);
    return pos;
}

Vector2i Personaje::obtener_mouse()
{
    _pos_mouse = Mouse::getPosition();
    //_pos_mouse = (Vector2i)vent.mapPixelToCoords(_pos_mouse);
    return _pos_mouse;
}
