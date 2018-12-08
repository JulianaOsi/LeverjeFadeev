//#pragma once
#include <fstream>

#include <time.h>
using namespace std;

struct Matr // ����� ��� �������
{
	double** M; // ���������� ���� �������
	int row;    // ���������� �����
	int col;    // ���������� ��������
};

//------------------------------------------���--------------------------------------------------------//

// ������� ����������� �������. �� �� ��������. ���������� ������ �������
Matr InitMatr(register int n, register int m)
{
	//���������� ��������� �������
	Matr temp;
	//�������� ������ ��� ������
	temp.M = new double*[n];
	//��������� ������� �������
	temp.row = n;
	temp.col = m;
	register int i;
	 int t = temp.row;
	//�������� ������ ��� ������ �� ��������...
	for (i = 0; i < t; i++)
	{
		temp.M[i] = new double[m];
	}
	//���������� ��������� �������
	return temp;
}

//----------------------------���----------------------------------------------------------------------//

//// ���������� �������� ���� ������
Matr operator -(Matr A, Matr B)
{
	register int i, j;
	 int Ar = A.row;
	 int Ac = A.col;

	for (i = 0; i < Ar; i++)
		for (j = 0; j < Ac; j++)
			A.M[i][j] -= B.M[i][j];

	return A;
}

// ���������� ����� ���� ������
Matr operator +(Matr A, Matr B)
{
	register int i, j;
	 int Ar = A.row;
	 int Ac = A.col;
	for (i = 0; i < Ar; i++)
		for (j = 0; j < Ac; j++)
			A.M[i][j] += B.M[i][j];

	return A;
}

//������� ��� �������� ����� �������
double Spur(Matr A)
{
	register int i;
	 int Ar = A.row;
	 double t = 0;
	for (i = 0; i < Ar; i++)
		t += A.M[i][i];
	return t;
}

//--------------------------------------����------------------------------------------------------------//

// ���������� ������� ������, ��� �������� ������� ����
Matr EnterZero(Matr A)
{
	register int i, j;
	 int Ar = A.row;
	 int Ac = A.col;

	for (i = 0; i < Ar; i++)
	{
		for (j = 0; j < Ac; j++)
			A.M[i][j] = 0;
	}
	return A;
}

// �������� ��������� �������
Matr EnterUnit(Matr A)
{
	register int i, j;
	 int Ar = A.row;
	 int Ac = A.col;

	for (i = 0; i < Ar; i++)
	{
		for (j = 0; j < Ac; j++)
			A.M[i][j] = 0;
		A.M[i][i] = 1;
	}
	return A;
}


//---------------------------------------------����,�����-----------------------------------------------------//

//��������� ���� ������
Matr operator *(Matr A, Matr B)
{
	//������� ��������������� �������
	Matr C;
	 int Ar = A.row;
	 int Ac = A.col;
	 int Bc = B.col;

	C = InitMatr(Ar, Bc);
	C = EnterZero(C);

	register int i, j ,l;
	//�� ��������������� ������� ���������� ��������� ��������� ���� �������� ������
	for (i = 0; i < Ar; i++)
		for (j = 0; j < Bc; j++)
			for (l = 0; l < Ac; l++)
				C.M[i][j] += A.M[i][l] * B.M[l][j];

	//���������� ��������� ���������
	return C;
}

// ��������� ������� �� ������
Matr operator * (register double a, Matr B)
{
	//������� ��������������� �������
	Matr C;
	int Bc = B.col;
	int Br = B.row;
	C = InitMatr(Br, Bc);
	C = EnterZero(C);
	register int i, j;
	//�� ��������������� ������� ���������� ��������� ��������� ������� �� ������
	for (i = 0; i < Br; i++)
		for (j = 0; j < Bc; j++)
			C.M[i][j] = B.M[i][j] * a;
	return C;
}

//////////////////////////////////////////////////////////////////////////////////////////////

// ��������� ������� ���������� ������������� �������
Matr EnterRandom(Matr A)
{
	srand((unsigned int)time(0));
	for (int i = 0; i < A.row; i++)
	{
		for (int j = 0; j < A.col; j++)
		{
			A.M[i][j] = (double)rand() / (double)RAND_MAX;
			
		}
	}
	return A;
}

// �������� ������� �� ������
void Print(Matr A)
{
	printf("\n\nEnter Matrix To Console!!!\n");
	for (int i = 0; i < A.row; i++)
	{
		for (int j = 0; j < A.col; j++)
			printf("%10.8f    ", A.M[i][j]);
		printf("\n");
	}
}

// ��������� ������� ������� ���������� � ����������
Matr EnterMatr(Matr A)
{
	printf("\nEnter elements of matrix from Console...");
	for (int i = 0; i < A.row; i++)
	{
		for (int j = 0; j < A.col; j++)
		{
			printf("\nEnter A[%i][%i]: ", i, j);
			double temp;
			scanf("%lf", &temp);
			A.M[i][j] = temp;
		}
	}
	return A;
}