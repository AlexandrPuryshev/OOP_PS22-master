#include "stdafx.h"
#include "TVSet.h"
#include <iostream>

using namespace std;

CTVSet::CTVSet() //конструктор
	:m_isTurnedOn(false)
	,m_channel(1) // по дефолту на 1 канале
{}
CTVSet::~CTVSet() //деструктор
{}

bool CTVSet::IsTurnedOn()const // телевизор включен?
{
	return m_isTurnedOn;
}

bool CTVSet::TurnOn() // включить телевизор
{
	if (!IsTurnedOn())
	{
		m_isTurnedOn = true;
		return m_isTurnedOn;
	}
	else
		return false;
}

bool CTVSet::TurnOff()
/*Выключает телевизор
возвращает true, если
телевизор был включен*/
{
	if (IsTurnedOn())
	{
		m_isTurnedOn = false;
		return true;
	}
	else
		return false;
}

int CTVSet::GetChannel() const //возвращает канал телика
{
	if (m_isTurnedOn)
	{
		return m_channel;
	}
	return 0;
}

bool CTVSet::SelectChannel(int channel) //выбор канала
{
	if ((channel > 0 && channel < 100) && (IsTurnedOn()))
	{
		m_channel = channel;
		return true;
	} // else
	return false;
}

void CTVSet::Info() const //текущее состояние
{
	if (IsTurnedOn())
	{
		cout << "TV is turned!" << endl;
	}
	else
	{
		cout << "TV is not turned!" << endl;
	}
	cout << "TV channel is: " << GetChannel() << endl;
}