#pragma once

//---------------------------------------------------------------------------------------------------------------------

#include "Hero.h"
#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "ResourceHolder.h"
//#include "Board.h"


class Board;

//---------------------------------------------------------------------------------------------------------------------


Hero::Hero()
    :MovingObject(OBJECTWIDTH, PLAYERHEIGHT),
    m_Sprite(OBJECTWIDTH, PLAYERHEIGHT)
{
    setPosition(PLAYERFIRSTPOS);
    setMaxSpeed(PLAYERMAXSPEED);
    setMoveSpeed(PLAYERSPEED);
    setJumpSpeed(PLAYERJUMPSPEED);
    setStopSpeed(PLAYERSTOPSPEED);

    /* TRY TO LOAD THE PLAYER TEXTURE: THROW EXCEPTION IN CASE FAILURE */
    try
    {
         m_Textures.load(HEROID, HEROPATH);
         m_Fonts.load(FONTID, ARIAL);
    }
    catch (std::runtime_error& e)
    {
        std::cout << "Exception: " << e.what() << "\n";
    }
    m_Sprite.setTexture(m_Textures.get(HEROID));
}

//Hero::Hero(const std::shared_ptr<Board>& board) :
//    MovingObject(OBJECTWIDTH, PLAYERHEIGHT, board),
//    m_Sprite(OBJECTWIDTH, PLAYERHEIGHT)
//{
//    /* SET (MOVE, MAX, JUMP, STOP) SPEED FOR PLAYER */
//    setPosition(PLAYERFIRSTPOS);
//    setMaxSpeed(PLAYERMAXSPEED);
//    setMoveSpeed(PLAYERSPEED);
//    setJumpSpeed(PLAYERJUMPSPEED);
//    setStopSpeed(PLAYERSTOPSPEED);
//
//    /* TRY TO LOAD THE PLAYER TEXTURE: THROW EXCEPTION IN CASE FAILURE */
//    try
//    {
//       // m_Textures.load(HEROID, HEROPATH);
//       // m_Fonts.load(FONTID, ARIAL);
//    }
//    catch (std::runtime_error& e)
//    {
//        std::cout << "Exception: " << e.what() << "\n";
//    }
//   // m_Sprite.setTexture(m_Textures.get(HEROID));
//}


//---------------------------------------------------------------------------------------------------------------------


void Hero::jump()
{
    /* IN CASE NO JUMP: JUST IGNORE */
    if (!m_JumpKeyReleased)    return;

    /* UPDATE THE JUMP STATUS */
    m_JumpKeyReleased = false;

    /* IF STILL ON GROUND AND JUMP BUTTON IS PRESSED */
    if (onGround())
    {
        MovingObject::jump();
    }
}


//---------------------------------------------------------------------------------------------------------------------


void Hero::endJump()
{
    m_JumpKeyReleased = true;

    if (getVelocity().y < PLAYERJUMPSPEED / 2) setVerticalVelocity(PLAYERJUMPSPEED / 2);
}


//---------------------------------------------------------------------------------------------------------------------


void Hero::move(Direction dir)
{
    /* SET DIRECTION TO THE PLAYER THEN MOVE */
    setDirection(dir);
    MovingObject::move(dir);
}


//---------------------------------------------------------------------------------------------------------------------


void Hero::endWalk()
{
    m_HorisontalButtonHeld = false;
}


//---------------------------------------------------------------------------------------------------------------------


void Hero::updatePosition()
{
    /* IN CASE PLAYER IS NOT ON GROUND: PLAY MATCHING TEXTURE */
    if (!onGround())
        m_Sprite.set(3);

    else if (m_Sprite.getCurrentTexture() == 3)
        m_Sprite.set(ZERO);

    /* IN CASE PLAYER IS MOVING IN GROUND: PLAY RUNNING TEXTURE */
    else if (m_HorisontalButtonHeld)
        m_Sprite.update(ZERO, 2);

    /* ELSE: PLAY INITIAL TEXTURE */
    else
        m_Sprite.update(ZERO, ZERO);

    MovingObject::updatePosition();

    m_Sprite.setPosition(getPosition().x, getPosition().y);
}


//---------------------------------------------------------------------------------------------------------------------


void Hero::draw(Window& window)
{
    window.draw(m_Sprite);

}


//---------------------------------------------------------------------------------------------------------------------


sf::Sprite Hero::getSprite() const
{
    return m_Sprite;
}


//---------------------------------------------------------------------------------------------------------------------


void Hero::setLife(int vary)
{
    if (vary < ZERO)
        if (m_Lifes > 1)
        {
            sf::sleep(sf::seconds(3));
        }
    m_Lifes += vary;
}


//---------------------------------------------------------------------------------------------------------------------


int Hero::getLife() const
{
    return m_Lifes;
}


//---------------------------------------------------------------------------------------------------------------------


bool Hero::isAlive()
{
    return !(m_Lifes == ZERO);
}


//---------------------------------------------------------------------------------------------------------------------


void Hero::reset()
{
    MovingObject::reset();
    setPosition(PLAYERFIRSTPOS);
    m_Lifes = 3;
}


//---------------------------------------------------------------------------------------------------------------------


void Hero::kill()
{
    setLife(-1);
    setPosition(PLAYERFIRSTPOS);
    setVelocity({ ZERO,ZERO });
    if (getLife() == ZERO)
        MovingObject::kill();
}


//---------------------------------------------------------------------------------------------------------------------


void Hero::setDirection(Direction new_dir)
{
    /* UPDATE HORIZONAL BUTTON */
    m_HorisontalButtonHeld = true;

    /* IN CASE NEW DIRECTION IS PRESSED: FLIP AND MOVE */
    if (getDirection() != new_dir)
    {
        m_Sprite.flip();
        MovingObject::setDirection(new_dir);
    }
}


//---------------------------------------------------------------------------------------------------------------------
