#include "Egg.h"
#include <ctime>
#include <random>
#include <iostream>

Egg::Egg(const sf::Vector2f position, const std::shared_ptr<Board>& board)
	:MovingObject(2, OBJECTHEIGHT, board),
	m_Sprite(2, OBJECTHEIGHT),
	m_Position(position)
{
	setJumpSpeed(PLAYERJUMPSPEED);
	try
	{
		m_Textures.load("E", EGGPATH);
	}
	catch (std::runtime_error& e)
	{
		std::cout << "Exception: " << e.what() << "\n";
	}

	m_Sprite.setTexture(m_Textures.get("E"));
	m_Sprite.setPosition(position.x, position.y);
	MovingObject::setPosition(position);

	m_weapon = randWeapon();

}

sf::Sprite Egg::getSprite() const
{
	return m_Sprite;
}

bool Egg::isCracked() const
{
	return m_cracked;
}

void Egg::updatePosition(const float gravity)
{

	/* UPDATE LAST TEXTURE */
	if (isCracked())
	{
		m_Sprite.update(2, 2);
	}
	else {
		m_Sprite.update(ZERO, ZERO);
	}

	MovingObject::updatePosition(gravity);

	m_Sprite.setPosition(getPosition().x, getPosition().y);

	if (m_pushed && onGround())
		m_destroy = true;
}

void Egg::draw(sf::RenderWindow& window)
{
	window.draw(m_Sprite);
}

bool Egg::isdestroyed() const
{
	return m_destroy;
}

void Egg::destroy() 
{
	m_destroy = true;
}

void Egg::push()
{
	/* IF STILL ON GROUND AND JUMP BUTTON IS PRESSED */
	if (onGround())
	{
		MovingObject::jump();
		m_pushed = true;
	}
}

void Egg::crack()
{
	m_cracked = true;
}

Player::WeaponState Egg::getWeapon() const
{
	return m_weapon;
}

Player::WeaponState Egg::randWeapon()
{
	std::uniform_int_distribution<int> d(1, MAX_WEAPON);
	std::random_device rd1;

	return Player::WeaponState(d(rd1));
}
