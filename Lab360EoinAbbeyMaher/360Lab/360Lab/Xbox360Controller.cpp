/// <summary>
/// @Author : Eoin Abbey-Maher
/// @Brief : Program to read controller inputs
/// 
/// Known Bugs: 
/// </summary>

#include "Xbox360Controller.h"

Xbox360Controller::Xbox360Controller()
{
	
}

Xbox360Controller::~Xbox360Controller()
{
}

bool Xbox360Controller::isConnected()
{
	for (int i = 0; i <= 8; i++)
	{
		if (sf::Joystick::isConnected(i))
		{
			sf_Joystick_Index = i;
			return true;

		}
		else
		{
			return false;	
		}
	}
	
}

bool Xbox360Controller::connect()
{
	if (isConnected())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Xbox360Controller::update()
{
	for (int i = 0; i < BUTTONS; i++)
	{
		m_textShown[i] = false;
	}
	m_previousState = m_currentState;
	buttonCheck();
}

void Xbox360Controller::buttonCheck()
{

	if (sf::Joystick::isButtonPressed(sf_Joystick_Index, 1)) //B
	{
		m_currentState.B = true;
		m_textShown[1] = true;
		if (m_previousState.B == false)
		{
			m_previousButton = "B";
		}
	}
	else
	{
		m_currentState.B = false;
	}

	if (sf::Joystick::isButtonPressed(sf_Joystick_Index, 0)) //A
	{
		m_currentState.A = true;
		m_textShown[0] = true;
		if (m_previousState.A == false)
		{
			m_previousButton = "A";
		}
	}
	else
	{
		m_currentState.A = false;
	}

	if (sf::Joystick::isButtonPressed(sf_Joystick_Index, 2)) //X
	{
		m_currentState.X = true;
		m_textShown[2] = true;
		if (m_previousState.X == false)
		{
			m_previousButton = "X";
		}
	}
	else
	{
		m_currentState.X = false;
	}

	if (sf::Joystick::isButtonPressed(sf_Joystick_Index, 3)) //Y
	{
		m_currentState.Y = true;
		m_textShown[3] = true;
		if (m_previousState.Y == false)
		{
			m_previousButton = "Y";
		}
	}
	else
	{
		m_currentState.Y = false;
	}

	if (sf::Joystick::isButtonPressed(sf_Joystick_Index, 5)) //RB
	{
		m_currentState.RB = true;
		m_textShown[4] = true;
	}
	else
	{
		m_currentState.RB = false;
	}

	if (sf::Joystick::isButtonPressed(sf_Joystick_Index, 4)) //LB
	{
		m_currentState.LB = true;
		m_textShown[5] = true;
	}
	else
	{
		m_currentState.LB = false;
	}

	if (sf::Joystick::isButtonPressed(sf_Joystick_Index, 8)) //left thumb click
	{
		m_currentState.LeftThumbStickClick = true;
		m_textShown[6] = true;
	}
	else
	{
		m_currentState.LeftThumbStickClick = false;
	}

	if (sf::Joystick::isButtonPressed(sf_Joystick_Index, 9)) //right thumb click
	{
		m_currentState.RightThumbStickClick = true;
		m_textShown[7] = true;
	}
	else
	{
		m_currentState.RightThumbStickClick = false;
	}

	if (sf::Joystick::getAxisPosition(sf_Joystick_Index, sf::Joystick::Axis::PovX) > dpadTreshold) //dpad Right
	{
		m_currentState.DpadRight = true;
		m_textShown[8] = true;

	}
	else
	{
		m_currentState.DpadRight = false;
	}

	if (sf::Joystick::getAxisPosition(sf_Joystick_Index, sf::Joystick::Axis::PovX) < (dpadTreshold * -1 )) //dpad Left
	{
		m_currentState.DpadLeft = true;
		m_textShown[9] = true;
	}
	else
	{
		m_currentState.DpadLeft = false;
	}

	if (sf::Joystick::getAxisPosition(sf_Joystick_Index, sf::Joystick::Axis::PovY) > (dpadTreshold)) //dpad Up
	{
		m_currentState.DpadUp = true;
		m_textShown[10] = true;
	}
	else
	{
		m_currentState.DpadUp = false;
	}

	if (sf::Joystick::getAxisPosition(sf_Joystick_Index, sf::Joystick::Axis::PovY) < (dpadTreshold * -1)) // dpad Down
	{
		m_currentState.DpadDown = true;
		m_textShown[11] = true;
	}
	else
	{
		m_currentState.DpadDown = false;
	}

	if (sf::Joystick::getAxisPosition(sf_Joystick_Index, sf::Joystick::Axis::Z) > dpadTreshold) //Left Trigger
	{
		m_currentState.LTrigger = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Z);
		m_textShown[12] = true;
	}
	else
	{
		m_currentState.LTrigger = false;
	}

	if (sf::Joystick::getAxisPosition(sf_Joystick_Index, sf::Joystick::Axis::Z) < (dpadTreshold *-1)) //Right Trigger
	{
		m_currentState.RTrigger = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Z);
		
		m_textShown[13] = true;
	}
	else
	{
		m_currentState.RTrigger = false;	
	}

	if (sf::Joystick::getAxisPosition(sf_Joystick_Index, sf::Joystick::Axis::U) > dpadTreshold || sf::Joystick::getAxisPosition(sf_Joystick_Index, sf::Joystick::Axis::U) < (dpadTreshold * -1)
		|| sf::Joystick::getAxisPosition(sf_Joystick_Index,sf::Joystick::Axis::R) > dpadTreshold || sf::Joystick::getAxisPosition(sf_Joystick_Index,sf::Joystick::Axis::R) < (dpadTreshold * -1)) //Right Thumb Stick move
	{
		m_currentState.RightThumbStick.x = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::U);
		m_currentState.RightThumbStick.y = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::R);
		m_textShown[14] = true;
	}
	else
	{
		m_currentState.RightThumbStick = (sf::Vector2f(0, 0));
		m_textShown[14] = false;
	}

	if (sf::Joystick::getAxisPosition(sf_Joystick_Index, sf::Joystick::Axis::X) > dpadTreshold || sf::Joystick::getAxisPosition(sf_Joystick_Index,sf::Joystick::Axis::X) < (dpadTreshold * -1)
		|| sf::Joystick::getAxisPosition(sf_Joystick_Index,sf::Joystick::Axis::Y ) > dpadTreshold || sf::Joystick::getAxisPosition(sf_Joystick_Index,sf::Joystick::Axis::Y) < (dpadTreshold * -1)) //Left Thumb stick move
	{
		m_currentState.LeftThumbStick.x = sf::Joystick::getAxisPosition(sf_Joystick_Index, sf::Joystick::Axis::X);
		m_currentState.LeftThumbStick.y = sf::Joystick::getAxisPosition(sf_Joystick_Index, sf::Joystick::Axis::Y);
		m_textShown[15] = true;
	}
	else
	{
		m_currentState.LeftThumbStick = (sf::Vector2f(0, 0));
		m_textShown[15] = false;
	}

}

