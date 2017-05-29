#pragma once
#define Re_h

const int N = 20;
const int M = 5;

class Re
{
public:
	Re();
	Re(char*,char*, char*, int, int, int);
	~Re() { }
	void setMark(char*);
	void setNumber(char*);
	void setPlace(char*);
	void setMass(int);
	void setPrice(int);
	void setAllPrice(int);
	void setRe(char*, char*, char*, int, int, int);
	char* getMark();
	char* getNumber();
	char* getPlace();
	int getMass();
	int getPrice();
	int getAllPrice();
	void displayRe();
	void EnterRe();
private:
	char mark[N],number[N],place[N];
	int mass, price, allprice;

};
