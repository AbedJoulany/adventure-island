#pragma once

//---------------------------------------------------------------------------------------------------------------------

#include "AnimatedSprite.h"
#include "ResourceHolder.h"
#include "Board.h"
#include "IdleObject.h"
#include "Sound.h"
#include <SFML\Audio\Music.hpp>


//---------------------------------------------------------------------------------------------------------------------


class Bonus : public IdleObject
{
public:
    Bonus(const sf::Vector2f position, const std::shared_ptr<Board>& board, std::string id, std::string path);

    /* SET BONUS AS TAKEN*/
    virtual void setTaken()override;

    /* CHECK IF BONUS IS TAKEN ALREADY */
    virtual bool isTaken()override;

    /* UPDATE ANIMATION OF BONUS */
    virtual void update()override;

    virtual int getBonusValue();

private:
    bool m_GotBonus = false;

protected:
    int m_bonusValue;
};
