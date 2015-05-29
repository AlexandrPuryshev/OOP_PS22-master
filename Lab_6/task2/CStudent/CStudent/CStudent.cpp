// CStudent.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "Student.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	string name, surname, patronic;
	int age;
	try
	{
		cout << "���: "; cin >> name; cout << endl;
		cout << "�������: "; cin >> surname; cout << endl;
		cout << "��������: "; cin >> patronic; cout << endl;
		cout << "�������: "; cin >> age; cout << endl;
		CStudent student(name, surname, patronic, age);
	}
	catch (exception e)
	{
		cout << "Error: " << e.what() << endl;
	}
	return 0;
}

