#include<iostream>
using namespace std;
int** AllocateMemory(int n, int*arr);//arr= массив размерностей
void  RandomMatrix(int**, int*, int);
int* AllocateMemory(int n);
void Swap(int&a, int&b);
void Swap(int*&a, int*&b);
void RandomArray(int* a, int n);
void DisplayArray(int* a, int n);
void DisplayMatrix(int **matrix, int n, int *arr);
void Swapping(int **matrix, int n,int *arr);


int main()
{
	int n = 6;
	int *arr = AllocateMemory(n);
	RandomArray(arr, n);
	DisplayArray(arr, n);
	cout << endl;
	int **matrix = AllocateMemory(n, arr);
	RandomMatrix(matrix, arr, n);
	DisplayMatrix(matrix, n, arr);
	cout << endl;
	Swapping(matrix, n,arr);
	DisplayMatrix(matrix, n, arr);
	cout << endl;
	system("pause");
	return 0;
}

int** AllocateMemory(int n, int *arr)// выделение памяти под матрицу 
{
	int**matrix = new int*[n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[arr[i]];
		for (int j = 0; j < arr[i]; j++)
			matrix[i][j] = 0;
		
	}
	return matrix;
}
void RandomMatrix(int**matrix, int*arr, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < arr[i]; j++)
			matrix[i][j] = rand() % 10+2;
}
int* AllocateMemory(int n)// выделяет память для одномерного динамического массива
{
	int*arr = new int[n];
	for (int i = 0; i < n; i++)
		arr[i] = 0;
	return arr;
}



void Swap(int*&a, int*&b)
{
	int*t = a;
	a = b;
	b = t;
}
void Swap(int&a, int&b)
{
	int t = a;
	a = b;
	b = t;
}

void RandomArray(int* a, int n)
{
	int i = n;
	for (int* p = a; p < a + n; p++)
	{
		*p = i;
		i--;
	}
}
void DisplayArray(int* a, int n)
{
	for (int* p = a; p < a + n; p++)
	{
		cout << " " << *p;
	}
}
void DisplayMatrix(int **matrix, int n, int *arr)
{
	for (int i = 0; i <n; i++)
	{
		if (arr[i] != n)
			for (int j = n-1; j>=arr[i]; j--)
			{
				cout.width(5);
				cout << 0;
			}
         for (int j = 0; j< arr[i]; j++)
		{
		cout.width(5);
		cout << matrix[i][j];
		}
		cout << endl;
	}
}
/*DisplayArray(matrix[i], arr[i]);
		cout << endl;*/
void Swapping(int **matrix, int n,int *arr)
{
	for (int i = 0; i < n / 2; i++)
	{
		Swap(matrix[i], matrix[n - i-1]);
		Swap(arr[i], arr[n - i-1]);
	}

}