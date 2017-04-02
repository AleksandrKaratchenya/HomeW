#include<iostream>
#include<cmath>
using namespace std;
int ** AllocateMemory1(int n);
void DisplayMatrix(int**matrix, int n);
void DisplayArray(int * a, int n);
void RandomMatrix(int**matrix,  int n);
int*  CreateArray(int**matrix, int n, int i, int j, int p, int &k);
//void CreateArray(int**matrix, int n, int i, int j, int p);
int* AllocateMemory(int n);
//void  CreateArray2(int**matrix, int n, int i, int j);
int MaxInArray(int*arr, int d);
int FindMaxElementInTheSelectedArea(int**matrix, int n, int i, int j);
int ** CreateMatrix(int  **matrix, int n);
void EnterMatrix(int  **matrix, int n);


int main()
{
	int n = 3;
	int k = 0;
	int **matrix1 = AllocateMemory1(n);
	int **matrix2 = AllocateMemory1(n);
	//RandomMatrix(matrix1,n);
	EnterMatrix(matrix1, n);
    cout << "Original matrix" << endl;
	DisplayMatrix(matrix1, n);
    cout << endl;
	matrix2 = CreateMatrix(matrix1, n);
	cout << "Resulting matrix" << endl;
	DisplayMatrix(matrix2, n);
	cout << endl;
	system("pause");
	return 0;
}


int ** AllocateMemory1(int n)
{
	int**matrix = new int*[n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n];
		for (int j = 0; j < n; j++)
			matrix[i][j] = 0;
	}
	return matrix;
}
void DisplayArray(int* a, int n)
{
	for (int* p = a; p < a + n; p++)
	{
		cout << " " << *p;
	}
}
void DisplayMatrix(int**matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout.width(5);
		DisplayArray(matrix[i], n);
		cout << endl;
	}
}
void RandomMatrix(int**matrix,int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matrix[i][j] = rand()%10;
}
int* AllocateMemory(int n)
{
	int*arr = new int[n];
	for (int i = 0; i < n; i++)
		arr[i] = 0;
	return arr;
}



int*  CreateArray(int**matrix, int n, int i, int j, int p,int &k) 
{
	int* arr= AllocateMemory(n);
	for (; i<n; i++)
	{
		for ( ; j< n-p; j++)
		{
			arr[k] = matrix[i][j];
			k++;
		}
	}
	return arr;
}

int FindMaxElementInTheSelectedArea(int**matrix, int n, int i, int j)
{
	int* arr= AllocateMemory(n);
	int l = 0;
	int *dimension = AllocateMemory(n);
	int k = 0;
	for (int p = n - j-1 ; i<n; p--, i++, j--)
	{
		if (j < 0) 
			j = 0;
		if (p < 0) p = 0;
        arr= CreateArray(matrix, n, i, j, p,k);
		dimension[l] = MaxInArray(arr, k);
		k = 0;
		l++;
		
	}
	int maxelemet = MaxInArray(dimension, l);
	return maxelemet;
} 


int MaxInArray(int*arr, int d)
{
	int max;
	if (d == 1)
		return arr[0];
	max = arr[0];
	for (int i = 0; i < d; i++)
	{   	
		if (max < arr[i + 1])
			max = arr[i + 1];		
	}		
	return max ;

}

int ** CreateMatrix(int  **matrix,int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matrix[i][j] = FindMaxElementInTheSelectedArea(matrix, n, i, j);
	return matrix;

}

void EnterMatrix(int  **matrix, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cout << " matrix[" << i << "]" << "[" << j << "]"<< " = ";
			cin >> matrix[i][j];
		}
}