#pragma once
#include "MovingObject.h"
#include "ResourceHolder.h"
#include "Board.h"
#include "AnimatedSprite.h"
#include "Sound.h"
#include <SFML\Audio\Music.hpp>

class Weapon : public MovingObject{

public:
    Weapon(const sf::Vector2f position, const Direction& direction, const std::shared_ptr<Board>& board, const std::string id, std::string path);

    virtual void updatePosition(const float gravity = WEAPONGRAVITY) override;

    virtual void draw(sf::RenderWindow& window) override;

    virtual bool destroy() const;

    virtual void setDestroy(bool destroy = true);

    virtual sf::Sprite getSprite() const override;


private:
    bool m_isMoving;
    bool m_destroy = false;
    sf::Vector2f m_Position;
    Resource_Holder<sf::Texture, std::string> m_Textures;
    AnimatedSprite m_Sprite;

};