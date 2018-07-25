#include<iostream>
using namespace std;
void main()
{
	int a, b, c,sum=0;
	for (int i = 101; i < 999; ++i)
	{
		a = i / 100;
		b = (i / 10) % 10;
		c = i % 10;
		if (a == b && a == c && b == c)continue;
		if (a == b || a == c||b==c )
			++sum;
	}
	cout << sum;
	system("pause");
}