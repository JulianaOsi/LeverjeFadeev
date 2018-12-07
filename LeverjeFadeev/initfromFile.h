#include <iostream>
#include <fstream>
#include <string>

Matr InitMatrFromFile(Matr A, FILE* file)
{
	char c;
	string matrVal;
	int i = 0;
	int j = 0;
	while ((j != A.col) and (c = fgetc(file)) != EOF)
	{
		if (c != ' ' and c != '\n')
			matrVal += c;
		else if (c == ' ')
		{
			double val = atof(matrVal.c_str());
			A.M[i][j] = val;
			cout << A.M[i++][j] << ' ';
			matrVal = "";
		}
		else if (c == '\n')
		{
			j++;
			i = 0;
			cout << '\n';
			matrVal = "";
		}
	}
	
	while ((c = fgetc(file)) != '\n')
	{
	}
	fgetc(file);

	return A;
}
