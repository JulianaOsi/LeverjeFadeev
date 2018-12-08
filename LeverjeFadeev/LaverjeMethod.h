#include "matrix.h"

double** Laverje(double **M, register int N) {
	
	Matr A = InitMatr(N, N);
	A.M = M;
	Matr A1 = InitMatr(N, N);
	Matr B1 = InitMatr(N, N);

	B1 = EnterUnit(B1);

	Matr UA = InitMatr(N, N);

	Matr E = InitMatr(N, N);
	E = EnterUnit(E);

	double* lamb = new double[N];

	//Начало времени выполнения алгоритма
	unsigned int start_time = clock();
	register int i;
	
	for (i = 1; i < N; i++)
	{
		A1 = A * B1;
		lamb[i - 1] = Spur(A1) / i;
		B1 = A1 - lamb[i - 1] * E;
	}
	A1 = A * B1;
	lamb[N - 1] = Spur(A1) / N;
	UA = (1 / lamb[N - 1]) * B1;

	//Конец времени выполнения алгоритма
	unsigned int end_time = clock();
	double* runTime = new double[1]{ ((double)end_time - start_time) / CLOCKS_PER_SEC };
	double ** result = new double*[2]{lamb, runTime};
	return result;
}
