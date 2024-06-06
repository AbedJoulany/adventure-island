#pragma once
#include "Weapon.h"
#include "ResourceHolder.h"
#include "Board.h"
#include "AnimatedSprite.h"
#include "Sound.h"
#include <SFML\Audio\Music.hpp>
#include "Player.h"

class Egg : public MovingObject {

public:
	Egg(const sf::Vector2f position, const std::shared_ptr<Board>& board);

	virtual void updatePosition(const float gravity = GRAVITY) override;

	virtual void draw(sf::RenderWindow& window) override;

	bool isdestroyed() const;
	void destroy();

	virtual sf::Sprite getSprite() const override;
	bool isCracked() const;
	void push();
	void crack();
	Player::WeaponState getWeapon() const;

private:

	Player::WeaponState randWeapon();

	bool m_pushed = false;
	bool m_destroy = false;
	bool m_cracked = false;
	Player::WeaponState m_weapon;

	sf::Vector2f m_Position;
	Resource_Holder<sf::Texture, std::string> m_Textures;
	AnimatedSprite m_Sprite;
};