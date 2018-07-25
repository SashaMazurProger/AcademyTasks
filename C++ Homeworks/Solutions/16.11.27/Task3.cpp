#include<iostream>
using namespace std;
void Symbol();
void Symbol2();
void main()
{
	int b = 0;
	Symbol();
	cout << "\n\n\t\t\t   PRODAM\n\n"
		<< "\tPAPUHU\n"
		<< "\tVyd: Ara(Apapa)\n"
		<< "\tVik: 4 roky\n"
		<< "\tOsoblyvosti: bahato hovoryt, znaye tablycyu mnozhennia\n"
		<< "\tTsina: 300 grn\n\n"
		<< "\tTel.:123 45 67(kot)\n\n";
	Symbol2();
	cout << "\n\t|  1  |\t|  1  |\n\t|  2  |\t|  2  |\n\t|  3  |\t|  3  |\n\t|  4  |\t|  4  |\n"
		<<"\t|  5  |\t|  5  |\n\t|  6  |\t|  6  |\n\t|__7__|\t|__7__|\n";
	system("pause");
}
void Symbol()
{
	int a = 0;
	while (a < 65)
	{
		cout << "_";
		a++;
	}
}
void Symbol2()
{
	int b = 0;
	while (b < 65)
	{
		cout << "^";
		b++;
	}
}