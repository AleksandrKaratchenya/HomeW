#include <iostream>
#include <cstring>

using namespace std;

char numToChar(int);
void intPartToHex(int, int, char*, int&);
void doublePartToHex(double, int, char*, int, int);
void reverse(char*);

int main()
{
	double num;
	cout << "Enter a number : ";
	cin >> num;
	bool isNeg = false;
	if (num < 0)
	{
		num = -num;
		isNeg = true;
	}
	int base;
	cout << "Enter a base of the system : ";
	cin >> base;
	cout << "Enter a number of digits after \",\": ";
	int eps;
	cin >> eps;
	int pos = 0;
	char strNum[64] = { '0' };
	intPartToHex((int)num, base, strNum, pos);
	strNum[pos++] = ',';
	doublePartToHex(num - (int)num, base, strNum, pos, eps);
	if (isNeg)
		cout << "Your number on new base is : -" << strNum << endl;
	else
		cout << "Your number on new base is : " << strNum << endl;
	system("pause");
	return 0;
}

char numToChar(int num)
{
	if (num >= 0 && num <= 9)
		return 48 + num;
	else if (num >= 10 && num <= 35)
		return 55 + num;
	return -1;
}

void intPartToHex(int num, int base, char *strNum, int &i)
{
	int numInt = (int)num;
	int rem = numInt % base;
	numInt /= base;
	while (numInt)
	{
		strNum[i] = numToChar(rem);
		rem = numInt % base;
		numInt /= base;
		i++;
	}
	strNum[i++] = numToChar(rem);
	reverse(strNum);
}

void doublePartToHex(double num, int base, char *strNum, int pos, int eps)
{
	int iter = 0;
	double doubleNum = num;
	while (iter < eps) {
		doubleNum = doubleNum * base;
		int intNum = (int)(doubleNum);
		strNum[pos++] = numToChar(intNum);
		doubleNum -= (int)doubleNum;
		iter++;
	}
	strNum[pos] = '\0';
}

void reverse(char *strNum)
{
	int len = strlen(strNum);
	for (int i = 0; i < len / 2; i++)
	{
		char c = strNum[i];
		strNum[i] = strNum[len - i - 1];
		strNum[len - i - 1] = c;
	}
}
