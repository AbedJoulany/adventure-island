#pragma once

//---------------------------------------------------------------------------------------------------------------------

#include "MovingObject.h"
#include "AnimatedSprite.h"
#include "ResourceHolder.h"
#include "Utils.h"


//---------------------------------------------------------------------------------------------------------------------


class Hero : public MovingObject
{
public:

    /* PLAYER CONSTRUCTOR */
    Hero();
    //Hero(const std::shared_ptr<Board>& board);

    void jump() override;

    void endJump();

    /* MOVE PLAYER IN GIVING DIRECTION */
    void move(Direction dir) override;

    void endWalk();

    void updatePosition() override;

    void draw(Window& window) override;

    sf::Sprite getSprite() const override;

    virtual void setLife(int vary);

    int getLife()const;

    /* CHECK IF PLAYER IS ALIVE */
    bool isAlive();

    void reset();

    /* KILL PLAYER */
    void kill();

    //static Entity* __stdcall Create() { return new Hero(); }


private:
    void setDirection(Direction dir) override;


    //-----Variables and constants------------
    Resource_Holder<sf::Texture, std::string> m_Textures;

    Resource_Holder<sf::Font, std::string> m_Fonts;
    AnimatedSprite m_Sprite;

    int m_Lifes = PLAYERLIFE;

    bool m_HorisontalButtonHeld = false;

    bool m_JumpKeyReleased = true;
};