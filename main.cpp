#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <stdlib.h>
#include <ctime>
#include"Personaje.h"
#include "item.h"
#include "Power.h"
#include "Enemy.h"
#include "Proyectil.h"
#include <iostream>

int main()
{
    //usamos srand para poner una posicion aletoria del objeto item(anillo)
    std::srand((unsigned)std::time(0));

    //Inicicalizar ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "Proyecto 1");
    window.setFramerateLimit(60);

    //Cargamos una fuente a nuestro en sfml
    sf::Font font;
    font.loadFromFile("pixel.ttf");
    sf::Text text, textVidas;
    text.setFont(font);
    textVidas.setFont(font);
    textVidas.setPosition({ 0, 50 });
    //creando objeto personaje
    Personaje n1;
    //creando objeto item anillo
    Item item;
    //Creamos el objeto power la esmeralda
    Power power;
    //Posicionando a item en un lugar aleatorio
    item.respawn();
    power.respawn();
    int timer = 60 * 5; //temporizador para que cada 5 segundos aparesca un objeto Power
    Enemy enemy;
    enemy.respawn();


    //Proyectil bala;



    //Variable para sumar puntos del personaje 
    int puntos = 0;
    int vidas = 3;

    sf::Sprite image_1;
    sf:Texture text_1;

    text_1.loadFromFile("fondo.jpg");
    image_1.setTexture(text_1);



    sf::SoundBuffer buffer;
    buffer.loadFromFile("siu.wav");

    sf::Sound sound;
    sound.setBuffer(buffer);

    sf::SoundBuffer sound_power;
    sound_power.loadFromFile("life.wav");

    sf::Sound power_s;
    power_s.setBuffer(sound_power);

    //gAME LOOP
    while (window.isOpen())
    {

        //read input (actualizar los estados de prerifericos de entrada)
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (vidas > 0)
        {

            enemy.update();

            if (timer > 0)
            {
                timer--;
            }
            //update actualiza los estados del juego
            n1.update();
            //bala.update(n1.obtener_pos(), n1.obtener_mouse());

            //Detectamos si el personaje colisiona con el item, si el personaje colisiona 
            //hace un respawn(reaparece en otro lugar el item(moneda))



            //colisiones
            if (n1.isCollisionable(item))
            {
                item.respawn();
                puntos++;
                //sound.setPitch(.5f + (std::rand() % 5 / 5.f));
                sound.play();
            }

            if (timer == 0 && n1.isCollisionable(power))
            {
                n1.agregarVelocidad(1);
                timer = 60 * 5;
                power.respawn();
                power_s.play();
            }
            if (n1.isCollisionable(enemy)) {
                n1.hited();
                enemy.youDamaged();
                vidas--;
                enemy.respawn();
            }
        }

        text.setString(std::to_string(puntos));
        textVidas.setString("Vidas: " + std::to_string(vidas));

        //limpiar la pantalla
        window.clear();

       

        //dibujar el fondo 
        window.draw(image_1);
        //le pasamos el objeto n1 al window de manera que este ya sabe como dibujarlo porque lo definimos en la clase
        window.draw(n1);

        //dibujar proyectil
        //window.draw(bala);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) ){
            //bala.respawn(n1.obtener_pos());
            //window.draw(bala);

        }

        //le pasamos el objeto item a window para que este dibuje porque lo definimos en la clase item
        window.draw(item);

        //Dibujamos la fuente en el juego 
        window.draw(text);
        window.draw(textVidas);
        window.draw(enemy);
        if (timer == 0)
        {
            window.draw(power);
        }

        window.display();
    }

    //LIiberacion del juego

    return 0;
}
