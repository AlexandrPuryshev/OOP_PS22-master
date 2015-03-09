#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

const int N = 3; //dimension of the matrix (3 * 3)

void Multiply(float fMatrix1[N][N], float fMatrix2[N][N], float fResultfMatrix[N][N])
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

void ReadingFromFile(ifstream &File, float fMatrix[N][N])
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
				if (!(File >> fMatrix[i][j]))
				{
					cout << "this is not matrix (3*3)!" << endl;
					File.close();
					exit(-1);
				}
		}
	}
}

void ShowfMatrix(float fMatrix[N][N])
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		printf("\n\n");
		for (j = 0; j < N; j++)
		{
			printf("|%6.3f|", fMatrix[i][j]);
		}
	}
}


float InverseFunction(float fMatrix[N][N], int iRow, int iCol)
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

//void CheckSizeOfMatrix(ifstream &File)
//{
//	string StringAllFile;
//	string StirngDitarminate;
//	int RowCount = 1, ElementInMass = 0;
//	int ColCount, CountElementInMass = 0;
//	int count = 0;
//	char chSymbolTrancsfer;
//	while (!File.eof())
//	{
//		getline(File, StirngDitarminate);
//		File >> chSymbolTrancsfer;
//		StringAllFile += StirngDitarminate + chSymbolTrancsfer;
//		if (chSymbolTrancsfer == '\n') // next row in file: "\n"
//		{
//			RowCount++;
//		}
//	}
//	while (StringAllFile[count] != EOF)
//	{
//		if (isdigit(StringAllFile.c_str()[count]))
//		CountElementInMass++;
//		count++;
//	}
//	ColCount = (CountElementInMass - RowCount) / RowCount;
//	if ((ColCount * RowCount) != N*N)
//	{
//		cout << "this is not matrix (3*3)!" << endl;
//		File.close();
//		exit(-1);
//	}
//}

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
		ReadingFromFile(fIn, fMatrix);
		fIn.close();
		cout << "Source matrix: " << endl;
		ShowfMatrix(fMatrix);
		for (int j = 0; j < N; j++)
		{
			fModule = fMatrix[0][j] * InverseFunction(fMatrix, 0, j) + fModule;
		}
		cout << "\n\nThe determinant of the source matrix is:" << fModule << endl;

		if (fModule == 0)
		{
			printf("\n\nSingular matrix!\n\n");
			fIn.close();
			return 0;
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				fInversfMatrix[j][i] = InverseFunction(fMatrix, i, j) / fModule;
			}
		}
		printf("\n\nThe inverse matrix:\n");
		ShowfMatrix(fInversfMatrix);
		printf("\n\nValidation of finding the inverse matrix:\n");
		Multiply(fMatrix, fInversfMatrix, fResultfMatrix);
		ShowfMatrix(fResultfMatrix);
		printf("\n");
		system("pause");
		return 0;
}