#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
void main()
{
	int max, min;
	srand(unsigned (time(NULL)));
	const int size=10;
	int a[size];
	for (int i = 0; i < size; ++i)
	{
		a[i] = rand();
	}
	max=a[0];
	min = a[0];
	for (int i = 0; i < size; ++i)
	{
		if (max<a[i])
			max = a[i];
		if (min>a[i])
			min = a[i];
	}
	cout <<"min: "<< min << "\tmax: " << max;
	system("pause");
}