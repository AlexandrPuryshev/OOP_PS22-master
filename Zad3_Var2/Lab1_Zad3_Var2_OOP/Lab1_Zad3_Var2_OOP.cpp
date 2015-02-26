#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

const int N = 3; // размерность матрицы(3*3)
int iValue = 0;

void vMultiply(float fMatrix1[N][N], float fMatrix2[N][N], float fResultfMatrix[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			fResultfMatrix[i][j] = 0;
			for (int k = 0; k < N; k++)
			{
				fResultfMatrix[i][j] += fMatrix1[k][j] * fMatrix2[i][k];
			}
		}
	}
}

void vReadingFromFile(ifstream &File, float fMatrix[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			File >> fMatrix[i][j];
		}
	}
}

void vShowfMatrix(float fMatrix[N][N])
{
	int i,j;
	for (i = 0; i < N; i++)
	{
		printf("\n\n");
		for (j = 0; j < N; j++)
		{
			printf("%6.3f", fMatrix[i][j]);
		}
	}
}

void vSizeOfFile(ifstream &file)
{
	char ch;
	while (file >> ch)
	{
		iValue++;
	}
}

// от 9 до 63 при матрице 3*3

/*0		 0		0    |	 999.999 999.999 999.999
  0		 0		0    |	 999.999 999.999 999.999
  0		 0		0    |	 999.999 999.999 999.999.*/

float fInverseFunction(float fMatrix[N][N], int iRow, int iCol)
{
	float fAdditMatrix[N-1][N-1];

	int fAdditMatrixI = 0;
	for (int i = 0; i < N; i++)
	{
		if (i == iRow) { continue; }
		int fAdditMatrixJ = 0;
		for (int j = 0; j < N; j++)
		{
			if (j == iCol) { continue; }
			fAdditMatrix[fAdditMatrixI][fAdditMatrixJ] = fMatrix[i][j];
			fAdditMatrixJ++;
		}
		fAdditMatrixI++;
	}
	if ((iRow + iCol) % 2 == 0)
		return ((fAdditMatrix[0][0] * fAdditMatrix[1][1]) - (fAdditMatrix[0][1] * fAdditMatrix[1][0]));
	else
		return -((fAdditMatrix[0][0] * fAdditMatrix[1][1]) - (fAdditMatrix[0][1] * fAdditMatrix[1][0]));
}


int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	if (argc != 2)
	{
		cout << "Ошибка: Неверно число параметров!" << endl;
		return 0;
	}
	float  fModule = 0;
	float  fResultfMatrix[N][N];
	float  fInversfMatrix[N][N];
	float  fMatrix[N][N];
	ifstream File((const char*)argv[1]);
	if (!File.is_open()) // проверка на открытие файла
	{
		cout << "Ошибка при открытии файлов чтения \n";
		return 0;
	}
	vSizeOfFile(File);
	File.clear(); // сбрасывает биты ошибок
	File.seekg(0, ios::beg); // устанавливает указатель в начало

	if ((iValue >= 9) && (iValue <= 63))
	{
		vReadingFromFile(File, fMatrix);
		cout << "Исходная матрица: " << endl;
		vShowfMatrix(fMatrix);
		for (int j = 0; j < N; j++)
		{
			fModule = fMatrix[0][j] * fInverseFunction(fMatrix, 0, j) + fModule;
		}
		cout << "\n\nОпределитель исходной матрицы равен:" << fModule << endl;

		if (fModule == 0)
		{
			printf("\n\nВырожденная матрица!\n\n");
			return 0;
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				fInversfMatrix[j][i] = fInverseFunction(fMatrix, i, j) / fModule;
			}
		}
		printf("\n\nОбратная матрица:\n");
		vShowfMatrix(fInversfMatrix);
		printf("\n\nПроверка правильности нахождения обратной матрицы:\n");
		vMultiply(fMatrix, fInversfMatrix, fResultfMatrix);
		vShowfMatrix(fResultfMatrix);
		getchar();
		printf("\n");
		return 0;
	}
	else
	{
		cout << "Неправильный формат данных в txt файле!" << endl;
		return 0;
	}

}