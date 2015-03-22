#include "stdafx.h"

const int N = 3; //dimension of the matrix (3 * 3)

void Multiply(float Matrix1[N][N], float Matrix2[N][N], float ResultMatrix[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			ResultMatrix[i][j] = 0;
			for (int k = 0; k < N; k++)
			{
				ResultMatrix[i][j] += Matrix1[k][j] * Matrix2[i][k];
			}
		}
	}
}

void ReadingFromFile(ifstream &File, float Matrix[N][N])
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
				if (!(File >> Matrix[i][j]))
				{
					cout << "this is not matrix (3*3)!" << endl;
					File.close();
					exit(-1);
				}
		}
	}
}

void ShowMatrix(float Matrix[N][N], ofstream &fOut)
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		fOut << "\n\n";
		printf("\n\n");
		for (j = 0; j < N; j++)
		{
			fOut << std::fixed << std::setprecision(3) << "    " << Matrix[i][j];
			printf("|%6.3f|", Matrix[i][j]);
		}
	}
}


float InverseFunction(float Matrix[N][N], int iRow, int iCol)
{
	float AdditMatrix[N - 1][N - 1];

	int AdditMatrixI = 0;
	for (int i = 0; i < N; i++)
	{
		if (i == iRow) { continue; }
		int AdditMatrixJ = 0;
		for (int j = 0; j < N; j++)
		{
			if (j == iCol) { continue; }
			AdditMatrix[AdditMatrixI][AdditMatrixJ] = Matrix[i][j];
			AdditMatrixJ++;
		}
		AdditMatrixI++;
	}
	if ((iRow + iCol) % 2 == 0)
		return ((AdditMatrix[0][0] * AdditMatrix[1][1]) - (AdditMatrix[0][1] * AdditMatrix[1][0]));
	else
		return -((AdditMatrix[0][0] * AdditMatrix[1][1]) - (AdditMatrix[0][1] * AdditMatrix[1][0]));
}

//void CheckSizeOMatrix(ifstream &File)
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
	float  Module = 0;
	float  ResultMatrix[N][N];
	float  InversMatrix[N][N];
	float  Matrix[N][N];
	ifstream fIn;
	fIn.open((const char*)argv[1], ios::in);
	if (fIn.fail()) // check opening of the file
	{
		cout << "Error when opening files of reading" << endl;
		return 0;
	}
		ReadingFromFile(fIn, Matrix);
		fIn.close();
		ofstream fOut;
		fOut.open("output.txt", ios::out);
		cout << "Source matrix: " << endl;
		ShowMatrix(Matrix, fOut);
		for (int j = 0; j < N; j++)
		{
			Module = Matrix[0][j] * InverseFunction(Matrix, 0, j) + Module;
		}
		cout << "\n\nThe determinant of the source matrix is:" << Module << endl;

		if (Module == 0)
		{
			printf("\n\nSingular matrix!\n\n");
			fIn.close();
			return 0;
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				InversMatrix[j][i] = InverseFunction(Matrix, i, j) / Module;
			}
		}

		printf("\n\nThe inverse matrix:\n");
		fOut << "\n----------------------------";
		ShowMatrix(InversMatrix, fOut);
		fOut.close();
		printf("\n\nValidation of finding the inverse matrix:\n");
		Multiply(Matrix, InversMatrix, ResultMatrix);
		ShowMatrix(ResultMatrix, fOut);
		printf("\n");
		system("pause");
		return 0;
}