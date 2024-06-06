#pragma once

//---------------------------------------------------------------------------------------------------------------------

#include "AnimatedSprite.h"
#include "ResourceHolder.h"
#include "IdleObject.h"
#include "Enemy.h"
#include "Board.h"
#include "Sound.h"
#include <SFML\Audio\Music.hpp>


//---------------------------------------------------------------------------------------------------------------------


class FireWood : public Enemy
{
public:
    FireWood(const sf::Vector2f position, const std::shared_ptr<Board>& board);

};