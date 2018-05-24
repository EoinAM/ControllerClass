// author Peter Lowe

#include "Game.h"

#include <iostream>

Game::Game() :
	m_window{ sf::VideoMode{ 800, 600, 32 }, "SFML Game" },
	m_exitGame{false} //when true game will exit
{
	if (m_controller.connect())
	{
		std::cout << "controller Is Connected" << std::endl;
	}
	if (!m_font.loadFromFile("ASSETS\\FONTS\\Gameplay.ttf"))
	{
		std::cout << "Font not loaded" << std::endl;
	}

	setupSprite();
	setupFaceArray();
}


Game::~Game()
{
}


void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if ( sf::Event::Closed == event.type) // window message
		{
			m_window.close();
		}
		if (sf::Event::KeyPressed == event.type) //user key press
		{
			
		}
	}
}

void Game::update(sf::Time t_deltaTime)
{
	m_controller.update();
	if (m_exitGame)
	{
		m_window.close();
	}
	m_PreviousButton.setString("Previous Button Pressed: " + m_controller.m_previousButton);
	m_pressedFaceArray[12].setString(std::to_string(m_controller.m_currentState.LTrigger));
	m_pressedFaceArray[13].setString(std::to_string(m_controller.m_currentState.RTrigger));
	m_pressedFaceArray[14].setString(std::to_string(m_controller.m_currentState.RightThumbStick.x) + " , " + std::to_string(m_controller.m_currentState.RightThumbStick.y));
	m_pressedFaceArray[15].setString(std::to_string(m_controller.m_currentState.LeftThumbStick.x) + " , " + std::to_string(m_controller.m_currentState.LeftThumbStick.y));

}

void Game::render()
{
	m_window.clear(sf::Color::White);
	m_window.draw(m_controllerSprite);
	m_window.draw(m_PreviousButton);
	for (int i = 0; i < BUTTONS; i++)
	{
		if (m_controller.m_textShown[i] == true)
		{
			m_window.draw(m_pressedFaceArray[i]);
		}
	}
	m_window.display();
}


void Game::setupSprite()
{
	if (!m_controllerTexture.loadFromFile("ASSETS\\IMAGES\\Controller.jpg"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading logo" << std::endl;
	}
	m_controllerSprite.setTexture(m_controllerTexture);
	m_controllerSprite.setOrigin(450, 300);
	m_controllerSprite.setPosition(m_window.getSize().x * .5, m_window.getSize().y * .5);
	m_controllerSprite.setScale(.85, .85);
}

void Game::setupFaceArray()
{
	m_PreviousButton.setFont(m_font);
	m_PreviousButton.setFillColor(sf::Color::Black);
	m_PreviousButton.setPosition(50, 580);
	m_PreviousButton.setCharacterSize(15);

	for (int i = 0; i < BUTTONS; i++)
	{
		m_pressedFaceArray[i].setFont(m_font);
		m_pressedFaceArray[i].setString("Pressed");
		m_pressedFaceArray[i].setFillColor(sf::Color::Blue);
		m_pressedFaceArray[i].setCharacterSize(15);
	}

	m_pressedFaceArray[0].setPosition(660, 405); // A
	m_pressedFaceArray[1].setPosition(660, 355); // B
	m_pressedFaceArray[2].setPosition(660, 305); // X
	m_pressedFaceArray[3].setPosition(660, 255); // Y
	m_pressedFaceArray[4].setPosition(620, 160); // RB
	m_pressedFaceArray[5].setPosition(60, 160);  // LB
	m_pressedFaceArray[6].setPosition(20, 280);  // Left stick click
	m_pressedFaceArray[7].setPosition(460, 500); // Right Stick Click
	m_pressedFaceArray[8].setPosition(330, 490); //Dpad Right
	m_pressedFaceArray[9].setPosition(210, 490); //Dpad Left
	m_pressedFaceArray[10].setPosition(280, 450); //Dpad UP
	m_pressedFaceArray[11].setPosition(280, 530); //Dpad Down
	m_pressedFaceArray[12].setPosition(200, 80); //Left Trigger;
	m_pressedFaceArray[13].setPosition(500, 80); //Right Trigger ;
	m_pressedFaceArray[14].setPosition(460, 500); //Right Stick Coords
	m_pressedFaceArray[15].setPosition(10, 220); //Left Stick Coords

}
