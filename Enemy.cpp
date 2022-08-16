#include <stdLib.h>
#include "Enemy.h"
Enemy::Enemy()
{
    _texture.loadFromFile("Enemy.png");
    _sprite.setTexture(_texture);
    _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
    _risa.loadFromFile("jaja.wav");
    _canal.setBuffer(_risa);
}
void Enemy::update() {
    _timeRespawn--;
    if (_timeRespawn < 0) {
        _timeRespawn = 60 * 5;
        _newPosition = { std::rand() % 700 + _sprite.getGlobalBounds().width, std::rand() % 500 + _sprite.getGlobalBounds().height };
    }
    if (_newPosition.x > _sprite.getPosition().x) {
        _sprite.move(5, 0);
    }

    if (_newPosition.x < _sprite.getPosition().x) {
        _sprite.move(-5, 0);
    }

    if (_newPosition.y > _sprite.getPosition().y) {
        _sprite.move(0, 5);
    }

    if (_newPosition.y < _sprite.getPosition().y) {
        _sprite.move(0, -5);
    }
    if (std::abs(_newPosition.x - _sprite.getPosition().x) < 5) {
        _sprite.move(0, -5);
    }
}

void Enemy::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}

void Enemy::respawn()
{
    _sprite.setPosition(std::rand() % 700 + _sprite.getGlobalBounds().width, std::rand() % 500 + _sprite.getGlobalBounds().height);
    _timeRespawn = 60 * 5;
}
void Enemy::youDamaged() {
    respawn();
    _canal.play();
}
sf::FloatRect Enemy::getBounds() const
{
    return _sprite.getGlobalBounds();
}