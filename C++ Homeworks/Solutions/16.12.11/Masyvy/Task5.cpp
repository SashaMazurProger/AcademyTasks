#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
void main()
{
	const int size= 10;
	int a[size], b[size], c[size];
	srand(unsigned(time(NULL)));
	for (int i = 0; i < size; ++i)
	{
		a[i] = rand()%10;
		b[i] = rand() % 10;
		c[i] = a[i] + b[i];
		cout << a[i] << " + " << b[i] << " = " << c[i] << "\n" << endl;
	}
	system("pause");
}