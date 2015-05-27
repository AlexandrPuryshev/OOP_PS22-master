// CStudent.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Student.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	string name, surname, patronic;
	int age;
	cout << "Имя: "; cin >> name; cout << endl;
	cout << "Фамилия: "; cin >> surname; cout << endl;
	cout << "Отчество: "; cin >> patronic; cout << endl;
	cout << "Возраст: "; cin >> age; cout << endl; 
	CStudent student(name, surname, patronic, age);
	return 0;
}

