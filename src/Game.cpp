#pragma once

//---------------------------------------------------------------------------------------------------------------------

#include "Game.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cmath>
#include "AudioController.h"
#include "Snail.h"
#include "Bird.h"
#include "Frog.h"
#include "BonusApple.h"
#include "BonusBanana.h"
#include "BonusPineApple.h"
#include "BonusTomato.h"
#include "BonusAxe.h"
#include "BonusFire.h"
#include "BonusSkateBoard.h"
#include "Trampoline.h"
#include "WeaponAxe.h"
#include "WeaponFire.h"
#include "Egg.h"



//---------------------------------------------------------------------------------------------------------------------


Game::Game(sf::RenderWindow& window) :
	m_Board(std::make_unique<Board>()),
	m_Player(std::make_unique<Player>(m_Board)),
	m_bonusSound(BONUSOUNDSPATH),
	m_GameOverSound(GAMEOVERSOUNDSPATH),
	m_VictorySound(VICTORYPATH),
	m_PauseSound(PAUSESOUNDSPATH),
	m_WinLevelSond(WINSOUNDSPATH),
	m_PowerUpSound(POWERUPSOUNDPATH)
{
	srand(ZERO);
	try {
		setMusic(MAINTHEMESOUNDSPATH);
		m_Fonts.load(FONTID, FONTSPATH);


	}
	catch (std::runtime_error& e)
	{
		std::cout << "Exception: " << e.what() << "\n";
	}
	loading(window);
	m_Board->loadMaps();
}


//---------------------------------------------------------------------------------------------------------------------


void Game::reset()
{
	m_Player->reset();
	m_Board->reset();
	m_Objects.clear();
	m_Enemies.clear();
	m_GameOver = false;
	m_GameWon = false;
	m_LevelFinished = false;
}


//---------------------------------------------------------------------------------------------------------------------


void Game::setObjects()
{
	m_Enemies.clear();
	m_Objects.clear();
	m_Player->setPosition(PLAYERFIRSTPOS);
	std::unordered_multimap<char, sf::Vector2f> objects;
	objects = m_Board->getObject();
	for (auto object : objects)
	{
		if (object.first == BIRDID)
			m_Enemies.emplace_back(std::make_unique<Bird>(object.second, m_Board));
		else if (object.first == FROGID)
			m_Enemies.emplace_back(std::make_unique<Frog>(object.second, m_Board));
		else if (object.first == SNAILID)
			m_Enemies.emplace_back(std::make_unique<Snail>(object.second, m_Board));
		else if (object.first == BONUSAPPLEID)
			m_Objects.emplace_back(std::make_unique<BonusApple>(object.second, m_Board));
		else if (object.first == BONUSPINEAPPLEID)
			m_Objects.emplace_back(std::make_unique<BonusPineApple>(object.second, m_Board));
		else if (object.first == BONUSBANANAID)
			m_Objects.emplace_back(std::make_unique<BonusBanana>(object.second, m_Board));
		else if (object.first == BONUSTOMATOID)
			m_Objects.emplace_back(std::make_unique<BonusTomato>(object.second, m_Board));
		else if (object.first == BONUSAXEID)
			m_Objects.emplace_back(std::make_unique<BonusAxe>(object.second, m_Board));
		else if (object.first == BONUSFIREID)
			m_Objects.emplace_back(std::make_unique<BonusFire>(object.second, m_Board));
		else if (object.first == EGGID)
			m_eggs.emplace_back(std::make_unique<Egg>(object.second, m_Board));
		else if (object.first == FIREWOODID)
			m_Enemies.emplace_back(std::make_unique<FireWood>(object.second, m_Board));
		else if (object.first == TRAMPOLINEID)
			m_Objects.emplace_back(std::make_unique<Trampoline>(object.second, m_Board));
	}
}


//---------------------------------------------------------------------------------------------------------------------


void Game::initializeView(sf::RenderWindow& window)
{
	m_View.setSize(window.getSize().x, window.getSize().y);
	m_View.zoom(0.328f);
	window.setView(m_View);
}


