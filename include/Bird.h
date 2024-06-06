#pragma once

//---------------------------------------------------------------------------------------------------------------------

#include "Enemy.h"
#include <SFML/Graphics.hpp>
#include <iostream>


//---------------------------------------------------------------------------------------------------------------------


class Bird : public Enemy
{
public:
	Bird(const sf::Vector2f position, const std::shared_ptr<Board>& board);
};