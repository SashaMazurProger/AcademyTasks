
#include<iostream>
using namespace std;
void main()
{
	int a, y = 20 ;
	long long sum;
	do
	{
		cout << "Vvedit chyslo a(1<=a<=20):";
		cin >> a;
	} while (!(a >= 1 && a <= 20));
		sum = a;
	while (a<20)
	{
		++a;
		sum *= a;
	}
	cout << "Dobutok:" << sum;
	system("pause");
}
