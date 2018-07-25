#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<iomanip>
using namespace std;
int func(int a, int x,int c)
{
	if (c==x)
	return 0;
	return c+func(a, x,c+1);
}
void main()
{
	int a, b, c;
	cout << "Vvedit pochatok diapazonu:";
	cin >> a;
	c = a + 1;
	do
	{
		cout << "Vvedit kinets diapazonu:";
		cin >> b;
	} while (b <= a + 1);
	cout << "Suma:" << func(a,b,c);
	system("pause");
}