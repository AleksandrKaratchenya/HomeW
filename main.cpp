#include <iostream> 
#include "Re.h"
#include <io.h>
#include <fstream>
#include <cstring>
using namespace std;
void InitFile(char*);
void DisplayFile(char*);
void AddToEndFile(char*);
void ChangeFile(char*);
void RemoveFromFile(char*);
void InitNumber(long&);
void SystemFun();
void InitNameFile(char*);
//void SortingFile(char*);
int Menu();
//using namespace std;

//Re initRe();
//Re* initArray(int);
//void displayArray(Re*, int);
//void sortPlace(Re* res, int n);
//void swap(Re&, Re&);
//void displayChoise(Re*, int n, char* mark, int maxmass, int  minmass);
int main()
{
	char fileName[N] = "List.bin";
	enum { Init = 1, Create, Display, Add, Change, Remove, Sort, Exit };
	while (true)
	{
		int Key = Menu();
		if (Key == Exit)
			return 0;
		system("cls");
		switch (Key)
		{
		case Init:
			InitNameFile(fileName);
			SystemFun();
			break;
		case Create:
			InitFile(fileName);
			SystemFun();
			break;
		case Display:
			DisplayFile(fileName);
			SystemFun();
			break;
		case Add:
			AddToEndFile(fileName);
			SystemFun();
			break;
		case Change:
			ChangeFile(fileName);
			SystemFun();
			break;
		case Remove:
			RemoveFromFile(fileName);
			SystemFun();
			break;
		/*case Sort:
			SortingFile(fileName);
			SystemFun();
			break;*/
		default:
			cout << "\nIncorrect input! Try again!";
			SystemFun();
		}
	}
}

void InitFile(char* fileName)
{
	ofstream streamOut;
	streamOut.open(fileName, ios::binary);
	if (!streamOut.is_open())
	{
		cout << "\nCan't open file to write!";
		SystemFun();
		return;
	}
	int bufSize = sizeof(Re);
	//Student* man = new Student;
	Re man;
	char Ok = 'y';
	while (Ok == 'y')
	{
		//man->EnterStudent();
		man.EnterRe();//
					  //streamOut.write((char*)man,bufSize);
		streamOut.write((char*)&man, bufSize);
		cout << " If do you want to continue, press 'y' :";
		cin >> Ok;
	}
	//delete man;
	streamOut.close();
}

void AddToEndFile(char* fileName)
{
	ofstream streamOut(fileName, ios::app | ios::binary);
	if (!streamOut.is_open())
	{
		cout << "Can't open file to write!";
		SystemFun();
		return;
	}
	int bufSize = sizeof(Re);
	Re man;
	char Ok = 'y';
	while (Ok == 'y')
	{
		man.EnterRe();
		streamOut.write((char*)&man, bufSize);
		cout << " If do you want to continue, press 'y' : ";
		cin >> Ok;
	}
	streamOut.close();
}
void ChangeFile(char* fileName)
{
	fstream streamInOut(fileName, ios::in | ios::out | ios::binary);
	if (!streamInOut)
	{
		cout << "Can't open file to read and write!";
		SystemFun();
		return;
	}
	int bufSize = sizeof(Re);
	Re man;
	long Position;
	InitNumber(Position);
	streamInOut.seekp((Position - 1) * bufSize, ios::beg);
	man.EnterRe();
	streamInOut.write((char*)&man, bufSize);
	streamInOut.close();
}
void RemoveFromFile(char* fileName)
{
	fstream streamInOut(fileName, ios::in | ios::out | ios::binary);
	if (!streamInOut.is_open())
	{
		cout << "Can't open file to read and write!";
		SystemFun();
		return;
	}
	streamInOut.seekp(0, ios::end);//*
	long N = streamInOut.tellp();//*
	int bufSize = sizeof(Re);
	Re man;
	long Position;
	InitNumber(Position);
	streamInOut.seekp(Position * bufSize, ios::beg);
	while (streamInOut.read((char*)&man, bufSize))
	{
		//streamInOut.seekp( (Position - 1 + i ) * bufSize, ios::beg);
		//streamInOut.write((char*)&man, bufSize);
		//streamInOut.seekp( bufSize, ios::cur);
		//i++;
		streamInOut.seekp(-2 * bufSize, ios::cur);
		streamInOut.write((char*)&man, bufSize);
		streamInOut.seekp(bufSize, ios::cur);
	}
	streamInOut.close();
	int DiskriptorFile = open(fileName, 2);//*
	chsize(DiskriptorFile, N - bufSize);//*
	close(DiskriptorFile);//*
}



