#pragma once
#include "SFML/Graphics.hpp"
#include "Collisionable.h"
#include "SFML/Audio.hpp"
class Enemy :public sf::Drawable, public Collisionable {
    sf::Sprite _sprite;
    sf::Texture _texture;
    int _timeRespawn;
    sf::Sound _canal;
    sf::SoundBuffer _risa;
    sf::Vector2f _newPosition;
public:
    Enemy();
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void respawn();
    void youDamaged();
    sf::FloatRect getBounds() const override;
};