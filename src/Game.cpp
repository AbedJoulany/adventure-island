#include "Game.h"

Game::Game(Window & window)
	: m_hero(std::make_unique<Hero>())
{
	//loading(window);
	//initializeView(window);
	window.setFramerateLimit(60); // 60 FPS cap.

}

Game::~Game()
{

}

void Game::run(Window& window)
{
	initializeView(window);
	HandleInput(window);
	Render(window);
	//sf::sleep(sf::seconds(0.2)); // Sleep for 0.2 seconds.
	RestartClock(); // Restarting our clock.
}

void Game::HandleInput(Window& window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		m_hero->jump();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		m_hero->endWalk();
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		m_hero->move(Hero::Right);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		m_hero->move(Hero::Left);
}

void Game::initializeView(Window& window)
{
	m_View.setSize(window.getSize().x, window.getSize().y);
	m_View.zoom(0.328f);
	window.setView(m_View);
}

void Game::loading(Window& window)
{
	sf::Text loading;
	window.setView(window.getDefaultView());
	//loading = setText("LOADING...", 100, sf::Color::White, window.getView().getCenter().x, window.getView().getCenter().y);
	window.clear(sf::Color::Black);
	window.draw(loading);
	window.display();
}

void Game::Update(Window& window,  GameState& state) {


	HandleInput(window);
	m_hero->updatePosition();

	if (auto event = sf::Event{}; window.pollEvent(event))
	{
		window.Update(event); // Update window events
		switch (event.type)
		{

		case sf::Event::KeyReleased:
			switch (event.key.code)
			{
			case sf::Keyboard::Up:
				m_hero->endJump();
				break;
			case sf::Keyboard::Left:
			case sf::Keyboard::Right:
				m_hero->endWalk();
				break;
			default:
				break;
			}
		}

	}
}

void Game::Render(Window& window)
{
	window.setBackground(LEVEL_1_BACKGROUND);
	m_hero->draw(window);
	// draw objects
}

sf::Time Game::GetElapsed()
{
	return m_elapsed;
}

void Game::RestartClock()
{
	m_elapsed += m_clock.restart();
}