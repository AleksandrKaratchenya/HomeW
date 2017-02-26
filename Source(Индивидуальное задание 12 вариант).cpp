#include <iostream>
//Example 1) (0,-2,12,-7,30,-4,37,-7,270,-2,188,-7,10,-9,2730,-8,2986,-1)
//               2) (-2,-4,0,-7,38,-1,210,-7,16,-7,8,5,-4,6,-1,8,-2,8)

using namespace std;

void Swap(int&, int&);
void Swap(int*, int*);
int* AllocateMemory(int);
void RandomArray(int*, int);
void DisplayArray(int*, int);
void EnterArray(int*, int);
void BubbleSort(int*, int);
void DeleteElemetsInArrayA(int*, int*, int&,int&);
int IsPositive(int*);
int IsEven(int*);
void ConvertAndCout(int, int );
int CouterABSDEF(int);
void Delets2(int*, int&);

int main()
{
	int n =18;
	int m = 0;
	int *b = AllocateMemory(n);
	int *a = AllocateMemory(n);
	int *z = b;
	cout << "Array a" << endl;
	DisplayArray(a, n);  
	cout << endl;
	 //RandomArray(a,n);
	EnterArray(a, n);
	cout <<"Array a (original array)" << endl;
	DisplayArray(a, n);
	cout << endl;
	DeleteElemetsInArrayA(a,z, n,m);
	cout << "Array  a (after deleting the desired numbers)" << endl;
	DisplayArray(a, n);
	cout << endl;
	cout << "Array  b (desired numbers)" << endl;
	DisplayArray(b, m);
	cout << endl;
	Delets2(b, m); 
	cout << "Array  b (after deleting repeating number(which include an equal numder of letters(A,B...F)))" << endl;
	DisplayArray(b, m);
	cout << endl;
	BubbleSort(b, m);
	cout << "Array b(after sorting by the number of letters)" << endl;
	DisplayArray(b, m);
	cout << endl;
	system("pause");

	delete[] a;
	delete[] b;



		
	//int y,x,r,t,i;// for chek 16 numbers
	//	cin >> y;
	//	cout << "0x" << hex << y << endl;
	//	cin >> x;
	//	cout << "0x" << hex << x << endl;
	//	cin >> r;
	//	cout << "0x" << hex << r<< endl; cin >> t;
	//	cout << "0x" << hex << t << endl; cin >> i;
	//	cout << "0x" << hex << i << endl;
	//	system("pause");

	return 0;
}

void Swap(int * a, int * b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void Swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}




int* AllocateMemory(int n)
{
	int* a = new int[n];

	   for (int* p = a; p < a + n; p++)
	   {
	        *p = 0;
	    }

	return a;
}

void RandomArray(int* a, int n)
{
	for (int* p = a; p < a + n; p++)
	{
		*p = rand() % 10;
	}
}

void DisplayArray(int* a, int n)
{
	for (int* p = a; p < a + n; p++)
	{
		cout << " " << *p;
	}
}

void EnterArray(int * a, int n)
{
	for (int *p = a, i = 1; p < a + n; p++, i++)
	{
		
		cout << "a[" << i << "] = ";
		cin >> *p;
	}
}
void BubbleSort(int *a, int n)
{
	for (int *p=a; p < a+n; p++)	
	{
		for (int *g = a+n-1; g >p; g--)
		{
			if (CouterABSDEF(*g)> CouterABSDEF(*(g -1)))
			{
				Swap(g, (g - 1));
				
			}
		}
	}
}
//void BubbleSort(int *a, int n)
//{
//	for (int *p = a; p < a + n; p++)
//	{
//		for (int *g = a + n - 1; g >p; g--)
//		{
//			if (*g> *(g - 1))
//			{
//				Swap(g, (g - 1));
//
//			}
//		}
//	}
//}


void DeleteElemetsInArrayA(int *a, int *z,int &n, int&m)
{
	for (int *p = a; p < a+ n; p++)
	{
		if (IsPositive(p) && IsEven(p) && (!IsPositive(p + 1)))
		{
			*(z+m)= *p; 
			m++;
			for (int i = 0; i < n-(p-a)-1; ++i)
			{
				*(p + i) = *(p + i + 1);
			}
			--n;
		}
	}
}

int IsPositive(int*p)
{
	if (*p > 0)
		return 1;
	if (*p < 0)
		return 0;
	if (*p == 0)
		return 0;
}
int IsEven(int*p)
{
	if (*p % 2 == 0)
		return 1;
	else return 0;
}

void ConvertAndCout(int numderconverte, int counter)
{

	long long remainder = numderconverte; 
	int i = 0;
	int *mass = new int[256];
	do
	{
		numderconverte /= 16;
		remainder %= 16;
		*(mass+i) = remainder;
		i++; 
		remainder = numderconverte;
	} while (numderconverte > 16);
	  mass[i] = remainder;
	for (int j=i; j > -1; j--)
	{
		if (mass[j] == 10)
		{
			cout << "A";
			counter++;
		}
		else if (mass[j] == 11)
		{
			cout << "B";
			counter++;
		}
		else if (mass[j] == 12)
		{
			cout << "C";
			counter++;
		}
		else if (mass[j] == 13)
		{
			cout << "D";
			counter++;
		}
		else if (mass[j] == 14)
		{
			cout << "E";
			counter++;
		}
		else if (mass[j] == 15) 
		{
			cout << "F"; 
			counter++;
		}
		else
			cout << mass[j];
	}
	cout << endl;
	delete[] mass;

}

int CouterABSDEF(int numderconverte)
{
	int counter=0;
	long long remainder = numderconverte; 
	int i = 0;
	int *mass = new int[256];
	do
	{
		numderconverte /= 16;
		remainder %= 16;
		*(mass + i) = remainder;
		i++;
		remainder = numderconverte;
	} while (numderconverte > 16);
	mass[i] = remainder;
	for (int j = i; j > -1; j--)
	{
		if (mass[j] == 10)
			counter++;

		else if (mass[j] == 11)
			counter++;
		
		else if (mass[j] == 12)
			counter++;
	
		else if (mass[j] == 13)
			counter++;

		else if (mass[j] == 14)
			counter++;

		else if (mass[j] == 15)
			counter++;
	}
	delete[] mass;
	return  counter;
}


		         
			    
	    
		
    

void Delets2(int*b, int& m)
{
	
	for (int *p = b; p < b + m; p++)
	{
		for (int *g =p; g< b + m; g++)
		{
			if (CouterABSDEF(*(p)) == CouterABSDEF(*(g+1)))
			{
				for (int i = 1; i <b+m-g -1; ++i)
				{
					*(g + i) = *(g + i+1 );
				}
				--m;
			}
		}
	}
} //m - (b - g)
