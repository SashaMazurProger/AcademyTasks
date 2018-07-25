#include<iostream>
using namespace std;
void main()
{
	int a,b=1;
	do
	{
		cout << "Vvedit chyslo(1<=a<=9):";
		cin >> a;
	}	while (!(a >=1&&a<=9));
	switch (a)
	{
	case 1:
		while (b < 10)
		{
			cout << a << " x " << b << "=" << a*b << "\n";
			++b;
		}
		break;
	case 2:
		while (b < 10)
		{
			cout << a << " x " << b << "=" << a*b << "\n";
			++b;
		}
		break;
	case 3:
		while (b < 10)
		{
			cout << a << " x " << b << "=" << a*b << "\n";
			++b;
		}
		break;
	case 4:
		while (b < 10)
		{
			cout << a << " x " << b << "=" << a*b << "\n";
			++b;
		}
		break;
	case 5:
		while (b < 10)
		{
			cout << a << " x " << b << "=" << a*b << "\n";
			++b;
		}
		break;
	case 6:
		while (b < 10)
		{
			cout << a << " x " << b << "=" << a*b << "\n";
			++b;
		}
		break;
	case 7:
		while (b < 10)
		{
			cout << a << " x " << b << "=" << a*b << "\n";
			++b;
		}
		break;
	case 8:
		while (b < 10)
		{
			cout << a << " x " << b << "=" << a*b << "\n";
			++b;
		}
		break;
	case 9:
		while (b < 10)
		{
			cout << a << " x " << b << "=" << a*b << "\n";
			++b;
		}
		break;
	}
	system("pause");
}