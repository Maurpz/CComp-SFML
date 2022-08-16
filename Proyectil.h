#pragma once
#include "SFML/Graphics.hpp"
#include "Collisionable.h"
#pragma once
using namespace sf;

class Proyectil : public Drawable, public Collisionable
{
	Sprite _sprite;
	Texture _textura;
	Vector2f _velocidad;

	//float _frame;

public:
	Proyectil();
	void update(Vector2i pos, Vector2i mouse_pos);
	void draw(RenderTarget& target, RenderStates states)const override;
	//el override es para decirle que estoy sobre escribiendo

	void respawn(Vector2i pos);
	//metodo para detectar las colisiones del personaje
	FloatRect getBounds() const override;
	//void hited();

	//void agregarVelocidad(float velocity);
};
