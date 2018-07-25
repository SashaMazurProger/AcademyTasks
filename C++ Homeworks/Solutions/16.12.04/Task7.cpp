#include<iostream>
using namespace std;
void main()
{
	int a, b,c ;
	cout << "Vvedit pochatok diapazonu:";
	cin >> a;
	c = a+1;
	do
	{
		cout << "Vvedit kinets diapazonu:";
		cin >> b;
	} while (b<=a+1);
	cout << "\tParni\n";
	while (a<c&&c<b)
	{
		if (c % 2 == 0)
		{
			cout << c<< "\n";
		}
		++c;
	}
	c = a + 1;
	cout << "\n\tNeparni\n";
	while (a<c&&c<b)
	{
		if (!(c % 2 ==0 ))
		{
			cout << c << "\n";
		}
		++c;
	}
	c = a + 1;
	cout << "\n\tKratni 7\n";
	while (a<c&&c<b)
	{
		if (c % 7 == 0)
		{
			cout << c << "\n";
		}
		++c;
	}
	system("pause");
}
