#include "Menu.h"
#include "Resources.h"
#include "Utils.h"
Menu::Menu()
{
	m_selectedOption = 0;
	m_options.push_back("Play");
	m_options.push_back("New game");
	m_options.push_back("Quit");
}

Menu::~Menu()
{
}

void Menu::update(Window& window, GameState& state)
{
	if (auto event = sf::Event{}; window.pollEvent(event))
	{
		window.Update(event); // Update window events
		switch (event.type)
		{
		case sf::Event::KeyReleased:
			switch (event.key.code)
			{
			case sf::Keyboard::Enter:
				handleOption(window, state);
				break;
			}
			handleKeys(event.key);
			break;
		}
	}
}

void Menu::handleKeys(const sf::Event::KeyEvent& keyEvent)
{
	switch (keyEvent.code)
	{
	case sf::Keyboard::Up:
		--m_selectedOption;
		m_selectedOption = (abs(m_selectedOption) * m_options.size() + m_selectedOption) % m_options.size();
		break;
	case sf::Keyboard::Down:
		++m_selectedOption;
		m_selectedOption = (abs(m_selectedOption) * m_options.size() + m_selectedOption) % m_options.size();
		break;

	}
}

void Menu::handleOption(Window& window, GameState& state)
{
	switch (m_selectedOption)
	{
	case Play:
		play(state);
		break;
	case MenuOptions::NewGame:
		NewGame(state);
		break;
	case Quit:
		quit(window, state);
		break;
	}
}

void Menu::Render(Window& window)
{
	drawOnScreen(window);
}


void Menu::play(GameState& state)
{
	state = GameState::inGame;
}

void Menu::NewGame(GameState& state)
{
	state = GameState::NewGame;
}

void Menu::quit(Window& window, GameState& state)
{
	window.close();
	state = GameState::Play;
}
void Menu::drawOnScreen(Window& window)
{
	int j = 0;
	sf::Color m_color;
	for (auto& i : m_options) {
		auto txt = Resources::instance().getTxt(i, window.getSize().x / 2.f,
			(j + 1) * window.getSize().y / (2 * (m_options.size() + 1)) +
			((window.getSize().y / 2)) / 2,ROULLET , true);
		//-----------------
		j++;
	}j = 0;
	for (auto& i : m_options)
	{
		if (j == m_selectedOption)
			m_color = sf::Color::Blue;
		else
			m_color = sf::Color::White;
		window.draw(Resources::instance().getTxt(i, window.getSize().x / 2.f,
			(++j) * window.getSize().y / (2 * (m_options.size() + 1)) +
			(window.getSize().y - (window.getSize().y / 2)) / 2, ROULLET, true, m_color, 50, 8.0f));
	}
}