#pragma once

//---------------------------------------------------------------------------------------------------------------------

#include <string>
#include "Sprite.h"
#include "ResourceHolder.h"
#include "Utils.h"


//---------------------------------------------------------------------------------------------------------------------


class Block
{
public:

    enum Type   //Different types of NotMovingObjects, the order corresponds to its place in the texture file
    {
        /* OTHER */
        Stone,

        /* GRASS */
        Grass_Top,
        Grass_Left_Corner,
        Grass_Left,
        Dirt,
        Grass_Right,
        Grass_Right_Corner,

        /* CLOUD */
        Cloud_Bottom_Left,
        Cloud_Bottom_Right,
        Cloud_Top_Left,
        Cloud_Top_Right,

        Empty,
    };

    Block(Type type, const int x, const int y); //Construct a NotMovingObject with a given type and at a given coordinate

    void draw(sf::RenderWindow& window);    //Draw a NotMovingObject on a given window


private:
    Resource_Holder<sf::Texture, Type> m_Textures;

    Sprite m_Sprite;
};