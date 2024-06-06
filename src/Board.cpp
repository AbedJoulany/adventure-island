#pragma once

//---------------------------------------------------------------------------------------------------------------------

#include "Board.h"
#include <fstream>
#include <iostream>


//---------------------------------------------------------------------------------------------------------------------


Board::Board()
    :m_X(ZERO),m_Y(ZERO)
{
    m_File.open(LEVELSPATH);
    if (!m_File.is_open())
    {
        std::cerr << "Could not open the file" << std::endl;
    }
}


//---------------------------------------------------------------------------------------------------------------------

/* LOAD MAP: READ AND STORE ALL OBJECTS IN MAP */
void Board::loadMaps()
{
    m_Maps.clear();
    m_Objects.clear();
    int counter = ZERO;
    while (counter < m_Levels)
    {
        std::unordered_multimap<char, sf::Vector2f> objects;
        std::string inputString;
        std::vector<std::unique_ptr<Block>> map_row;
        std::vector<std::vector<std::unique_ptr<Block>>> Map;
        Map.clear();

        /* get map borders */
        while (inputString.empty() && !m_File.eof())
            getline(m_File, inputString);

        if (!m_File.eof())
        {
            /* get the X,Y borders */
            std::stringstream stream(inputString);
            stream >> m_X >> m_Y;
            for (int i = ZERO; i < m_X; i++)
            {
                getline(m_File, inputString);
                for (int j = ZERO; j < m_Y; j++)
                {
                    Block::Type type;

                    switch (inputString[j])
                    {
                    case FINISHLINEID:
                        m_FinishLines[counter] = j;
                        map_row.push_back(nullptr);
                        continue;
                    case BIRDID:
                        objects.insert({ BIRDID , sf::Vector2f(j, i) });
                        map_row.push_back(nullptr);
                        continue;
                    case FROGID:
                        objects.insert({ FROGID , sf::Vector2f(j, i) });
                        map_row.push_back(nullptr);
                        continue;
                    case 's':
                        objects.insert({ SNAILID , sf::Vector2f(j, i) });
                        map_row.push_back(nullptr);
                        continue;
                    case 'G':
                        objects.insert({ FIREWOODID , sf::Vector2f(j, i) });
                        map_row.push_back(nullptr);
                        continue;
                    case 'T':
                        objects.insert({ TRAMPOLINEID , sf::Vector2f(j, i) });
                        map_row.push_back(nullptr);
                        continue;
                    case BONUSAPPLEID:
                        objects.insert({ BONUSAPPLEID , sf::Vector2f(j, i) });
                        map_row.push_back(nullptr);
                        continue;
                    case BONUSPINEAPPLEID:
                        objects.insert({ BONUSPINEAPPLEID , sf::Vector2f(j, i) });
                        map_row.push_back(nullptr);
                        continue;
                    case BONUSTOMATOID:
                        objects.insert({ BONUSTOMATOID , sf::Vector2f(j, i) });
                        map_row.push_back(nullptr);
                        continue;
                    case BONUSBANANAID:
                        objects.insert({ BONUSBANANAID , sf::Vector2f(j, i) });
                        map_row.push_back(nullptr);
                        continue;
                    case BONUSFIREID:
                        objects.insert({ BONUSFIREID , sf::Vector2f(j, i) });
                        map_row.push_back(nullptr);
                        continue;
                    case BONUSAXEID:
                        objects.insert({ BONUSAXEID , sf::Vector2f(j, i) });
                        map_row.push_back(nullptr);
                        continue;
                    case BONUSSKATEBOARDID:
                        objects.insert({ BONUSSKATEBOARDID , sf::Vector2f(j, i) });
                        map_row.push_back(nullptr);
                        continue;
                    case EGGID:
                        objects.insert({ EGGID , sf::Vector2f(j, i) });
                        map_row.push_back(nullptr);
                        continue;
                    case WHITESPACEID:
                        map_row.push_back(nullptr);
                        continue;
                    case STONEID:           type = Block::Stone;
                        break;
                    case GRASSTOPID:        type = Block::Grass_Top;
                        break;
                    case GRASSLEFTCORNERID: type = Block::Grass_Left_Corner;
                        break;
                    case GRASSLEFTID:       type = Block::Grass_Left;
                        break;
                    case DIRTID:            type = Block::Dirt;
                        break;
                    case GRASSRIGHTID:      type = Block::Grass_Right;
                        break;
                    case GRASSRIGHTCORNER:  type = Block::Grass_Right_Corner;
                        break;
                    case BOTTOMLEFTCLOUD:   type = Block::Cloud_Bottom_Left;
                        break;
                    case BOTTOMRIGHTCLOUD:  type = Block::Cloud_Bottom_Right;
                        break;
                    case TOPLEFTCLOUD:      type = Block::Cloud_Top_Left;
                        break;
                    case TOPRIGHTCLOUD:     type = Block::Cloud_Top_Right;
                        break;
                    default:                type = Block::Empty;
                        break;
                    }

                    map_row.emplace_back(std::make_unique<Block>(type, j, i));

                }
                Map.push_back(std::move(map_row));
            }
            m_Maps.push_back(std::move(Map));
            m_Objects.push_back(std::move(objects));
        }
        counter++;
    }
}


//---------------------------------------------------------------------------------------------------------------------


std::unordered_multimap<char, sf::Vector2f> Board::getObject()
{
    return m_Objects[m_Level];
}


//---------------------------------------------------------------------------------------------------------------------


void Board::draw(sf::RenderWindow& window)
{
    std::for_each(m_Maps[m_Level].begin(), m_Maps[m_Level].end(), [&window](const std::vector<std::unique_ptr<Block>>& row)
        {
            std::for_each(row.begin(), row.end(), [&window](const std::unique_ptr<Block>& block)
                {
                    if (block)    block->draw(window);
                });
        });
}


//---------------------------------------------------------------------------------------------------------------------


int Board::leftBoundary() const
{
    return ZERO;
}


//---------------------------------------------------------------------------------------------------------------------


int Board::rightBoundary() const
{
    return m_Maps[m_Level][ZERO].size();
}


//---------------------------------------------------------------------------------------------------------------------


int Board::topBoundary() const
{
    return ZERO;
}


//---------------------------------------------------------------------------------------------------------------------


int Board::bottomBoundary() const
{
    return m_Maps[m_Level].size();
}


//---------------------------------------------------------------------------------------------------------------------


bool Board::isSolidBlock(const int x, const int y) const
{
    return m_Maps[m_Level][x][y] != nullptr;
}

bool Board::intersectsBlock(const sf::FloatRect& rect, const int x, const int y) const
{
    if (m_Maps[m_Level][x][y] != nullptr)
    {
       // rect.intersects(m_Maps[m_Level][x][y])
    }
    return false;
}


//---------------------------------------------------------------------------------------------------------------------


bool Board::reachedFinish(const int x) const
{
    return x > m_FinishLines.find(m_Level)->second;
}


//---------------------------------------------------------------------------------------------------------------------


void Board::setLevel()
{
    m_Level++;
}


//---------------------------------------------------------------------------------------------------------------------


bool Board::gameWon()
{
    return m_Level == m_Levels;
}


//---------------------------------------------------------------------------------------------------------------------


void Board::reset()
{
    m_Level = ZERO;
}


//---------------------------------------------------------------------------------------------------------------------
