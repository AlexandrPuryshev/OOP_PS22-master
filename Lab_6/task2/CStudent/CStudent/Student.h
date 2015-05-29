#pragma once
#include <string>

class CStudent
{
public:
	CStudent(const std::string name, const  std::string surname,
		const  std::string patronymic, const int age);
	CStudent();
	~CStudent();
	//////////////////////////////////////////////////////////////////////////////////
	std::string GetName() const;
	std::string GetSurname() const;
	std::string GetPatronymic() const;
	//////////////////////////////////////////////////////////////////////////////////
	int GetAge() const;
	void Rename(std::string name, std::string surname, std::string patronymic);
	void SetAge(int age);
private:
	int m_age;
	std::string m_name;
	std::string m_surname;
	std::string m_patronymic;
	//////////////////////////////////////////////////////////////////////////////////
	bool IsCorrectAge(const int age);
	bool stringIsAlphaAndNotHaveASpace(const std::string s);
	bool StringIsNotEmpty(const std::string str);
};

