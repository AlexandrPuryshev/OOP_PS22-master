#pragma once

#define FORWARD   1
#define BACKWARD -1
#define STAY	  0

class CCar
{
public:
	CCar();
	~CCar();
	bool EngineIsTurnedOn()const;

	int GetSpeed() const;
	int GetGear() const;
	int GetDirection()const;
	void Info()const;

	bool TurnOnEngine();
	bool TurnOffEngine();

	bool SetGear(int gear);
	bool SetSpeed(int speed);
	bool RangeSpeedForGear(int speed, int minimalRange, int maximalRange);
private:
	bool CheckBackWardGear(int gear);
	int m_gear;
	int m_speed;
	int m_direction;
	bool m_EngineIsTurnedOn;
};