void DisplayFile(char* fileName)
{
	ifstream streamIn(fileName, ios::binary);
	if (!streamIn.is_open())
	{
		cout << "Can't open file to read!";
		SystemFun();
		return;
	}
	int bufSize = sizeof(Re);
	Re* man = new Re;
	while (streamIn.read((char*)man, bufSize))
	{
		man->displayRe();
	}
	streamIn.close();
}

void InitNumber(long& n)
{
	cout << "Enter the number of record:" << endl;
	cin >> n;
	system("cls");
}

void SystemFun()
{
	cout << endl;
	system("pause");
	system("cls");
}

void InitNameFile(char* fileName)
{
	cout << "Enter the name of file: " << endl;
	cin.ignore();
	cin.getline(fileName, 256, '\n');
	system("cls");
}

int Menu()
{
	int k;
	cout << "\n Enter the number - the mode of operations with file:"
		"\n 1 - INITIALIZATION THE NAME OF FILE"
		"\n 2 - FORMATION OF THE FILE"
		"\n 3 - VIEWING OF CONTENTS OF THE FILE"
		"\n 4 - ADD AN ELEMENT TO AND OF FILE"
		"\n 5 - CHANGE THE ELEMENT IN THE FILE"
		"\n 6 - REMOVE THE ELEMENT IN THE FILE"
		"\n 8 - EXIT\n";
	cin >> k;
	return k;
}
	/*int n;
	cout << "\nEnter the number of Re:";
	cin >> n;
	system("cls");
	Re* res = initArray(n);
	if (!res)
	{
		cout << "\nDynamic array doesn't exist!\n";
		system("pause");
		return 0;
	}
	cout << "\nThe list of Re:\n";
	displayArray(res, n);
	char mark[N];
	cin.ignore();
	cout << "SortbyMark" << endl;
	cout << "\nEnter the mark:";
	cin.getline(mark, N, '\n');
	int minmass, maxmass;
	cout << "\nEnter the minmass:";
	cin >> minmass;
	cout << "\nEnter the maxmass:";
	cin >>maxmass;
	cout << "\n\nThe list of choise-Re:\n";
	displayChoise(res, n, mark, minmass, maxmass);
	cout << endl;
	cout << "\n\nThe sorting list of Re: \n";
	sortPlace(res, n);
	displayArray(res, n);
	delete[] res;*/


Re initRe()
{
	char  mark[N] = "", number[N] = "", place[N] = "";
	cout << "\nEnter Mark:";
	cin.ignore();
	cin.get(mark, N, '\n');
	cout << "Enter number:";
	cin.ignore();
	cin.get(number, N, '\n');
	cout << "Enter place:";
	cin.ignore();
	cin.get(place, N, '\n');
	cout << "Enter mass , price, allprice" << endl;
	int mass, price, allprice;
	cin.ignore();
	cin >> mass;
	cin >> price;
	cin >> allprice;
	Re re;
	//    Student student(firstName, lastName, fuculty, marks);
	re.setRe(mark, number, place, mass,price,allprice);
	return re;
}

Re* initArray(int n)
{
	Re* res = new Re[n];
	//    if (!array)
	//        return NULL;
	for (int i = 0; i < n; i++)
	{
		cout << "\nEnter the information about " << (i + 1) << " Re\n";
		res[i] = initRe();
	}
	return res  ;
}

void displayArray(Re* res, int n)
{
	for (int i = 0; i < n; i++)
		res[i].displayRe();
	     cout << endl;
		 cout << endl;
}

void displayChoise(Re* res, int n, char* mark, int minmass, int  maxmass)
{
	for (int i = 0; i < n; i++)
		if (!strcmp(res[i].getMark(), mark) && res[i].getMass()
			<= maxmass  &&  res[i].getMass() >=minmass)
			res[i].displayRe();
}

void sortPlace(Re* res, int n)
{
	for (int i = 0; i <= n; i++)
		for (int j = n - 1; j > i; j--)
			if (strcmp(res[j].getPlace(), res[j - 1].getPlace()) < 0)
				swap(res[j], res[j - 1]);
}

void swap(Re &a,Re &b)
{
	Re help = a;
	a = b;
	b = help;
}