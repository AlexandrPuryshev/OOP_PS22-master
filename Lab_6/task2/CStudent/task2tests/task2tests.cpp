// task2tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../CStudent/Student.h"

BOOST_AUTO_TEST_CASE(StudentHasNotIncorrectData)
{

	CStudent student("Vasin", "Ivanov", "Sergeeich", 15);
	BOOST_CHECK(true);

	{
		try
		{
			CStudent student("", "Ivanov", "Sergeeich", 15);
			BOOST_CHECK(false);
		}
		catch (std::invalid_argument)
		{
			BOOST_CHECK(true);
		}
	}

	{
		try
		{
			CStudent student("", "", "Sergeeich", 15);
			BOOST_CHECK(false);
		}
		catch (std::invalid_argument)
		{
			BOOST_CHECK(true);
		}
	}

	{
		try
		{
			CStudent student("", "", "", 15);
			BOOST_CHECK(false);
		}
		catch (std::invalid_argument)
		{
			BOOST_CHECK(true);
		}
	}

	{
		try
		{
			CStudent student("123", "Ivanov", "Sergeeich", 15);
			BOOST_CHECK(false);
		}
		catch (std::invalid_argument)
		{
			BOOST_CHECK(true);
		}
	}

	{
		try
		{
			CStudent student("4", "1", "656", 15);
			BOOST_CHECK(false);
		}
		catch (std::invalid_argument)
		{
			BOOST_CHECK(true);
		}
	}

	{
		try
		{
			CStudent student("123", "Ivanov", "Sergeeich", 15);
			BOOST_CHECK(false);
		}
		catch (std::invalid_argument)
		{
			BOOST_CHECK(true);
		}
	}

	{
		try
		{
			CStudent student("4s", "d1", "6a56", 15);
			BOOST_CHECK(false);
		}
		catch (std::invalid_argument)
		{
			BOOST_CHECK(true);
		}
	}


	BOOST_CHECK_THROW(CStudent("Vasin", "I v a n o v", "Sergeeich", 30),std::invalid_argument);

}

BOOST_AUTO_TEST_CASE(CheckRenameStudent)
{
	CStudent student = CStudent("Petr", "Petrov", "Petrovich", 34);
	BOOST_CHECK_THROW(student.Rename("I v a n", "Ivanov", "Ivanovich"), std::invalid_argument);
	BOOST_CHECK_EQUAL(student.GetName(), "Petr");
	BOOST_CHECK_EQUAL(student.GetSurname(), "Petrov");
	BOOST_CHECK_EQUAL(student.GetPatronymic(), "Petrovich");
	BOOST_CHECK_THROW(student.Rename("Ivan", "I v a n o v", "Ivanovich"), std::invalid_argument);
	BOOST_CHECK_EQUAL(student.GetName(), "Petr");
	BOOST_CHECK_EQUAL(student.GetSurname(), "Petrov");
	BOOST_CHECK_EQUAL(student.GetPatronymic(), "Petrovich");
	BOOST_CHECK_THROW(student.Rename("Ivan", "Ivanov", "I v a n ovich"), std::invalid_argument);
	BOOST_CHECK_EQUAL(student.GetName(), "Petr");
	BOOST_CHECK_EQUAL(student.GetSurname(), "Petrov");
	BOOST_CHECK_EQUAL(student.GetPatronymic(), "Petrovich");
}

BOOST_AUTO_TEST_CASE(CheckAgeStudent)
{
	{
		try
		{
			CStudent student("Vasin", "Ivanov", "Sergeeich", 100);
			BOOST_CHECK(false);
		}
		catch (std::out_of_range)
		{
			BOOST_CHECK(true);
		}
	}

	{
		try
		{
			CStudent student("Vasin", "Ivanov", "Sergeeich", 12);
			BOOST_CHECK(false);
		}
		catch (std::out_of_range)
		{
			BOOST_CHECK(true);
		}
	}

	///////////////////////////////////////////////////////////////////////
	CStudent student("Vasin", "Ivanov", "Sergeeich", 30);
	BOOST_CHECK(student.GetAge() == 30);
	BOOST_CHECK_THROW(student.SetAge(29), std::domain_error);
	BOOST_CHECK_NO_THROW(student.SetAge(40));
	BOOST_CHECK(student.GetAge() == 40);
	BOOST_CHECK(true);

}


