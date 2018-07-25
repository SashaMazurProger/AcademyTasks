#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<string.h>
using namespace std;

class Drib
{
	int x;
	int y;
public:
	void SetX(int a)
	{
		x = a;
	}
	void SetY(int b)
	{
		y = b;
	}
	int GetX()
	{
		return x;
	}
	int GetY()
	{
		return y;
	}
	void Suma(Drib a, Drib b)
	{
		cout << "\n" << a.x << "/" << a.y << "+" << b.x << "/" << b.y
			<< "=" << (a.x*b.y) + (b.x*a.y) << "/" << a.y*b.y;
	}
	void Rizn(Drib a, Drib b)
	{
		cout << "\n" << a.x << "/" << a.y << "-" << b.x << "/" << b.y
			<< "=" << (a.x*b.y) - (b.x*a.y) << "/" << a.y*b.y;
	}
	void Dob(Drib a, Drib b)
	{
		cout << "\n" << a.x << "/" << a.y << "*" << b.x << "/" << b.y
			<< "=" << (a.x*b.x) << "/" << a.y*b.y;
	}
	void Chastka(Drib a, Drib b)
	{
		cout << "\n" << a.x << "/" << a.y << " / " << b.x << "/" << b.y
			<< "=" << (a.x*b.y)<< "/" << a.y*b.x;
	}
};


void main()
{
	Drib a;
	Drib b;

	a.SetX(1);
	a.SetY(2);

	b.SetX(3);
	b.SetY(4);

	a.Suma(a,b);
	a.Rizn(a, b);
	a.Dob(a, b);
	a.Chastka(a, b);
	system("pause");
}



