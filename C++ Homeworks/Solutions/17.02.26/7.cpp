#include<iostream>
using namespace std;
void Calc(float *a, float *b, float *res, int d)
{
	if (d == 1)
		*res = *a + *b;
	else if (d == 2)
		*res = *a - *b;
	else if (d == 3)
		*res = *a**b;
	else *res = *a / *b;
}
void main()
{
	int d;
	float a, b, res;
	do
	{
		cout << "1 chyslo:";
		cin >> a;
		cout << "2 chyslo:";
		cin >> b;
		do
		{
			cout << "-------------------";
			cout << "\nVyberit diyu:"
				<< "\n1....+"
				<< "\n2....-"
				<< "\n3....*"
				<< "\n4..../"
				<< "\n0....exit\n";
			cout << "-------------------";
			cin >> d;
		} while ((b == 0 && d == 4) || (d < 0 || d>4));
		if (d != 0)
		{
			Calc(&a, &b, &res, d);
			cout << "Result:" << res;
			do
			{
				cout << "\nProdovzshymo? 1-Yes 0-No\n";
				cin >> d;
			} while (d != 0 && d != 1);
		}
	} while (d != 0);
	system("pause");
}
