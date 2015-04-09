#include "stdafx.h"
#include "TVSet.h"
#include <iostream>

using namespace std;

CTVSet::CTVSet() //�����������
	:m_isTurnedOn(false)
	,m_channel(1) // �� ������� �� 1 ������
{}
CTVSet::~CTVSet() //����������
{}

bool CTVSet::IsTurnedOn()const // ��������� �������?
{
	return m_isTurnedOn;
}

bool CTVSet::TurnOn() // �������� ���������
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
/*��������� ���������
���������� true, ����
��������� ��� �������*/
{
	if (IsTurnedOn())
	{
		m_isTurnedOn = false;
		return true;
	}
	else
		return false;
}

int CTVSet::GetChannel() const //���������� ����� ������
{
	if (m_isTurnedOn)
	{
		return m_channel;
	}
	return 0;
}

bool CTVSet::SelectChannel(int channel) //����� ������
{
	if ((channel > 0 && channel < 100) && (IsTurnedOn()))
	{
		m_channel = channel;
		return true;
	} // else
	return false;
}

void CTVSet::Info() const //������� ���������
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