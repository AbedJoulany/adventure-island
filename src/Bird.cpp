#pragma once

//---------------------------------------------------------------------------------------------------------------------

#include "Bird.h"

//---------------------------------------------------------------------------------------------------------------------


Bird::Bird(const sf::Vector2f position, const std::shared_ptr<Board>& board):
	Enemy(position , board , "bird" ,BIRDPATH,0,1,true)
{
}


//---------------------------------------------------------------------------------------------------------------------