#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
void main()
{
	const int size1 = 10, size2 = 5;
	int a[size1], b[size2], c[size2];
	srand(unsigned(time(NULL)));
	for (int i = 0; i < size1; ++i)
	{
		a[i] = rand();
		cout << a[i] << "\n" << endl;
	}
	cout << "\n___________________" << endl;
	for (int i = 0; i < size2; ++i)
	{
		b[i] = a[i];
		cout << b[i] << "\n" << endl;
	}
	cout << "\n___________________" << endl;
	for (int i = 0, x = 5; i < size2&&x < size1; ++i, ++x)
	{
		c[i] = a[x];
		cout << c[i] << "\n" << endl;
	}
	system("pause");
}