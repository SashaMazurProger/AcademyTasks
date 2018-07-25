#include<iostream>
using namespace std;
void main()
{
	int a, b =1 ;
	do
	{
		cout << "Vvedit chyslo a(1<=a<=9):";
		cin >> a;
	} while (!(a >= 1 && a <= 9));
	while (b<10)
	{
		cout << a<<" x "<<b<<" = "<<a*b<<"\n";
		++b;
	}
	system("pause");
}
