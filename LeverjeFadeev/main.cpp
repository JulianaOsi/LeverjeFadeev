#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include <time.h>

using namespace std;

int main()
{
	printf("Enter Amount of Matrix: ");
	int matrAmount;
	scanf("%i", &matrAmount);
	//Спрашиваем у пользователя и считываем размер матрицы, с которой будем работать
	printf("Enter Size of Matrix: ");
	int N;
	scanf("%i", &N);

	//double* times = new double[matrAmount]; // Выделение памяти для массива

	//ofstream out;   //создаем поток
	//out.open("TestRunTime.txt", ios::app); // открываем файл для записи в конец
	//out << "Matrix: " << N << "x" << N << endl;

	for (int i = 0; i < matrAmount; i++)
	{
		//Создаем матрицу заданного размера
		Matr A = InitMatr(N, N);
		//двва способа заполнить матрицу, раскоменнтировать тот который нужен 
		//заполняем матрицу случайными числами ( для больших размеров матриц актуально)
		A = EnterRandom(A);

		//ofstream mtrx;
		//mtrx.open("TestMatrix.txt", ios::app); // открываем файл для записи в конец
		//for (int i = 0; i < N; i++) 
		//{
		//	for (int j = 0; j < N; j++)
		//	{
		//		mtrx << A.M[i][j]<<" ";
		//	}
		//	mtrx << endl;
		//}
		//mtrx << "__________________________________________________________________________________________________________________"<<endl;
		/*mtrx.close();*/

		//заполняем матрицу с клавиатуры, актуально для небольши размеров матрицы
		/*A* = EnterMatr(A);*/
		//выводим матрицу на экран
		Print(A); 
		//создаем две вспомогательных матрицы, они нужны для расчетов...
		Matr A1 = InitMatr(N, N);
		Matr B1 = InitMatr(N, N);
		//Матрица B1 сначала единичная
		B1 = EnterUnit(B1);
		//создаем матрицу, где будет записана обратная
		Matr UA = InitMatr(N, N);
		//создаем единичную матрицу, нужна для расчетов
		Matr E = InitMatr(N, N);
		E = EnterUnit(E);
		//создаем массив, где бдут записаны коэффициенты характеристического полинома
		double* lamb = new double[N];
		//Перед началом работы алгоритма снимаем время, чтобы оценить время выполнения расчетов
		unsigned int start_time = clock();
		//начинаем сам алгоритм Леверье-Фаддеева, запускаем не до последнего элемента
		//последний шаг считаем отдельно
		for (int i = 1; i < N; i++)
		{
			//Пересчитываем матрицу A1 и B1 по формулам Фаддеева
			A1 = A * B1;
			//Записываем очередной коэффициент характеристического полинома
			lamb[i - 1] = Spur(A1) / i;
			B1 = A1 - lamb[i - 1] * E;
		}
		//На последнем шаге считаем только матрицу A1 икоэффициент
		//матрица B1 на посчледнем шаге должна уйти в ноль
		A1 = A * B1;
		//записали последний коэффициент полинома
		lamb[N - 1] = Spur(A1) / N;
		//посчитали обратную матрицу, она считается через предпоследнюю матрицу B1
		//Почему мы и не считаем B 1еще раз...
		UA = (1 / lamb[N - 1]) * B1;
		//Смотрим время в конце работ алгоритма...
		unsigned int end_time = clock();
		//Выводим коэффициенты характеристического полинома
		printf("\n\nCoeff polynom's: \n");
		for (int i = 0; i < N; i++)
			printf("Lambda %i  --   %6.8f\n", i + 1, lamb[i]);
		//Печатаем обратную матрицу
		printf("\n\nInverse Matrix:");
		Print(UA);
		//Проверяем правильность обратной матрицы, выводм результат умножения обратной амтрицы и исходной
		printf("\n\nCheck to Inverse matrix: A^-1 * A");
		Print(UA * A);

		double runTime = ((double)end_time - start_time) / CLOCKS_PER_SEC;
		
		//times[i] = runTime;
		//out << runTime << endl;   // сама запись
		
		//ofstream lmb;
		//lmb.open("TestLamb.txt", ios::app); // открываем файл для записи в конец
		//for (int i = 0; i < N; i++)
		//{
		//	lmb << lamb[i]<<" ";
		//}
		//lmb << endl;
		//lmb.close();

		printf("Run time --- %f\n\n", runTime);
	}
	/*double sum=0;
	for (int i = 0; i < matrAmount; i++)
	{
		sum += times[i];
	}
	double average = sum / matrAmount;
	out << "Average: " <<fixed<< average << endl;

	out.close();*/
	return 0;
}
