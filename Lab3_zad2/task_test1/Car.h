#pragma once

#define FORWARD   1
#define BACKWARD -1
#define STAY	  0

using namespace std;
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
private:
	int m_gear;
	int m_speed;
	int m_direction;
	bool m_EngineIsTurnedOn;
};