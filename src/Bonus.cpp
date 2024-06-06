#pragma once

//---------------------------------------------------------------------------------------------------------------------

#include "Bonus.h"
#include <iostream>
#include "Sound.h"


//---------------------------------------------------------------------------------------------------------------------



Bonus::Bonus(const sf::Vector2f position, const std::shared_ptr<Board>& board, std::string id, std::string path) :
    IdleObject(position, board, id, path)
{
}


//---------------------------------------------------------------------------------------------------------------------



void Bonus::setTaken()
{
    m_GotBonus = true;
}


//---------------------------------------------------------------------------------------------------------------------



bool Bonus::isTaken()
{
    return m_GotBonus;
}


//---------------------------------------------------------------------------------------------------------------------



void Bonus::update()
{
    getSprite().update(ZERO, ZERO);
}

int Bonus::getBonusValue()
{
    return m_bonusValue;
}


//---------------------------------------------------------------------------------------------------------------------