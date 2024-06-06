#pragma once

//---------------------------------------------------------------------------------------------------------------------

#include "BonusAxe.h"
#include <iostream>
#include "Sound.h"


//---------------------------------------------------------------------------------------------------------------------



BonusAxe::BonusAxe(const sf::Vector2f position, const std::shared_ptr<Board>& board) :
    Bonus(position, board, "X", WEAPONAXEPATH)
{
    m_bonusValue = 0;
}


//---------------------------------------------------------------------------------------------------------------------



std::string BonusAxe::name()
{
    return "BonusAxe";
}


//---------------------------------------------------------------------------------------------------------------------