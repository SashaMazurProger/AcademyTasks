
#include<iostream>
using namespace std;
void main()
{
	int a, b =1 ;
	do
	{
		cout << "Vvedit chyslo a(a>1):";
		cin >> a;
	} while (a<=1);
	while (b<a)
	{
		cout << b<<"\n";
		++b;
	}
	system("pause");
}
