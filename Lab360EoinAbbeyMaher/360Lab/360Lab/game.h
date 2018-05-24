//Author Eoin Abbey-Maher
#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>
#include "Xbox360Controller.h"



class Game
{
public:
	Game();
	~Game();
	void run();

private:

	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();
	
	void setupSprite();
	void setupFaceArray();

	sf::RenderWindow m_window; // main SFML window
	sf::Texture m_controllerTexture;
	sf::Sprite m_controllerSprite;
	sf::Font m_font;
	sf::Text m_pressedFaceArray[BUTTONS];

	sf::Text m_PreviousButton;

	bool m_exitGame; // control exiting game

	Xbox360Controller m_controller;

};

#endif // !GAME

