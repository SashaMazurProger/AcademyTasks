#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<string.h>
using namespace std;

class Complex
{
	double a;
	double b;
public:
	Complex()
	{
	}
    Complex(double x,double y)
	{
		a = x;
		b = y;
	}
	void SetA(double x)
	{
		a = x;
	}
	double GetA()
	{
		return a;
	}
	void SetB(double x)
	{
		b = x;
	}
	double GetB()
	{
		return b;
	}
     Complex operator +( Complex m)
	{
		Complex tmp(a + m.a, b + m.b);
		return tmp;
	}
     Complex operator-( Complex m)
	{
		Complex tmp(a - m.a, b - m.b);
		return tmp;
	}
	 Complex operator*( Complex m)
	{
		Complex tmp(a*m.a + a*m.b, b*m.a + b*m.b);
		return tmp;
	}
	 Complex operator/( Complex m)
	{
		Complex tmp((a + b) / (m.a + m.b),0);
		return tmp;
	}
    void Print(Complex n)
	{
		cout <<"------Rezultat: "<< n.a<<" + "<<n.b;
	}
};

int main()
{
	double tmpA,tmpB;
	int key;
	Complex firstNumb;
	Complex secondNumb;
	do
	{
		cout << "\n--------------------------"
			<< "\n     \\\\\\Menu///"
			<< "\n1 - Vkazaty chysla"
			<< "\n2 - Dodaty k-ni chysla"
			<< "\n3 - Znayty riznytsyu"
			<< "\n4 - Pomnozhyty"
			<< "\n5 - Podilyty"
			<< "\n\n0 - Vyhid"
			<< "\n--------------------------\n";
		do
		{
			cout << "\nZrobit vash vybir";
			cin >> key;
		} while (key<0 || key>5);
		switch (key)
		{
		case 1:
			cout << "\nPershe chyslo a+ib"
				<< "\n\na=";
			cin >> tmpA;
			cout << "\n\nib=";
			cin >> tmpB;
		    firstNumb.SetA(tmpA);
			firstNumb.SetB(tmpB);

			cout << "\nDruhe chyslo s+ih"
				<< "\n\ns=";
			cin >> tmpA;
			cout << "\n\nih=";
			cin >> tmpB;
			secondNumb.SetA(tmpA);
			secondNumb.SetB(tmpB);
			break;
		case 2:
			firstNumb.Print(firstNumb + secondNumb);
			break;
		case 3:
			firstNumb.Print(firstNumb - secondNumb);
			break;
		case 4:
			firstNumb.Print(firstNumb * secondNumb);
			break;
		case 5:
			firstNumb.Print(firstNumb / secondNumb);
			break;
		}
	} while (key);
	system("pause");
	return 0;
}

