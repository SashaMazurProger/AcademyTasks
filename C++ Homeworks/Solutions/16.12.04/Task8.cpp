#include<iostream>
using namespace std;
void main()
{
	int a, b,c,sum = 0;
	cout << "Vvedit pochatok diapazonu:";
	cin >> a;
	c = a+1;
	do
	{
		cout << "Vvedit kinets diapazonu:";
		cin >> b;
	} while (b <= a + 1);
	while (c<b)
	{
		sum += c;
		++c;
	}
	cout << "Suma:" << sum;
	system("pause");
}