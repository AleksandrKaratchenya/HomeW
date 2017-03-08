#include<iostream>
using namespace std;
int** AllocateMemory(int n, int*arr);//arr= массив размерностей
void  RandomMatrix(int**,int*,int);
int* AllocateMemory(int n);
int SumString(int*a,int n);//(сумма элементов 1 строки)
int*CreateSumRows(int**matrix, int*arr, int n,int *rows);
void SortBySumRows(int**matrix, int*rows,int *arr, int n);//сортировка массива сумм
void Swap(int&a, int&b);
void Swap(int*&a, int*&b);
void RandomArray(int* a, int n);
void DisplayArray(int* a, int n);
void DisplayMatrix(int **matrix, int n, int *arr);
void SortBySumRows2(int**matrix, int*arr, int n);




int main() 
{

	int n = 6;
	int *arr = AllocateMemory(n);
	RandomArray(arr, n);
	int **matrix = AllocateMemory(n, arr);
	DisplayArray(arr, n);
	cout << endl;
	RandomMatrix(matrix, arr, n);
	DisplayMatrix(matrix, n, arr);
	cout << endl;
	int *rows = AllocateMemory(n);
	rows = CreateSumRows(matrix, arr, n, rows);
	 //SortBySumRows(matrix, rows,arr, n);// 1 вариант 
	SortBySumRows2(matrix, arr, n);//2 вариант 

	DisplayMatrix(matrix, n, arr);
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
			matrix[i][j] = 0;// обнулили элементы самой матрицы
	}
	return matrix;
}
void RandomMatrix(int**matrix, int*arr,int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < arr[i]; j++)
			matrix[i][j] = rand() % 10;
}
int* AllocateMemory(int n)// выделяет память для одномерного динамического массива
{
	int*arr = new int[n];
	for (int i = 0; i < n; i++)
		arr[i] = 0;
	return arr;
}
int SumString(int*a, int n)//вызов для  3 строки SumString(matrix[3],arr[3])
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += a[i];
	}
	return sum;
}
int*CreateSumRows(int**matrix, int*arr, int n,int *rows)
{
	for (int i = 0; i < n; i++) 
	{
		rows[i] = SumString(matrix[i], arr[i]);
	}
	return rows;
}
void SortBySumRows(int**matrix, int*rows,int*arr, int n)
{
	for(int i=1;i<n;i++)
		for (int j = n - 1; j >= i; j--)
			if (rows[j] < rows[j - 1])
			{
				Swap(rows[j], rows[j - 1]);
			Swap(matrix[j], matrix[j-1]);
			Swap(arr[j], arr[j - 1]);
			}
	delete[] rows;
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
 void SortBySumRows2(int**matrix, int*arr, int n)// 2 вариант 
 {
	 for (int i = 1; i < n; i++)
		 for (int j = n - 1; j >= i; j--)
			 if (SumString(matrix[j], arr[j]) <= SumString(matrix[j - 1], arr[j - 1]))
			 {
				 Swap(matrix[j], matrix[j - 1]);
				 Swap(arr[j],arr[j-1]);
			 }
 }
 void RandomArray(int* a, int n)
 {
	 for (int* p = a; p < a + n; p++)
	 {
		 *p = rand() % 10 +1;
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
	 for (int i = 0; i < n; i++)
	 {
		 DisplayArray(matrix[i], arr[i]);
		 cout << endl;
		 
		 
		 /* for (int j = 0; j < arr[i]; j++)
		 {
			 cout.width(5);
			 cout << matrix[i][j];
		 }
		 cout << endl;*/
	 }
 }
 