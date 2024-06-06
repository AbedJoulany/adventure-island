#pragma once

//---------------------------------------------------------------------------------------------------------------------

#include "BonusApple.h"
#include <iostream>
#include "Sound.h"


//---------------------------------------------------------------------------------------------------------------------



BonusApple::BonusApple(const sf::Vector2f position, const std::shared_ptr<Board>& board) :
    Bonus(position, board, "A", BONUSAPPLEPATH)
{
    m_bonusValue = 100;
}


//---------------------------------------------------------------------------------------------------------------------



std::string BonusApple::name()
{
    return "BonusApple";
}


//---------------------------------------------------------------------------------------------------------------------