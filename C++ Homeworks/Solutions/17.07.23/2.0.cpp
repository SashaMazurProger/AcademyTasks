#include<iostream>
#include<math.h>
#include<fstream>
using namespace std;

class Shape
{
protected:
	int x, y;
public:
	Shape()
	{}
	Shape(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	virtual void Save()
	{

	}
	void Load()
	{
		char s[100];
		ifstream ifs("data.txt", ios::in);
		if (!ifs)
		{
			cout << "\nFile didn't open";
		}
		ifs >> s;
		cout << "Load:" << s;
	}
	virtual void Show()
	{
		cout << "\nx:" << x << "\ny:" << y;
	}
};
class Square :public Shape
{
	double l;
public:
	Square(double x, double y, double l) : Shape(x, y)
	{
		this->l = l;
	}
	Square()
	{
	}
	virtual void Show()
	{
		cout << "\nSquare"
			<< "\nx:" << x
			<< "\ny:" << y
			<< "\nLenght side:" << l;
	}
};
class Rectangle :public Shape
{
protected:
	double  a, b;
public:
	Rectangle(double a, double b, double x, double y)
		:Shape(x, y)
	{
		this->a = a;
		this->b = b;
	}
	virtual void Show()
	{
		cout << "\nRectangle"
			<< "\nx:" << x
			<< "\ny:" << y
			<< "\nLenght side a:" << a
			<< "\nLenght side b:" << b;
	}
};
class Circle :public Shape
{
	double r;
public:
	Circle(double x, double y, double r) : Shape(x, y)
	{
		this->r = r;
	}
	virtual void Show()
	{
		cout << "\nCircle"
			<< "\nx:" << x
			<< "\ny:" << y
			<< "\nRadius:" << r;
	}
	virtual void Save()
	{
		ofstream ofs("data.txt", ios::out | ios::app);
		if (!ofs)
		{
			cout << "\nFile didn't open";
			return;
		}
		ofs << "Circle:x=" << x << " y=" << y << " r=" << r << "\n";
		ofs.close();
	}
};
class Ellipse :public Rectangle
{
public:
	Ellipse(double a, double b, double x, double y)
		:Rectangle(a, b, x, y)
	{
	}
	virtual void Show()
	{
		cout << "\nEllipse"
			<< "\nx (rectangle) :" << x
			<< "\ny (rectangle):" << y
			<< "\nLenght side a (rectangle):" << a
			<< "\nLenght side b (rectangle):" << b;
	}
	virtual void Save()
	{
		ofstream ofs("data.txt", ios::out | ios::app);
		if (!ofs)
		{
			cout << "\nFile didn't open";
			return;
		}
		ofs << "Ellipse:x=" << x << " y=" << y << " a=" << a << " b=" << b << "\n";
		ofs.close();
	}
};
void main()
{
	char str[100];
	Shape *arr[4];
	Shape arr2[4];
	Square square2;
	arr[0] = new Square(4, 5, 8);
	arr[1] = new Rectangle(7, 8, 1, 2);
	arr[2] = new Ellipse(4, 3, 0, 1);
	arr[3] = new Circle(1, 2, 5);
	arr[4] = new Square(4, 5, 8);
	arr[5] = new Rectangle(7, 8, 1, 2);
	arr[6] = new Ellipse(4, 3, 0, 1);
	arr[7] = new Circle(1, 2, 5);
	arr[8] = new Square(4, 5, 8);
	arr[9] = new Rectangle(7, 8, 1, 2);
	arr[10] = new Ellipse(4, 3, 0, 1);

	ofstream ofs("data.txt", ios::out | ios::app);
	if (!ofs)
	{
		cout << "\nFile didn't open";
		return;
	}
	for (int i = 0; i < 10; ++i)
	{
		arr[i]->Save();
	}

	cout << "\n\nLoad:\n";

	ifstream ifs("data.txt", ios::in);
	if (!ifs)
	{
		cout << "\nFile didn't open";
	}
	Shape *shapes[10];
	ifs >> shapes;

	for (int i = 0; i < 10; ++i)
	{
		cout << shapes[i]->Show;
	}

	system("pause");
	return;
}





