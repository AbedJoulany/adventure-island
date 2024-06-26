#pragma once

//---------------------------------------------------------------------------------------------------------------------

#include "BonusFire.h"
#include <iostream>
#include "Sound.h"


//---------------------------------------------------------------------------------------------------------------------



BonusFire::BonusFire(const sf::Vector2f position, const std::shared_ptr<Board>& board) :
    Bonus(position, board, "R", WEAPONFIREPATH)
{
    m_bonusValue = 0;
}


//---------------------------------------------------------------------------------------------------------------------



std::string BonusFire::name()
{
    return "BonusFire";
}


//---------------------------------------------------------------------------------------------------------------------