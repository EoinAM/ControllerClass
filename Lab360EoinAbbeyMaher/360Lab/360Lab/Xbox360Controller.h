#ifndef XBOX360CONTROLLER
#define XBOX360CONTROLLER

#include <SFML\Graphics.hpp>
#include <iostream>

int const BUTTONS{ 19 };

struct GamePadState
{
	bool A;
	bool B;
	bool X;
	bool Y;
	bool LB;
	bool RB;
	bool LeftThumbStickClick;
	bool RightThumbStickClick;
	bool DpadUp;
	bool DpadDown;
	bool DpadLeft;
	bool DpadRight;
	bool Start;
	bool Back;
	bool Xbox;
	float RTrigger;
	float LTrigger;
	sf::Vector2f RightThumbStick;
	sf::Vector2f LeftThumbStick;
};

class Xbox360Controller
{
public:
	Xbox360Controller();
	~Xbox360Controller();

	int sf_Joystick_Index;

	GamePadState m_currentState;
	GamePadState m_previousState;
	std::string m_previousButton;
	bool isConnected();
	bool connect();

	bool m_textShown[BUTTONS];

	void Xbox360Controller::update();

	void buttonCheck();

private:
	const int dpadTreshold = 50;

};

#endif 

