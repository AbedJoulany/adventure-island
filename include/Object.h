#pragma once
#include "Board.h"
#include "AnimatedSprite.h"
#include <string>
#include "ResourceHolder.h"
#include "Sound.h"
#include <SFML\Audio\Music.hpp>

class Object {

public:
    Object(const float& width, const float& height, const std::shared_ptr<Board>& board);

    virtual void draw(sf::RenderWindow& window) = 0;

protected:

    const std::shared_ptr<Board> m_Board;
    const float m_Height;
    const float m_Width;

private:


};