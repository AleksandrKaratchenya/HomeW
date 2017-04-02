#include<iostream>
#include<cmath>
using namespace std;
double ** AllocateMemory1(int n);
void DisplayMatrix(double**matrix, int n);
void DisplayArray(double * a, int n);
double Sinus(double x, double eps);
double CreateElemets(int i, int j, double eps);
double CreateElemets(int i, int j);
double** CreateMatrix(int n, double eps, double **matrix);
double **CreateMatrix(int n, double **matrix);
double SumModulesElements(double*a, int n);
double Norm(double**a, int n);

int main()
{
	int n;
	double accurancy;
	cout << "Enter accurancy = ";
	cin >> accurancy;
	cout << "Enter n = ";
	cin >> n;
	cout << endl;
	 double **matrix1=AllocateMemory1(n);
	 double **matrix2 = AllocateMemory1(n);
	 cout <<"First matrix "<< endl;
	 matrix1 = CreateMatrix(n, accurancy, matrix1);
		 DisplayMatrix(matrix1, n);
		 cout << endl;
		 cout << "Second matrix " << endl;
		 matrix2 = CreateMatrix(n, matrix2);
		 DisplayMatrix(matrix2, n);
		 cout << endl;
		 cout << "Norm 1 -Norm  2  "<< Norm(matrix1, n)- Norm(matrix2, n) <<endl;
		 cout << "Norm 1"<< endl;
		 cout << Norm(matrix1, n);
		 cout << endl;
		 cout << "Norm  2  " << endl;
		 cout << Norm(matrix2, n);
	system("pause");
	return 0;
}

double Sinus(double x, double eps)// синус
{
	double res = 0, term = x, p = -1;
	int i = 1;
	while (fabs(res) > eps)
	{
		res += term;
		i += 2;
		term *= (x*x / (i*(i - 1))*p);
	}

	return res;
}

double ** AllocateMemory1(int n)
{
	double**matrix = new double*[n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new double[n];
		for (int j = 0; j < n; j++)
			matrix[i][j] = 0;
	}
	return matrix;
}

double SumModulesElements(double*a, int n)
{
	double sum = 0;
	 
	for (int i = 0; i < n; i++)
	{
		sum += fabs(a[i]);
	}
	return sum;
}
double Norm (double**matrix,int n)
{
	double maxsum;
	for (int i = 0; i < n-1; i++)
	{
		if (SumModulesElements(matrix[i], n) >= SumModulesElements(matrix[i + 1], n))
			maxsum = SumModulesElements(matrix[i], n);
		else maxsum = SumModulesElements(matrix[i + 1], n);		
	}
	return maxsum;
}


void DisplayArray(double* a, int n)
{
	for (double* p = a; p < a + n; p++)
	{
		cout << " " << *p;
	}
}
void DisplayMatrix(double**matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		DisplayArray(matrix[i], n);
		cout << endl;
	}
}
double** CreateMatrix(int n, double eps, double **matrix)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			matrix[i][j] = CreateElemets(i,j, eps);
	return matrix;

}
double** CreateMatrix(int n,  double **matrix)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matrix[i][j] = CreateElemets(i, j);
	return matrix;

}

double CreateElemets(int i, int j, double eps)
{
	double element;
	if (i != j)
		element = (Sinus(i*j, eps) + i + 1) / pow((j + 1), 3);
	else element = i;
	return element;
}
double CreateElemets(int i, int j)
{
	double element;
	if (i != j)
		element = (sin(i*j) + i + 1) / pow((j + 1), 3);
	else element = i;
	return element;
}
