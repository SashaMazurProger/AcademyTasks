#include<iostream>
#include<math.h>
using namespace std;

class Equation
{
public:
	Equation()
	{
	}
	virtual void Roots() = 0;
};
class LineEquation:public Equation
{
	double x, a, b;
public:
	LineEquation(double a,double b)
	{
		this->a = a;
		this->b = b;
	}
	virtual void Roots()
	{
		if (a == 0)
		{
			cout << "\nRivnyannya ne maye koreniv";
		}
		else if (a == 0 && b == 0)
		{
			cout << "\nRivnyannya maye bezlich koreniv";
		}
		else
		{
			x = b / a;
			cout << "\nx=" << x;
		}
	}
};
class SquareEquation :public Equation
{
	double x1,x2, a, b,c,D;
public:
	SquareEquation(double a, double b,double c)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		D = b*b - (4 * a*c);
	}
	virtual void Roots()
	{
		cout << "\nD=" << D;
		if (a != 0 && b != 0 && c != 0)
		{
			if (D < 0)
				cout << "\nRivnyannya ne maye koreniv";
			else if (D == 0)
			{
				x1 = x2 = -1 * (b / (2 * a));
				cout << "\nx1=x2=" << x1;
			}
			else
			{
				x1 = (-1 * b + sqrt(D)) / 2 * a;
				x2 = (-1 * b - sqrt(D)) / 2 * a;
				cout << "\nx1=" << x1
					<< "\nx2=" << x2;
			}
		}
		else
		{
			cout << "\nRivnyannya nepovne";
		}
	}
};
int main()
{
	LineEquation lEqua(2, 8);
	SquareEquation sEqua(2, 8, -16);
	cout << "\n2x=8";
	lEqua.Roots();
	cout << "\n------------------";
	cout << "\n2x*x+8x-16=0";
	sEqua.Roots();
	system("pause");
	return 0;
}





