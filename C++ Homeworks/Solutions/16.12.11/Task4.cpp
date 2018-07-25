#include<iostream>
using namespace std;
void main()
{
	int a,b=0;
	cout << "Vvedit tsile chyslo:";
	cin >> a;
	while(a>0)
	{
		if (a %10 != 3&&a % 10 != 6)
		{
			b *= 10;
			b += a % 10;
		}
		a /= 10;
	}
	while (b > 0)
	{
		cout << b % 10;
		b /= 10;
	}
	system("pause");
}
