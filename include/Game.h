#pragma once

//---------------------------------------------------------------------------------------------------------------------

#include "Board.h"
#include <vector>
#include <string>
#include "Player.h"
#include "Enemy.h"
#include "ResourceHolder.h"
#include "MainMenu.h"
#include "Utils.h"
#include "FireWood.h"
#include "Weapon.h"
#include <fstream>
#include "Egg.h"


//---------------------------------------------------------------------------------------------------------------------


//Holds the game and all its resources
class Game
{
public:

    /* GAME CONSTRUCTOR */
    Game(sf::RenderWindow& window);

    /* RESET GAME */
    void reset();

    /* SET THE TEXTS INSTRUCTIONS OF THE GAME */
    sf::Text setText(std::string, int size, sf::Color color, float xPos, float yPos);

    //! Start the game
    void run(sf::RenderWindow& window);

private:

    /* SET THE OBJECTS */
    void setObjects();

    /* INITIALIZES THE GAME VIEW */
    void initializeView(sf::RenderWindow& window);

    void setMusic(std::string path);

    void displayGameOver(sf::RenderWindow& window);

    void displayGameWon(sf::RenderWindow& window);

    void displayLevelWon(sf::RenderWindow& window);

    /* PAUSE THE GAME */
    void pause(sf::RenderWindow& window);

    void handleInputs(sf::RenderWindow& window);

    void handleButtonEvents(sf::Event& event, sf::RenderWindow& window);

    void updateObjects(sf::RenderWindow& window);

    void drawObjects(sf::RenderWindow& window);

    void checkForCollision();

    void cleanupObjects();

    bool playerStompsEnemy(const std::unique_ptr<Enemy>& e);

    void playerThrowWeapon();

    /* SET THE LOADING WINDOW BEFORE GAME STARTS */
    void loading(sf::RenderWindow& window);

    void getBox();

    /* QUIT THE GAME */
    bool quit(sf::Event event, sf::RenderWindow& window);

    bool m_GameOver = false;
    bool m_GameWon = false;
    bool m_LevelFinished = false;
    std::string m_PreviousMaxName;
    int m_PreviousMaxScore;
    sf::Clock clock;
    sf::View m_View;
    std::shared_ptr<Board> m_Board;
    std::unique_ptr<Player> m_Player;
    std::vector<std::unique_ptr<Enemy>> m_Enemies;
    std::vector<std::unique_ptr<IdleObject>> m_Objects;
    std::vector<std::unique_ptr<Weapon>> m_Weapons;
    std::vector<std::unique_ptr<Egg>> m_eggs;

    Resource_Holder<sf::Font, std::string> m_Fonts;
    sf::Music m_ThemeMusic;
    Sound m_bonusSound;
    Sound m_GameOverSound;
    Sound m_VictorySound;
    Sound m_WinLevelSond;
    Sound m_PauseSound;
    Sound m_PowerUpSound;
};