//---------------------------------------------------------------------------------------------------------------------


void Game::setMusic(std::string path)
{
	if (!m_ThemeMusic.openFromFile(path))
		throw std::runtime_error("Failed to load File " + path);
	m_ThemeMusic.setLoop(true);
	m_ThemeMusic.setVolume(25);
}


//---------------------------------------------------------------------------------------------------------------------


void Game::run(sf::RenderWindow& window)
{
	setObjects();
	initializeView(window);
	m_ThemeMusic.play();

	while (window.isOpen())
	{
		handleInputs(window);
		updateObjects(window);

		if (m_GameOver)
		{
			m_GameOverSound.play();
			displayGameOver(window);
			return;
		}

		if (m_LevelFinished)
		{
			m_LevelFinished = false;
			m_WinLevelSond.play();
			displayLevelWon(window);
			run(window);
			return;
		}

		if (m_GameWon)
		{
			m_Player->resetPowers();
			m_VictorySound.play();
			displayGameWon(window);
			return;
		}

		drawObjects(window);
		cleanupObjects();
	}
}


//---------------------------------------------------------------------------------------------------------------------


void Game::displayGameOver(sf::RenderWindow& window)
{
	window.setView(window.getDefaultView());
	sf::Text text;
	text = setText("GAME OVER", 70, sf::Color::White, window.getView().getCenter().x, window.getView().getCenter().y);

	m_ThemeMusic.pause();
	m_GameOverSound.play();

	sf::sleep(sf::seconds(1));

	window.clear(sf::Color::Black);
	window.draw(text);
	window.display();

	sf::sleep(sf::seconds(3));
}


//---------------------------------------------------------------------------------------------------------------------


void Game::displayGameWon(sf::RenderWindow& window)
{
	m_ThemeMusic.stop();
	m_VictorySound.play();
	sf::Text text;
	window.setView(window.getDefaultView());
	text = setText("VICTORY", 70, sf::Color::Black, window.getView().getCenter().x, window.getView().getCenter().y / 1.4f);


	auto toggleTextColor = [&text]()
	{
		if (text.getFillColor() == sf::Color::Black)     text.setFillColor(sf::Color::Yellow);
		else                                            text.setFillColor(sf::Color::Black);
	};

	while (m_VictorySound.getStatus() == sf::Music::Playing)
	{
		toggleTextColor();

		window.setView(window.getDefaultView());
		window.draw(text);
		window.setView(m_View);
		window.display();
		sf::sleep(sf::milliseconds(250));
	}
}


//---------------------------------------------------------------------------------------------------------------------


void Game::displayLevelWon(sf::RenderWindow& window)
{
	m_ThemeMusic.stop();
	m_VictorySound.play();
	sf::Text text;
	window.setView(window.getDefaultView());
	text = setText("Congrats, next level is coming", 50, sf::Color::Black, window.getView().getCenter().x, window.getView().getCenter().y / 1.4f);


	auto toggleTextColor = [&text]()
	{
		if (text.getFillColor() == sf::Color::Black)     text.setFillColor(sf::Color::Yellow);
		else                                            text.setFillColor(sf::Color::Black);
	};

	while (m_VictorySound.getStatus() == sf::Music::Playing)
	{
		toggleTextColor();

		window.setView(window.getDefaultView());
		window.draw(text);
		window.setView(m_View);
		window.display();
		sf::sleep(sf::milliseconds(150));
	}
}


//---------------------------------------------------------------------------------------------------------------------


void Game::pause(sf::RenderWindow& window)
{
	m_ThemeMusic.pause();
	m_PauseSound.play();
	sf::Text text;
	window.setView(window.getDefaultView());
	text = setText("PAUSED", 70, sf::Color::Black, window.getView().getCenter().x, window.getView().getCenter().y / 1.4f);
	window.draw(text);
	window.setView(m_View);

	window.display();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::P)
			{
				m_ThemeMusic.play();
				return;
			}
		}
	}
}


