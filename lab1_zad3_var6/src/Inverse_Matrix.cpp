#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

const int N = 3; //dimension of the matrix (3 * 3)

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
	int i, j;
	for (i = 0; i < N; i++)
	{
		printf("\n\n");
		for (j = 0; j < N; j++)
		{
			printf("%6.3f", fMatrix[i][j]);
		}
	}
}

void vSizeOfFile(ifstream &file, int iValue)
{
	char ch;
	while (file >> ch)
	{
		iValue++;
	}
}

//9 to 63 with a matrix of 3 * 3

/*0		 0		0    |	 999.999 999.999 999.999
0		 0		0    |	 999.999 999.999 999.999
0		 0		0    |	 999.999 999.999 999.999.*/

float fInverseFunction(float fMatrix[N][N], int iRow, int iCol)
{
	float fAdditMatrix[N - 1][N - 1];

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
		cout << "Error: Invalid number of parameters!" << endl;
		return 0;
	}
	float  fModule = 0;
	float  fResultfMatrix[N][N];
	float  fInversfMatrix[N][N];
	float  fMatrix[N][N];
	ifstream fIn;
	fIn.open((const char*)argv[1], ios::in);
	if (fIn.fail()) // check opening of the file
	{
		cout << "Error when opening files of reading" << endl;
		fIn.close();
		return 0;
	}
	int iValue = 0;
	vSizeOfFile(fIn, iValue);
	fIn.clear(); // Resets the error bits
	fIn.seekg(0, ios::beg); // Sets the pointer to the top file

	if ((iValue >= 9) && (iValue <= 63))
	{
		vReadingFromFile(fIn, fMatrix);
		cout << "Source matrix: " << endl;
		vShowfMatrix(fMatrix);
		for (int j = 0; j < N; j++)
		{
			fModule = fMatrix[0][j] * fInverseFunction(fMatrix, 0, j) + fModule;
		}
		cout << "\n\nThe determinant of the source matrix is:" << fModule << endl;

		if (fModule == 0)
		{
			printf("\n\nSingular matrix!\n\n");
			return 0;
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				fInversfMatrix[j][i] = fInverseFunction(fMatrix, i, j) / fModule;
			}
		}
		printf("\n\nThe inverse matrix:\n");
		vShowfMatrix(fInversfMatrix);
		printf("\n\nValidation of finding the inverse matrix:\n");
		vMultiply(fMatrix, fInversfMatrix, fResultfMatrix);
		vShowfMatrix(fResultfMatrix);
		system("pause");
		printf("\n");
		return 0;
	}
	else
	{
		cout << "Wrong format of the data in txt file!" << endl;
		return 0;
	}

}