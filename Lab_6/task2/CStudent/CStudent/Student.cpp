#include "stdafx.h"
#include "Student.h"

bool  CStudent::stringIsAlphaAndNotHaveASpace(const std::string s)
{
	for (std::string::const_iterator it = s.begin(); it != s.end(); ++it)
	{
		const char ch = *it;
		if (!isalpha(ch) || ch == ' ')
		{
			return false;
		}
	}
	return true;	
}

bool CStudent::StringIsNotEmpty(const std::string  str)
{
	return (!str.empty());
}

bool CStudent::IsCorrectAge(const int age)
{
	if (age < 14 || age > 60)
	{
		throw std::out_of_range("Age is out of range");
	}
	return true;
}

std::string CStudent::GetName() const
{
	return m_name;
}

std::string CStudent::GetSurname() const
{
	return m_surname;
}

std::string CStudent::GetPatronymic() const
{
	return m_patronymic;
}

int CStudent::GetAge() const
{
	return m_age;
}

void CStudent::SetAge(int age)
{
	if (IsCorrectAge(age))
	{
		if (age > m_age)
		{
			m_age = age;
		}
		else
		{
			throw std::domain_error("New age less than previous");
		}
	}
}

void CStudent::Rename(std::string name, std::string surname, std::string patronymic)
{
	if (stringIsAlphaAndNotHaveASpace(name) && stringIsAlphaAndNotHaveASpace(surname) && stringIsAlphaAndNotHaveASpace(patronymic)
		&& (StringIsNotEmpty(name) && StringIsNotEmpty(surname) && StringIsNotEmpty(patronymic)))
	{
		m_name = move(name);
		m_surname = move(surname);
		m_patronymic = move(patronymic);
	}
	else
	{
		throw std::invalid_argument("name or surname or patromymic is incorrect");
	}
}

CStudent::CStudent(const std::string name, const  std::string surname,
	const  std::string patronymic, const int age)
{
	if (stringIsAlphaAndNotHaveASpace(name) && stringIsAlphaAndNotHaveASpace(surname) && stringIsAlphaAndNotHaveASpace(patronymic)
	 && (StringIsNotEmpty(name) && StringIsNotEmpty(surname) && StringIsNotEmpty(patronymic)))
	{
		m_name = move(name);
		m_surname = move(surname);
		m_patronymic = move(patronymic);
		if (IsCorrectAge(age))
			m_age = age;
		else
			throw std::out_of_range("Wrong age");
	}
	else
	{
		throw std::invalid_argument("name or surname or patromymic is incorrect");
	}
}

CStudent::CStudent()
{

}

CStudent::~CStudent()
{
}

