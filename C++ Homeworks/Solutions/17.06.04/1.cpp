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
	void operator+( Drib b)
	{
		cout << "\n" << x << "/" << y << "+" << b.x << "/" << b.y
			<< "=" << (x*b.y) + (b.x*y) << "/" << y*b.y;
	}
	void operator-( Drib b)
	{
		cout << "\n" << x << "/" << y << "-" << b.x << "/" << b.y
			<< "=" << (x*b.y) - (b.x*y) << "/" << y*b.y;
	}
	void operator*( Drib b)
	{
		cout << "\n" << x << "/" << y << "*" << b.x << "/" << b.y
			<< "=" << (x*b.x) << "/" << y*b.y;
	}
	void operator/(Drib b)
	{
		cout << "\n" << x << "/" << y << " / " << b.x << "/" << b.y
			<< "=" << (x*b.y) << "/" << y*b.x;
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

	a + b;
	a - b;
	a * b;
	a / b;
	system("pause");
}