//---------------------------------------------------------------------------------------------------------------------


void Game::handleInputs(sf::RenderWindow& window)
{

	sf::Event event;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		m_Player->jump();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		m_Player->endWalk();
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		m_Player->move(Player::Right);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		m_Player->move(Player::Left);
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::KeyReleased:
			handleButtonEvents(event, window);
			break;
		default:
			break;
		}
	}
}


//---------------------------------------------------------------------------------------------------------------------


void Game::handleButtonEvents(sf::Event& event, sf::RenderWindow& window)
{
	switch (event.key.code)
	{
	case sf::Keyboard::Up:
		m_Player->endJump();
		break;
	case sf::Keyboard::Left:
	case sf::Keyboard::Right:
		m_Player->endWalk();
		break;
	case sf::Keyboard::Space:
		playerThrowWeapon();
		break;
	case sf::Keyboard::P:
		pause(window);
		break;
	case sf::Keyboard::M:
		Audio_Controller::toggleMute();
		break;
	case sf::Keyboard::B:
		Audio_Controller::decreaseVolume();
		break;
	case sf::Keyboard::N:
		Audio_Controller::increaseVolume();
		break;
	case sf::Keyboard::Escape:
		if (quit(event, window))
		{
			window.close();
		}
		break;
	default:
		break;
	}
}


//---------------------------------------------------------------------------------------------------------------------


void Game::updateObjects(sf::RenderWindow& window)
{
	m_Player->updatePosition();

	if (m_Board->reachedFinish(m_Player->getPosition().x))
	{
		m_Board->setLevel();
		if (m_Board->gameWon())
		{
			m_GameWon = true;
			return;
		}
		m_LevelFinished = true;
		return;

	}

	if (!m_Player->isAlive())
	{
		m_GameOver = true;
		return;
	}

	std::for_each(m_Enemies.begin(), m_Enemies.end(), [](std::unique_ptr<Enemy>& e)
		{
			if (dynamic_cast<Bird*>(e.get()))
			{
				e->updatePosition(0);
			}
			else {
				e->updatePosition();
			}
		});

	std::for_each(m_Objects.begin(), m_Objects.end(), [](std::unique_ptr<IdleObject>& o)
		{
			o->update();
		});
	std::for_each(m_Weapons.begin(), m_Weapons.end(), [&](std::unique_ptr<Weapon>& w)
		{
			w->updatePosition();
		});
	std::for_each(m_eggs.begin(), m_eggs.end(), [&](std::unique_ptr<Egg>& e)
		{
			e->updatePosition();
		});

	checkForCollision();

	const int viewHeight = 175;
	m_View.setCenter(sf::Vector2f(m_Player->getSprite().getPosition().x, viewHeight));

	if (m_View.getCenter().x < m_View.getSize().x / 2)
		m_View.setCenter(sf::Vector2f(m_View.getSize().x / 2, viewHeight));

	window.setView(m_View);
}


//---------------------------------------------------------------------------------------------------------------------


void Game::drawObjects(sf::RenderWindow& window)
{
	window.clear(sf::Color::Cyan);

	m_Board->draw(window);
	m_Player->draw(window);

	std::for_each(m_Enemies.begin(), m_Enemies.end(), [&](std::unique_ptr<Enemy>& e)
		{
			e->draw(window);
		});

	std::for_each(m_Objects.begin(), m_Objects.end(), [&](std::unique_ptr<IdleObject>& o)
		{
			o->draw(window);
		});
	std::for_each(m_Weapons.begin(), m_Weapons.end(), [&](std::unique_ptr<Weapon>& w)
		{
			w->draw(window);
		});
	std::for_each(m_eggs.begin(), m_eggs.end(), [&](std::unique_ptr<Egg>& e)
		{
			e->draw(window);
		});

	window.display();
}


//---------------------------------------------------------------------------------------------------------------------


