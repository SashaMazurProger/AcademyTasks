#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
void main()
{
	int minx, maxy, c=0;
	double max, min,firstm=0,secm,summ=0,sumfs=0,dobmm=1,dobp=1,d;
	srand(time(NULL));
	const int size=10;
	double a[size];
	for (int i = 0; i < size; ++i)
	{
		a[i] = -10 + rand() % 20;
		d=rand()%1000;
		a[i] += d/1000;
		cout << a[i]<<"\n"<<endl;
	}
	max = a[0];
	min = a[0];
	for ( int i = 0; i < size; ++i)
	{
		if (max < a[i])
		{
			max = a[i];
			maxy= i;
		}
		if (min > a[i])
		{
			min = a[i];
			minx= i;
		}
		if (a[i] < 0)
			summ += a[i];
		if ((i+1)% 2 == 0)
			dobp *= a[i];
		if (c != -1&&a[i]<0)
		{
			firstm = i;
			--c;
		}
		if (a[i]<0)
			secm = i;
	}
	if (minx < maxy)
	{
		for (int i = minx + 1; i < maxy; ++i)
			dobmm *= a[i];
	}
	if (minx > maxy)
	{
		for (int i = maxy + 1; i < minx; ++i)
			dobmm *= a[i];
	}
	for (int i = firstm + 1; i < secm; ++i)
		sumfs += a[i];
	cout << "1................." << summ
		<< "\n2................." << dobmm
		<< "\n3................." << dobp
		<< "\n4................." << sumfs<<endl;
	system("pause");
}