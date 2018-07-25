#include<iostream>
#include<iomanip>
using namespace std;

struct Complex
{
	double a, b;
};
void Print(Complex x)
{
	cout << "\nres:" <<x.a<<" + "<<x.b;
}
void Past(Complex&n, Complex&m)
{
		cout << "\nPershe chyslo a+ib"
			<< "\n\na=";
		cin >> n.a;
		cout << "\n\nib=";
		cin >> n.b;

		cout << "\nDruhe chyslo s+ih"
			<< "\n\ns=";
		cin >> m.a;
		cout << "\n\nih=";
		cin >> m.b;
}
void Suma(Complex n, Complex m)
{
	Complex tmp;
	tmp.a = n.a+m.a;
	tmp.b=n.b+m.b;
	Print(tmp);
}
void Riznytsya(Complex n, Complex m)
{
	Complex tmp;
	tmp.a = n.a - m.a;
	tmp.b = n.b - m.b;
	Print(tmp);
}
void Dobutok(Complex n, Complex m)
{
	Complex tmp;
	tmp.a = n.a*m.a + n.a*m.b;
	tmp.b = n.b*m.a + n.b*m.b;
	Print(tmp);
}
void Chastka(Complex n, Complex m)
{
	Complex tmp;
	tmp.a = (n.a + n.b) / (m.a + m.b);
	Print(tmp);
}
int main()
{
	int key;
	Complex firstNumb = {};
	Complex secondNumb = {};
	do
	{
		cout << "\n--------------------------"
			<< "\n     \\\\\\Menu///"
			<< "\n1 - Vkazaty chysla"
			<< "\n2 - Dodaty k-ni chysla"
			<< "\n3 - Znayty riznytsyu"
			<< "\n4 - Pomnozhyty"
			<< "\n5 - Podilyty"
			<<"\n\n0 - Vyhid"
			<<"\n--------------------------\n";
		do
		{
			cout << "\nZrobit vash vybir";
			cin >> key;
		} while (key<0||key>5);
		switch (key)
		{
		case 1:
			Past(firstNumb, secondNumb);
			break;
		case 2:
			Suma(firstNumb, secondNumb);
			break;
		case 3:
			Riznytsya(firstNumb, secondNumb);
			break;
		case 4:
			Dobutok(firstNumb, secondNumb);
			break;
		case 5:
			Chastka(firstNumb, secondNumb);
			break;
		}
	} while (key);
	system("pause");
	return 0;
}



