#pragma once
#include "Weapon.h"

class WeaponFire : public Weapon {

public:
	WeaponFire(const sf::Vector2f position, const Direction& direction, const std::shared_ptr<Board>& board);

};