void Game::checkForCollision()
{
	// player collision to enemy
	std::for_each(m_Enemies.begin(), m_Enemies.end(), [this](std::unique_ptr<Enemy>& e)
		{
			if (m_Player->getSprite().getGlobalBounds().intersects(e->getSprite().getGlobalBounds()))
			{

				if (m_Player->onSkate())
				{
					m_Player->destroySkate();
					m_Player->stomp();
					e->kill();
				}
				else
					m_Player->kill();

			}
		});
	// weapon collision to enemy
	std::for_each(m_Weapons.begin(), m_Weapons.end(), [this](std::unique_ptr<Weapon>& w)
		{
			std::for_each(m_Enemies.begin(), m_Enemies.end(), [this, &w](std::unique_ptr<Enemy>& e)
				{
					if (w->getSprite().getGlobalBounds().intersects(e->getSprite().getGlobalBounds()))
					{
						e->kill();
						w->setDestroy();
					}
				});

			std::for_each(m_eggs.begin(), m_eggs.end(), [this, &w](std::unique_ptr<Egg>& e)
				{
					if (w->getSprite().getGlobalBounds().intersects(e->getSprite().getGlobalBounds()))
					{
						if (e->isCracked())
						{
							e->destroy();
						}
						else {
							e->crack();
						}
						w->setDestroy();
					}
				});
		});

	std::for_each(m_eggs.begin(), m_eggs.end(), [this](std::unique_ptr<Egg>& e)
		{
			if (m_Player->getSprite().getGlobalBounds().intersects(e->getSprite().getGlobalBounds()))
			{
				e->push();
			}
		});

	std::for_each(m_Objects.begin(), m_Objects.end(), [this](std::unique_ptr<IdleObject>& o)
		{

			if (o->name() == "BonusApple" || o->name() == "BonusPineApple" ||
				o->name() == "BonusTomato" || o->name() == "BonusBanana")
			{
				if (m_Player->getSprite().getGlobalBounds().intersects(o->getSprite().getGlobalBounds()))
				{
					m_bonusSound.play();
					o->setTaken();
					m_Player->setScore(dynamic_cast<Bonus*>(o.get())->getBonusValue());
				}
			}
			else if (o->name() == "BonusAxe")
			{
				if (m_Player->getSprite().getGlobalBounds().intersects(o->getSprite().getGlobalBounds()))
				{
					m_bonusSound.play();
					o->setTaken();
					m_Player->setWeapon(Player::WeaponState::Axe);
				}
			}
			else if (o->name() == "BonusFire")
			{
				if (m_Player->getSprite().getGlobalBounds().intersects(o->getSprite().getGlobalBounds()))
				{
					m_bonusSound.play();
					o->setTaken();
					m_Player->setWeapon(Player::WeaponState::FireBall);
				}
			}
			else if (o->name() == "BonusSkateBoard")
			{
				if (m_Player->getSprite().getGlobalBounds().intersects(o->getSprite().getGlobalBounds()))
				{
					m_bonusSound.play();
					o->setTaken();
					m_Player->setSkate();
				}
			}
			else if (o->name() == "Trampoline")
			{
				sf::Rect Q = o->getSprite().getGlobalBounds();
				Q.top = o->getSprite().getGlobalBounds().top + 4;
				if (m_Player->getSprite().getGlobalBounds().intersects(Q))
				{
					m_Player->stompTrampoline();
				}
			}
		});
}


//---------------------------------------------------------------------------------------------------------------------


