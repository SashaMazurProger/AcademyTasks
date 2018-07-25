#include<iostream>
using namespace std;
void main()
{
	int a,b=500,sum=0;
	do
	{
		cout << "Vvedit chyslo(<500):";
		cin >> a;
	} while (a >= 500);
	
	while (a < 500)
	{
		sum += a;
		++a;
	}
	cout << "Suma:"<<sum;
	system("pause");
}
