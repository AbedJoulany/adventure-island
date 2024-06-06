#pragma once

//---------------------------------------------------------------------------------------------------------------------

#include "BonusBanana.h"
#include <iostream>
#include "Sound.h"


//---------------------------------------------------------------------------------------------------------------------



BonusBanana::BonusBanana(const sf::Vector2f position, const std::shared_ptr<Board>& board) :
    Bonus(position, board, "B", BONUSBANANAPATH)
{
    m_bonusValue = 200;
}


//---------------------------------------------------------------------------------------------------------------------



std::string BonusBanana::name()
{
    return "BonusBanana";
}


//---------------------------------------------------------------------------------------------------------------------