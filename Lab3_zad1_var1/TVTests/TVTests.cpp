// TVTests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../TV/TVSet.h"

struct TVSetFixture
{
	CTVSet tv;
};

/*
Телевизор
	- изначально выключен
	- может быть включен
	- может быть выключен
	- в выключенном состоянии должен быть на 0 канале
	- при первом включении телевизор включается на первом канале
	- позволяет выбрать с 1 по 99 канал во включенном состоянии
	*/


BOOST_FIXTURE_TEST_SUITE(TVSet, TVSetFixture)

BOOST_AUTO_TEST_CASE(TurnedOffByDefault)
{
	BOOST_CHECK(!tv.IsTurnedOn());
}

BOOST_AUTO_TEST_CASE(CanBeTurnedOn)
{
	BOOST_CHECK(tv.TurnOn());
	BOOST_CHECK(tv.IsTurnedOn());
}

BOOST_AUTO_TEST_CASE(CanBeTurnedOff)
{
	tv.TurnOn();
	BOOST_CHECK(tv.TurnOff());
	BOOST_CHECK(!tv.IsTurnedOn());
}

BOOST_AUTO_TEST_CASE(IsAtChannel0WhenTurnedOff)
{
	BOOST_CHECK_EQUAL(tv.GetChannel(), 0);
	tv.TurnOn();
	tv.TurnOff();
	BOOST_CHECK_EQUAL(tv.GetChannel(), 0);
}

BOOST_AUTO_TEST_CASE(ChooseChannelWhenTurnedOff)
{
	BOOST_CHECK_EQUAL(tv.GetChannel(), 0);
	tv.TurnOn();
	tv.TurnOff();
	tv.SelectChannel(1);
	BOOST_CHECK_EQUAL(tv.GetChannel(), 0);
}

BOOST_AUTO_TEST_CASE(InitiallyIsTurnedOnAtChannel1)
{
	tv.TurnOn();
	BOOST_CHECK_EQUAL(tv.GetChannel(), 1);
}

BOOST_AUTO_TEST_CASE(TvIsTurnedOn_On_BeforeChannel)
{
	tv.TurnOn();
	tv.SelectChannel(2);
	tv.TurnOff();
	tv.TurnOn();
	BOOST_CHECK_EQUAL(tv.GetChannel(), 2);
}

BOOST_AUTO_TEST_CASE(CanNotTurnOffTheTVIsTurnedOff)
{
	tv.TurnOff();
	tv.TurnOff();
	BOOST_CHECK(tv.TurnOff() == false);
}

BOOST_AUTO_TEST_CASE(CanNotTurnOnTheTVIsTurnedOn)
{
	tv.TurnOn();
	tv.TurnOn();
	BOOST_CHECK(tv.TurnOn() == false);
}


BOOST_AUTO_TEST_CASE(CanSelectChannelFrom1To99WhenIsOn)
{
	tv.TurnOn();

	BOOST_CHECK(!tv.SelectChannel(0));
	BOOST_CHECK_EQUAL(tv.GetChannel(), 1);

	BOOST_CHECK(tv.SelectChannel(99));
	BOOST_CHECK_EQUAL(tv.GetChannel(), 99);

	BOOST_CHECK(!tv.SelectChannel(100));
	BOOST_CHECK_EQUAL(tv.GetChannel(), 99);

	BOOST_CHECK(tv.SelectChannel(1));
	BOOST_CHECK_EQUAL(tv.GetChannel(), 1);
}


BOOST_AUTO_TEST_SUITE_END()