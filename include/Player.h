#pragma once

//---------------------------------------------------------------------------------------------------------------------

#include "MovingObject.h"
#include "AnimatedSprite.h"
#include "ResourceHolder.h"
#include "Utils.h"


//---------------------------------------------------------------------------------------------------------------------


class Player : public MovingObject
{
public:
    enum class WeaponState
    {
        none,
        Axe,
        FireBall,
        SkateBoard
    };
    /* PLAYER CONSTRUCTOR */
    Player(const std::shared_ptr<Board>& board);

    void jump() override;

    void endJump();

    /* MOVE PLAYER IN GIVING DIRECTION */
    void move(Direction dir) override;

    void endWalk();

    void updatePosition(const float gravity = GRAVITY) override;

    void draw(sf::RenderWindow& window) override;

    sf::Sprite getSprite() const override;

    sf::Vector2f getWeaponPosition();

    virtual void setLife(int vary);

    int getLife()const;

    void setScore(int score);

    int getScore()const;

    /* UPDATE STOMP WITH PLAYER */
    void stomp();

    /* UPDATE JUMP OF TRAMPOLINE */
    void stompTrampoline();

    /* CHECK IF PLAYER IS ALIVE */
    bool isAlive();

    void reset();
    void resetPowers();
    
    /* KILL PLAYER */
    void kill();

    void setSkate();
    bool onSkate() const;
    void destroySkate();
    void setWeapon(const WeaponState& state);
    void weaponThrow();
    void weaponDestroy();
    bool weaponThrowAllowed();
    WeaponState getWeapon() const;

private:
    void setDirection(Direction dir) override;


    //-----Variables and constants------------
    Resource_Holder<sf::Texture, std::string> m_Textures;

    Resource_Holder<sf::Font, std::string> m_Fonts;

    AnimatedSprite m_Sprite;
    Sound m_JumpSound;
    Sound m_DiedSound;
    Sound m_TrampolineSound;
 
    WeaponState m_weaponstate;
    sf::Clock m_weaponClock;
    int m_Lifes = PLAYERLIFE;
    int m_Score = ZERO;
    int m_weaponThrown = ZERO;
    bool m_onSkate = false;;
    bool m_HorisontalButtonHeld = false;
    bool m_JumpKeyReleased = true;



};