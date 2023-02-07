#pragma once
#include <SFML/Graphics.hpp>

class Entity {

protected:
	sf::Vector2f pos;
	bool removable;

public:

	Entity(const int width, const int height);
	~Entity();

public:
	virtual void update(double dt) = 0;
	virtual void render(Graphics* gr) = 0;
	virtual Rectanglef bounds() const { return Rectanglef(); };
	virtual Rectanglef bounds(double px, double py) const { return Rectanglef(); };
	virtual void collides(Entity* e) {};

	/* SET & GET POSITION FOR MOVING OBJECT */
	sf::Vector2f getPosition() const;
	void setPosition(const sf::Vector2f position);

	bool isRemovable() const
	{
		return removable;
	}
	sf::Vector2f getPosition() const
	{
		return pos;
	}
	virtual Rectanglef getCollisionRectangle() const { return bounds(); }

};