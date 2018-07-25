#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<iomanip>
using namespace std;
int func(int a, int x,long res)
{
	if (x == 0)
	return 1;
	return res*func(a, x-1, res);
}
void main()
{
	int a, x;
	long res;
	cout << "Chyslo:";
	cin >> a;
	res = a;
	do
	{
		cout << "\nStepin:";
		cin >> x;
	} while (x <= 1);
	cout<<"\nResult:"<<func(a, x,res);
	system("pause");
}
