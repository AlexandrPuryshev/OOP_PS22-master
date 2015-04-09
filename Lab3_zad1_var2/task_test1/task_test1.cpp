// task_test1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../Lab3_zad2/Car.h"

/*
Автомобиль
-Двигатель:
..........................................................................................................
-- изначально выключен
-- может быть включен
-- может быть выключен
-- при выключенном двигателе переключиться можно только на нейтральную передачу
-- автомобиль после включения двигателя находится на нейтральной передаче в состоянии
покоя.
-- При включенном двигателе переключиться можно с любой передачи на любую
-- на задний ход можно переключиться только с нейтральной или первой передачи на нулевой
скорости;
-- с заднего хода можно переключиться на первую передачу только на нулевой скорости;
-- переключившись на заднем ходу на нейтральную передачу на ненулевой скорости, переключиться
на первую передачу можно только после остановки
-- Двигатель данного автомобиля может быть выключен только при нулевой скорости на нейтральной
передаче
..........................................................................................................
- Направление движения:
..........................................................................................................
-- вперед
-- назад
-- стоим
..........................................................................................................
- Скорость движения:
..........................................................................................................
--(Передача - скорость)
-- Задний ход 0 – 20 (-1)
-- Нейтраль Без ограничений  (0)
-- Первая 0 – 30  (1)
-- Вторая 20 – 50  (2)
-- Третья 30 – 60  (3)
-- Четвертая 40 – 90  (4)
-- Пятая 50 – 150  (5)
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

BOOST_AUTO_TEST_CASE(CanNotSetGearBackwardWhenGearIsGreat_1)
{
	car.TurnOnEngine();
	car.SetGear(3);
	car.SetSpeed(10);
	car.SetGear(-1);
	BOOST_CHECK(!car.SetGear(-1));
}

BOOST_AUTO_TEST_CASE(SetGearJustZeroWhenEngineTurnOff)
{
	car.TurnOnEngine();
	car.TurnOffEngine();
	BOOST_CHECK(!car.SetGear(2));
	BOOST_CHECK(!car.SetGear(-1));
	BOOST_CHECK(car.SetGear(0));
}

BOOST_AUTO_TEST_CASE(EngineTurnOffWhenSpeedIsZeroAndGearIsZero)
{
	car.TurnOnEngine();
	car.SetGear(2);
	car.SetSpeed(10);
	BOOST_CHECK(!car.TurnOffEngine());
	car.SetGear(0);
	car.SetSpeed(0);
	BOOST_CHECK(car.TurnOffEngine());
}

BOOST_AUTO_TEST_CASE(WithBacwardGearAfirstSwitchForTransmissionOfOnlyZeroSpeed)
{
	car.TurnOnEngine();
	car.SetGear(-1);
	car.SetSpeed(10);
	BOOST_CHECK(!car.SetGear(1));
	car.SetSpeed(0);
	BOOST_CHECK(car.SetGear(1));
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