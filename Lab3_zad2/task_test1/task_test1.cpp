// task_test1.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "../Lab3_zad2/Car.h"

/*
����������
-���������:
..........................................................................................................
-- ���������� ��������
-- ����� ���� �������
-- ����� ���� ��������
-- ��� ����������� ��������� ������������� ����� ������ �� ����������� ��������
-- ���������� ����� ��������� ��������� ��������� �� ����������� �������� � ���������
�����.
-- ��� ���������� ��������� ������������� ����� � ����� �������� �� �����
-- �� ������ ��� ����� ������������� ������ � ����������� ��� ������ �������� �� �������
��������;
-- � ������� ���� ����� ������������� �� ������ �������� ������ �� ������� ��������;
-- �������������� �� ������ ���� �� ����������� �������� �� ��������� ��������, �������������
�� ������ �������� ����� ������ ����� ���������
-- ��������� ������� ���������� ����� ���� �������� ������ ��� ������� �������� �� �����������
��������
..........................................................................................................
- ����������� ��������:
..........................................................................................................
-- ������
-- �����
-- �����
..........................................................................................................
- �������� ��������:
..........................................................................................................
--(�������� - ��������)
-- ������ ��� 0 � 20 (-1)
-- �������� ��� �����������  (0)
-- ������ 0 � 30  (1)
-- ������ 20 � 50  (2)
-- ������ 30 � 60  (3)
-- ��������� 40 � 90  (4)
-- ����� 50 � 150  (5)
min(0) - max(150)
..........................................................................................................
*/

struct CarFixture
{
	CCar car;
};

BOOST_FIXTURE_TEST_SUITE(Car, CarFixture)

BOOST_AUTO_TEST_CASE(EngineOffByDefault)
{
	BOOST_CHECK_EQUAL(car.EngineIsTurnedOn(), false);
}

BOOST_AUTO_TEST_CASE(EngineCanBeTurnedOn)
{
	BOOST_CHECK(car.TurnOnEngine());
	BOOST_CHECK(car.EngineIsTurnedOn());
}

BOOST_AUTO_TEST_CASE(EngineCanBeTurnedOff)
{
	car.TurnOnEngine();
	BOOST_CHECK(car.TurnOffEngine());
	BOOST_CHECK(!car.EngineIsTurnedOn());
}

BOOST_AUTO_TEST_CASE(CanNotEngineTurnOnWhenHeIsTurnedOn)
{
	car.TurnOnEngine();
	car.TurnOnEngine();
	BOOST_CHECK(car.TurnOnEngine() == false);
}

BOOST_AUTO_TEST_CASE(CanNotEngineTurnOffWhenHeIsTurnedOff)
{
	car.TurnOffEngine();
	car.TurnOffEngine();
	BOOST_CHECK(car.TurnOffEngine() == false);
}

BOOST_AUTO_TEST_CASE(UpperNumbersOfTransfers)
{
	car.TurnOnEngine();
	BOOST_CHECK_EQUAL(car.SetGear(-12), false);
	BOOST_CHECK_EQUAL(car.SetGear(10), false);
	BOOST_CHECK_EQUAL(car.SetGear(100), false);
	BOOST_CHECK_EQUAL(car.SetGear(6), false);
}	

BOOST_AUTO_TEST_CASE(ChooseSpeedCanNotUpperSelectedInGear_1)
{
	car.TurnOnEngine();
	car.SetGear(1);
	BOOST_CHECK(car.SetSpeed(-1) == false);
	BOOST_CHECK(car.SetSpeed(100) == false);
}

BOOST_AUTO_TEST_CASE(ChooseSpeedCanNotUpperSelectedInGear_2)
{
	car.TurnOnEngine();
	car.SetGear(2);
	BOOST_CHECK(car.SetSpeed(10) == false);
	BOOST_CHECK(car.SetSpeed(60) == false);
}

BOOST_AUTO_TEST_CASE(ChooseSpeedCanNotUpperSelectedInGear_3)
{
	car.TurnOnEngine();
	car.SetGear(3);
	BOOST_CHECK(car.SetSpeed(20) == false);
	BOOST_CHECK(car.SetSpeed(80) == false);
}


BOOST_AUTO_TEST_CASE(ChooseSpeedCanNotUpperSelectedInGear_4)
{
	car.TurnOnEngine();
	car.SetGear(4);
	BOOST_CHECK(car.SetSpeed(30) == false);
	BOOST_CHECK(car.SetSpeed(100) == false);
}

BOOST_AUTO_TEST_CASE(ChooseSpeedCanNotUpperSelectedInGear_5)
{
	car.TurnOnEngine();
	car.SetGear(5);
	BOOST_CHECK(car.SetSpeed(30) == false);
	BOOST_CHECK(car.SetSpeed(200) == false);
}

BOOST_AUTO_TEST_SUITE_END()