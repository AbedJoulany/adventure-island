#include "WeaponAxe.h""

WeaponAxe::WeaponAxe(const sf::Vector2f position, const Direction& direction, const std::shared_ptr<Board>& board)
	:Weapon(position, direction, board, WEAPONAXEID, WEAPONAXEPATH)
{
}
