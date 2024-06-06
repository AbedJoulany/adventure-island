#pragma once
#include "Weapon.h"

class WeaponAxe : public Weapon {

public:
	WeaponAxe(const sf::Vector2f position, const Direction& direction, const std::shared_ptr<Board>& board);


};