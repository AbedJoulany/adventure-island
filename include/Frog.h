#pragma once

//---------------------------------------------------------------------------------------------------------------------

#include "Enemy.h"
#include <SFML/Graphics.hpp>
#include <iostream>


//---------------------------------------------------------------------------------------------------------------------


class Frog : public Enemy
{
public:
	Frog(const sf::Vector2f position, const std::shared_ptr<Board>& board);
};