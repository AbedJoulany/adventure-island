#pragma once

//---------------------------------------------------------------------------------------------------------------------

#include "BonusPineApple.h"
#include <iostream>
#include "Sound.h"


//---------------------------------------------------------------------------------------------------------------------



BonusPineApple::BonusPineApple(const sf::Vector2f position, const std::shared_ptr<Board>& board) :
    Bonus(position, board, "P", BONUSPINEAPPLEPATH)
{
    m_bonusValue = 300;
}


//---------------------------------------------------------------------------------------------------------------------



std::string BonusPineApple::name()
{
    return "BonusPineApple";
}


//---------------------------------------------------------------------------------------------------------------------