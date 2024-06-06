#pragma once

//---------------------------------------------------------------------------------------------------------------------

#include "BonusSkateBoard.h"
#include <iostream>
#include "Sound.h"


//---------------------------------------------------------------------------------------------------------------------



BonusSkateBoard::BonusSkateBoard(const sf::Vector2f position, const std::shared_ptr<Board>& board) :
    Bonus(position, board, "S", BONUSSKATEBOARDPATH)
{
    m_bonusValue = 0;
}


//---------------------------------------------------------------------------------------------------------------------



std::string BonusSkateBoard::name()
{
    return "BonusSkateBoard";
}


//---------------------------------------------------------------------------------------------------------------------