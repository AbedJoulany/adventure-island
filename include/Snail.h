#pragma once

//---------------------------------------------------------------------------------------------------------------------

#include "Enemy.h"
#include <SFML/Graphics.hpp>
#include <iostream>


//---------------------------------------------------------------------------------------------------------------------


class Snail : public Enemy
{
public:
	Snail(const sf::Vector2f position, const std::shared_ptr<Board>& board);
};