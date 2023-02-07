#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "SFML/Audio.hpp"
#include <unordered_map>
#include <memory>

#define ARIAL "arial.ttf"

class Resources
{
	//==================== public =============================================
public:
	//------------------------------ singleton --------------------------------
	static Resources& instance();
	//returns sprite ----------------------------------------------------------
	sf::Sprite get_img(const std::string& path);
	//returns icon ------------------------------------------------------------
	const sf::Uint8* get_icon(const std::string& path);
	//returns font ------------------------------------------------------------
	const sf::Font& get_font(const std::string& path);
	//returns sound -----------------------------------------------------------
	sf::Sound* getSound(const std::string& path);
	//returns sound buffer ----------------------------------------------------
	sf::SoundBuffer* getBuffer(const std::string& path);
	//returns music <no need for more than one music at the same time ---------
	sf::Music& getMusic(const std::string& path);
	//returns modified text according to passed arguments ---------------------
	sf::Text getTxt(const std::string& text,
		const int& positionX, const int& positionY,
		const std::string& fontPath = ARIAL,
		const bool& centerize = true,
		const sf::Color& color = sf::Color::White,
		const int& size = 30, const float& thickness = 5.f);
	//====================== private ==========================================
private:
	Resources();//-------constructor ------------------------------------------
	~Resources();//------destructor -------------------------------------------
	//unordered maps that saves all textures and sound buffers 
	//for restoring them every time another class asks for them and make
	//it easy to destroy them at once in destructor 
	std::unordered_map<std::string, std::unique_ptr<sf::Texture>> textures;
	std::unordered_map<std::string, std::unique_ptr<sf::SoundBuffer>> sound_buffers;
	std::unordered_map<std::string, std::unique_ptr<sf::Sound>> sounds;
	sf::Sound sound;
	std::unordered_map<std::string, std::unique_ptr<sf::Text>> texts;
	//music
	sf::Music music;
	//font
	sf::Font font;

};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------