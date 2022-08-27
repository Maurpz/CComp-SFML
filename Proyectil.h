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
    //int estado=1;

	//float _frame;

public:
	Proyectil();
	void update(Vector2i pos, Vector2i mouse_pos);
	void draw(RenderTarget& target, RenderStates states)const override;
	//el override es para decirle que estoy sobre escribiendo
    //void cambiar_estado(int e);
    //void imprimir();
	void respawn(Vector2i pos);
	//metodo para detectar las colisiones del personaje
	FloatRect getBounds() const override;
	//void hited();

	//void agregarVelocidad(float velocity);
};

/*
class Nodo {
public:
    Proyectil dato;
    Nodo* siguiente;
};


Nodo* ingresar(Nodo*& inicio, Proyectil n) {
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = nullptr;

    if (inicio == nullptr) {
        inicio = nuevo_nodo;
    }
    else {
        Nodo* aux = inicio;
        while (aux->siguiente != nullptr) {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo_nodo;
    }
    return inicio;
};
*/