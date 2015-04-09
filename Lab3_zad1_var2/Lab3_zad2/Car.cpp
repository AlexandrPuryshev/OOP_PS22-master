#include "stdafx.h"
#include "Car.h"
#include <iostream>

using namespace std;

CCar::CCar() 
			:   m_speed(0),
				m_gear(0),
				m_EngineIsTurnedOn(false),
				m_direction(STAY)
{}


CCar::~CCar()
{}

bool CCar::TurnOnEngine()
{
	if (!EngineIsTurnedOn())
	{
		if (m_speed == 0 && m_gear == 0 && m_direction == STAY)
		{
			m_EngineIsTurnedOn = true;
			return m_EngineIsTurnedOn;
		}
	}
	return false;
}

bool CCar::TurnOffEngine()
{
	if (EngineIsTurnedOn())
	{
		if (m_speed == 0 && m_gear == 0 && m_direction == STAY)
		{
			m_EngineIsTurnedOn = false;
			return true;
		}
	}
	return false;
}

bool CCar::EngineIsTurnedOn()const
{
	return m_EngineIsTurnedOn;
}

int CCar::GetSpeed()const
{
	return m_speed;
}

int CCar::GetGear()const
{
	return m_gear;
}

int CCar::GetDirection()const
{
	return m_direction;
}

bool CCar::SetGear(int gear)
{
	bool backwardMet = false;
	if (-1 > gear || gear > 5)
	{
		return false;
	}
	if (EngineIsTurnedOn())
	{
			if (EngineIsTurnedOn())
			{
				switch (gear)
				{
					case -1:
					{
							   if ((m_gear == 0 || m_gear == 1) && m_speed == 0)
							   {
								   m_gear = gear; 
								   m_direction = BACKWARD;
								   return true;
								   backwardMet = true;
							   }
							   return false;
							   break;
					}
					case 1:
					{
							  if ((m_gear == -1 || m_gear == 0) && m_speed > 0 && m_direction == BACKWARD) //
							  {
								  return false;
							  }
							  m_gear = gear;
							  m_direction = FORWARD;
							  return true;
							  break;
					}
					case 0:
					{
						if (m_speed == 0)
						{
							m_direction = STAY;
						}
						m_gear = gear;
						return true;
					}
				}
				if (gear != -1)
				{
					m_gear = gear;
					return true;
				}
				else
				{
					return false;
				}
			}
		}
	else
	{
		if (gear == 0)
		{
			m_gear = gear;
			return true;
		}
		return false;
	}
}

void CCar::Info()const
{
	if (EngineIsTurnedOn())
	{
		cout << "Engine turn on!" << endl;
	}
	else
	{
		cout << "Engine is not turn on!" << endl;
	}
	switch (m_direction)
	{
		case -1:
		{
				cout << "direction is backward" << endl;
				break;
		}
		case 1:
		{
				cout << "direction is forward" << endl;
				break;
		}
		case 0:
		{
				cout << "direction is stay" << endl;
				break;
		}
	}
	cout << "speed = " << GetSpeed() << endl;
	cout << "gear = " << GetGear() << endl;
}

bool CCar::RangeSpeedForGear(int speed, int minimalRange, int maximalRange)
{
	if (speed >= minimalRange && speed <= maximalRange)
	{
		m_direction = FORWARD;
		m_speed = speed;
		return true;
	}
	return false;
}


bool CCar::SetSpeed(int speed)
{
	if ((speed >= 0 && speed <= 150) || EngineIsTurnedOn())
	switch (m_gear)
	{
		case -1:
		{
				   if (speed >= 0 && speed <= 20)
				   {
					   m_direction = BACKWARD;
					   m_speed = speed;
					   return true;
				   }
				   return false;
				   break;
		}
		case 0:
		{
				  if (speed < m_speed)
				  {
					  if (speed == 0)
					  {
						  m_direction = STAY;
					  }
					  m_speed = speed;
					  return true;
				  }
				  return false;
				  break;
		}
		case 1:
		{

				  if (RangeSpeedForGear(speed, 0, 30))
				  {
					  return true;
				  }
				  else
				  {
					  return false;
				  }
				  break;
		}
		case 2:
		{
				  if (RangeSpeedForGear(speed, 20, 50))
				  {
					  return true;
				  }
				  else
				  {
					  return false;
				  }
				  break;
		}
		case 3:
		{
				  if (RangeSpeedForGear(speed, 30, 60))
				  {
					  return true;
				  }
				  else
				  {
					  return false;
				  }
				  break;
		}
		case 4:
		{
				  if (RangeSpeedForGear(speed, 40, 90))
				  {
					  return true;
				  }
				  else
				  {
					  return false;
				  }
				  break;
		}
		case 5:
		{
				  if (RangeSpeedForGear(speed, 50, 150))
				  {
					  return true;
				  }
				  else
				  {
					  return false;
				  }
				  break;
		}
	}
	else
	{
		return false;
	}
}





