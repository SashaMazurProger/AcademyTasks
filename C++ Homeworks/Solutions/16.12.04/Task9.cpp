#include<iostream>
using namespace std;
void main()
{
	int a,sum = 0;
	do
	{
		cout << "Vvedit chyslo:";
		cin >> a;
		sum += a;
	}	while (a != 0);
	cout << "Suma:" << sum;
	system("pause");
}