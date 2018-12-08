//#pragma once
#include <fstream>

#include <time.h>
using namespace std;

struct Matr // Новый тип Матрица
{
	double** M; // Собственно сама матрица
	int row;    // количество строк
	int col;    // количество столбцов
};

//------------------------------------------ЮЛЯ--------------------------------------------------------//

// Функция определения матрицы. по ее размерам. Возвращает пустую матрицу
Matr InitMatr(register int n, register int m)
{
	//Определяем временную матрицу
	Matr temp;
	//выделяем память под строки
	temp.M = new double*[n];
	//запсываем размеры матрицы
	temp.row = n;
	temp.col = m;
	register int i;
	 int t = temp.row;
	//выделяем память под каждый из столбцов...
	for (i = 0; i < t; i++)
	{
		temp.M[i] = new double[m];
	}
	//возвращаем созданную матрицу
	return temp;
}

//----------------------------ЮЛЯ----------------------------------------------------------------------//

//// Возвращает разность двух матриц
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

// Возвращает сумму двух матриц
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

//Функция для рассчета следа матрицы
double Spur(Matr A)
{
	register int i;
	 int Ar = A.row;
	 double t = 0;
	for (i = 0; i < Ar; i++)
		t += A.M[i][i];
	return t;
}

//--------------------------------------МИХА------------------------------------------------------------//

// Заполнение матрицы нолями, все элементы матрицы нули
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

// Создание единичной матрицы
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


//---------------------------------------------ЖЕНЯ,СЛАВА-----------------------------------------------------//

//Умножение двух матриц
Matr operator *(Matr A, Matr B)
{
	//создаем вспомогательную матрицу
	Matr C;
	 int Ar = A.row;
	 int Ac = A.col;
	 int Bc = B.col;

	C = InitMatr(Ar, Bc);
	C = EnterZero(C);

	register int i, j ,l;
	//во вспомогательную матрицу записываем результат умножения двух заданных матриц
	for (i = 0; i < Ar; i++)
		for (j = 0; j < Bc; j++)
			for (l = 0; l < Ac; l++)
				C.M[i][j] += A.M[i][l] * B.M[l][j];

	//возвращаем результат умножения
	return C;
}

// Умножение матрицы на скаляр
Matr operator * (register double a, Matr B)
{
	//создаем вспомогательную матрицу
	Matr C;
	int Bc = B.col;
	int Br = B.row;
	C = InitMatr(Br, Bc);
	C = EnterZero(C);
	register int i, j;
	//во вспомогательную матрицу записываем результат умножения матрицы на скаляр
	for (i = 0; i < Br; i++)
		for (j = 0; j < Bc; j++)
			C.M[i][j] = B.M[i][j] * a;
	return C;
}

//////////////////////////////////////////////////////////////////////////////////////////////

// заполняет матрицу случайными вещественными числами
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

// Печатает матрицу на экране
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

// заполняет матрицу числами введенными с клавиатуры
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