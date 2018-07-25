#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<string.h>
#include<thread>
using namespace std;

class Kruh
{
	double radius;
public:
	Kruh()
	{
	}
	void SetRadius(double a)
	{
		radius = a;;
	}
	double GetRadius()
	{
		return radius;
	}
};
class Kvadrat
{
	double dovzhyna;
public:
	Kvadrat()
	{
	}
	void SetDov(double a)
	{
		dovzhyna = a;;
	}
	double GetDov()
	{
		return dovzhyna;
	}
};
class Figura :public Kruh, public Kvadrat
{
public:
	Figura(double r, double l)
	{
		SetDov(l);
		SetRadius(r);
	}
	void Show()
	{
		cout << "\nStorona kvadrata:" << GetDov();
		cout << "\nDiametr kruha:" << GetRadius() * 2;
		if (GetRadius() > GetDov() / 2)
		{
			cout << "\nPomylka!!!Diametr kruha bilshe storony kvadrata";
		}
		else if (GetRadius() < GetDov() / 2)
		{
			cout << "\nPomylka!!!Diametr kruha menshyy storony kvadrata";
		}
		else
		{
			cout << "\nDiametr==Storona";
		}
	}
};
int main()
{
	Figura f1 = Figura(2, 4);
	Figura f2 = Figura(2.5, 6);
	f1.Show();
	cout << "\n-----------------------";
	f2.Show();
	system("pause");
	return 0;
}





