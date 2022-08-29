#pragma once
#include "SFML/Graphics.hpp"
#include "Collisionable.h"
#pragma once
using namespace sf;

class Vida : public Drawable, public Collisionable
{
	int valor = 1;
	Sprite _sprite;
	Texture _textura;
	Vector2f _velocidad;
	//int estado=1;

	//float _frame;

public:
	Vida();
	void update();
	void draw(RenderTarget& target, RenderStates states)const override;
	void respawn();
	int get_valor();
	FloatRect getBounds() const override;

};
