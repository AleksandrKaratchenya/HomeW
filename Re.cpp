
#include <iostream>
#include <string.h>
#include "Re.h"

using namespace std;

Re::Re()
{
	cout << "Create object!";
}

Re::Re(char*mark, char*number, char*place, int mass, int price, int allprice)
{
	setRe(mark, number, place, mass,price,allprice);
}

//Student::~Student()
//{
//    cout << "Destruct object!";
//}

void Re::setMark(char*m)
{
	strcpy(mark, m);
}

void Re:: setNumber(char*n)
{
	strcpy(number, n);
}

void Re::setPlace(char*p)
{
	strcpy(place, p);
}

void Re::setMass(int m)
{
	mass = m;
}
void Re::setPrice(int p)
{
	price = p;
}
void Re::setAllPrice(int ap)
{
   allprice = ap;
}

char* Re::getMark()
{
	return mark;
}

char* Re::getNumber()
{
	return number;
}

char* Re::getPlace()
{
	return place;
}

int Re::getMass()
{
	return mass;
}
int Re::getPrice()
{
	return price;
}
int Re::getAllPrice()
{
	return allprice;
}


void Re::setRe(char* m, char*n, char*p, int mas, int pr, int apr)
{
	setMark(m);
	 setNumber(n);
	 setPlace(p);
	 setMass( mas);
	 setPrice( pr);
     setAllPrice( apr);
}

void Re::displayRe()
{
	cout << mark << endl; cout << number << endl;cout << place << endl;
	//cout.precision(4);
	cout << mass << " " << price << " " << allprice << "\n" << endl;
}
void Re::EnterRe()
{
	const int N = 256;
	char mark[N] = "", number[N] = "",  place[N] = "";
	cout << "Enter mark:";
	cin.ignore();
	cin.getline(mark, N, '\n');
	cout << "Enter number:";
	cin.getline(number, N, '\n');
	cout << "Enter place:";
	cin.getline(place, N, '\n');
	int mass, price, allprice;
	cout << "Enter  mass:" << endl;
	cin >> mass;
	cout << "Enter  price:" << endl;
	cin >> price;
	cout << "Enter  allprice:" << endl;
	cin >> allprice;
	this->setRe(mark, number, place, mass,price,allprice);
}
