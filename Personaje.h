#include "SFML/Graphics.hpp"
#include "Collisionable.h"
#include "Vida.h"
#pragma once
using namespace sf;

//todos lo objetos que son drawables tiene un metodo polimorfico el cual nos permite sobreescribir
//en mi  personaje para indicar en que forma este personaje se va dibujar

//al ser un objeto dibujable se lo podemos dar a window
class Personaje: public Drawable, public Collisionable
{
	//num vidas
	int vida_jugador = 3;
	//arma
	Sprite _arma;
	Texture t_arma;
	

	//personaje
	Sprite _sprite;
	Texture _textura;


	Vector2f _velocidad;
	Vector2i _pos_mouse;
	float _frame;
	
public:
	Personaje();
	void update();
	void draw(RenderTarget& target, RenderStates states)const override;
	//void navajazo(RenderTarget& target, RenderStates states)const override;
	//el override es para decirle que estoy sobre escribiendo
	
	//metodo para detectar las colisiones del personaje
	FloatRect getBounds() const override;
	void hited();

	Vector2i obtener_pos();

	Vector2i obtener_mouse();

	void agregarVelocidad(float velocity);

	int getVida();

	void operator()(Vida obj);

	void da�o();
};

