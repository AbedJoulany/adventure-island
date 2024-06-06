#pragma once

//---------------------------------------------------------------------------------------------------------------------

#include "Bonus.h"

//---------------------------------------------------------------------------------------------------------------------


class BonusPineApple : public Bonus
{
public:
    BonusPineApple(const sf::Vector2f position, const std::shared_ptr<Board>& board);

    /* RETURN THE TYPE NAME OF THE OBJECT */
    virtual std::string name()override;

};