void Game::cleanupObjects()
{
	m_Enemies.erase(std::remove_if(m_Enemies.begin(), m_Enemies.end(), [](const std::unique_ptr<Enemy>& e)
		{
			return e->getLife() == ZERO;

		}), m_Enemies.end());

	m_Objects.erase(std::remove_if(m_Objects.begin(), m_Objects.end(), [](const std::unique_ptr<IdleObject>& o)
		{
			return o->isTaken();

		}), m_Objects.end());

	m_Weapons.erase(std::remove_if(m_Weapons.begin(), m_Weapons.end(), [this](const std::unique_ptr<Weapon>& w)
		{
			if (w->destroy())
				m_Player->weaponDestroy();
			return w->destroy();

		}), m_Weapons.end());

	m_eggs.erase(std::remove_if(m_eggs.begin(), m_eggs.end(), [&](const std::unique_ptr<Egg>& e)
		{
			if (e->isdestroyed())
			{
				if (e->getWeapon() == Player::WeaponState::Axe)
					m_Objects.emplace_back(std::make_unique<BonusAxe>(e->getPosition(), m_Board));
				else if (e->getWeapon() == Player::WeaponState::FireBall)
					m_Objects.emplace_back(std::make_unique<BonusFire>(e->getPosition(), m_Board));
				else if (e->getWeapon() == Player::WeaponState::SkateBoard)
					m_Objects.emplace_back(std::make_unique<BonusSkateBoard>(e->getPosition(), m_Board));
			}
			return e->isdestroyed();

		}), m_eggs.end());
}


//---------------------------------------------------------------------------------------------------------------------


bool Game::playerStompsEnemy(const std::unique_ptr<Enemy>& e)
{
	float slope = fabsf((e->getPosition().y - m_Player->getPosition().y) / (e->getPosition().y - m_Player->getPosition().y));

	return (slope >= 1) && m_Player->bottomBoundary() < e->bottomBoundary() && m_Player->getVelocity().y > 0;
}

void Game::playerThrowWeapon()
{
	if (!m_Player->weaponThrowAllowed())
		return;
	switch (m_Player->getWeapon())
	{
	case Player::WeaponState::none:
		return;
	case Player::WeaponState::Axe:
		m_Weapons.emplace_back(std::make_unique<WeaponAxe>(m_Player->getPosition(), m_Player->getDirection(), m_Board));
		break;
	case Player::WeaponState::FireBall:
		m_Weapons.emplace_back(std::make_unique<WeaponFire>(m_Player->getPosition(), m_Player->getDirection(), m_Board));
		break;
	}
	m_Player->weaponThrow();
}


//---------------------------------------------------------------------------------------------------------------------


void Game::loading(sf::RenderWindow& window)
{
	sf::Text loading;
	window.setView(window.getDefaultView());
	loading = setText("LOADING...", 100, sf::Color::White, window.getView().getCenter().x, window.getView().getCenter().y);
	window.clear(sf::Color::Black);
	window.draw(loading);
	window.display();
}


//---------------------------------------------------------------------------------------------------------------------


void Game::getBox()
{
	int boxContent = rand() % 2;
	switch (boxContent)
	{
	case 0:
		m_bonusSound.play();
		break;
	case 1:
		if (m_Player->getLife() < 4)
		{
			m_Player->setLife(1);
			m_PowerUpSound.play();
			break;
		}
		getBox();
		break;
	default:
		break;
	}
}


//---------------------------------------------------------------------------------------------------------------------


bool Game::quit(sf::Event eventt, sf::RenderWindow& window)
{
	sf::Text quitValidation;
	quitValidation = setText("           sure you wanna quit the game?\n(enter to validate/press any key to continue)", 30, sf::Color::White,
		window.getView().getCenter().x, window.getView().getCenter().y / 1.4f);
	m_ThemeMusic.pause();
	window.clear(sf::Color::Black);
	window.draw(quitValidation);
	window.display();
	sf::Event event;
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Enter:
					return true;
				default:
					m_ThemeMusic.play();
					return false;
				}
			default:
				break;
			}
		}
	}
}


//---------------------------------------------------------------------------------------------------------------------


sf::Text Game::setText(std::string str, int size, sf::Color color, float xPos, float yPos)
{
	sf::Text text(str, m_Fonts.get(FONTID));
	text.setCharacterSize(size);
	text.setFillColor(color);
	text.setOrigin(text.getGlobalBounds().width / float(2), text.getGlobalBounds().height / float(2));
	text.setPosition(xPos, yPos);
	return text;

}


//---------------------------------------------------------------------------------------------------------------------