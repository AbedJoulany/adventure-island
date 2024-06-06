#include "Weapon.h"

Weapon::Weapon(const sf::Vector2f position, const Direction& direction, const std::shared_ptr<Board>& board, const std::string id, std::string path)
	:MovingObject(OBJECTWIDTH, OBJECTHEIGHT, board),
	m_Sprite(OBJECTWIDTH, OBJECTHEIGHT),
	m_Position(position),
	m_isMoving(true)
{
	try
	{
		m_Textures.load(id, path);
	}
	catch (std::runtime_error& e)
	{
		std::cout << "Exception: " << e.what() << "\n";
	}
	m_Sprite.setTexture(m_Textures.get(id));
	m_Sprite.setPosition(position.x, position.y);
	MovingObject::setPosition(position);
	MovingObject::setDirection(direction);
}

void Weapon::updatePosition(const float gravity)
{
	if (m_isMoving)
	{
		/* UPDATE LAST TEXTURE */
		m_Sprite.update(ZERO, 3);

		setHorisontalVelocity(WEAPONSPEED * getDirection());

		MovingObject::updatePosition(gravity);
		if (onGround() || getVelocity().x == ZERO)
			m_destroy = true;

		m_Sprite.setPosition(getPosition().x, getPosition().y);
		return;
	}
	m_Sprite.setPosition(getPosition().x, getPosition().y);
	m_Sprite.update(ZERO, 3);
}

void Weapon::draw(sf::RenderWindow& window)
{
	window.draw(m_Sprite);
}

bool Weapon::destroy() const
{
	return m_destroy;
}

void Weapon::setDestroy(bool destroy)
{
	m_destroy = destroy;
}

sf::Sprite Weapon::getSprite() const
{
	return m_Sprite;
}
