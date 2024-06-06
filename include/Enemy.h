#pragma once

//---------------------------------------------------------------------------------------------------------------------


#include "MovingObject.h"
#include "ResourceHolder.h"
#include "Board.h"


//---------------------------------------------------------------------------------------------------------------------


class Enemy : public MovingObject
{
public:

    /* ENEMY CONSTRUCTOR */
    Enemy(const sf::Vector2f position, const std::shared_ptr<Board>& board, const std::string, const std::string,
        int first, int last,bool moving);

    virtual void updatePosition(const float gravity = GRAVITY) override;

    virtual void draw(sf::RenderWindow& window) override;

    sf::Sprite getSprite() const override;

    /* KILL ENEMY */
    virtual void kill();

    /* SETS ENEMY'S LIFE */
    virtual void setLife(int vary)override;

    /* RETURN THE ENEMY'S LIFE */
    virtual int getLife()const;

    /* CHECK IF ENEMY IS MOVING TYPE ENEMY */
    virtual bool getMoving()const;

private:
    /* FLIP ENEMY DIRECTION */
    void flip();
    int m_Life = ENEMYLIFE;
    int m_first;
    int m_last;
    bool m_isMoving;
    Sound m_killed;
    Resource_Holder<sf::Texture, std::string> m_Textures;
    AnimatedSprite m_Sprite;
};