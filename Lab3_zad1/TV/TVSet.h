#pragma once


class CTVSet
{
public:
	CTVSet();
	~CTVSet();
	bool IsTurnedOn() const;
	bool TurnOn();
	/*Выключает телевизор
	возвращает true, если 
	телевизор был включен*/
	bool TurnOff();
	int GetChannel() const;
	bool SelectChannel(int channel);
	void Info() const;
private:
	bool m_isTurnedOn;
	int m_channel;
};

