#pragma once

//---------------------------------------------------------------------------------------------------------------------

#include "Frog.h"


//---------------------------------------------------------------------------------------------------------------------


Frog::Frog(const sf::Vector2f position, const std::shared_ptr<Board>& board) :
	Enemy(position, board, "frog", FROGPATH, ZERO, 1, true)
{
}


//---------------------------------------------------------------------------------------------------------------------
