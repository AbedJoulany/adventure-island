#pragma once
#include "Window.h"
#include "Hero.h"
#include <memory>
#include <vector>
#include <string>
#include "GameState.h"

class Game {

public:
	Game(Window& window);
	~Game();

	void run(Window& window);
	void Update(Window& window,  GameState& state);
	void Render(Window& window);
	sf::Time GetElapsed();
	void RestartClock();
private:
	void HandleInput(Window& window);
	/* INITIALIZES THE GAME VIEW */
	void initializeView(Window& window);
	/* SET THE LOADING WINDOW BEFORE GAME STARTS */
	void loading(Window& window);

	sf::View m_View;
	std::unique_ptr<Hero> m_hero;


	sf::Clock m_clock;
	sf::Time m_elapsed;
};