#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
void func(int arr[],int size)
{
	int countMin = 0, countPlus=0,count0=0;
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] < 0)
		{
			++countMin;
		}
		if (arr[i] == 0)
		{
			++count0;
		}
		if (arr[i] > 0)
		{
			++countPlus;
		}
	}
	cout << "\nDodatnih:" << countPlus;
	cout << "\nVid'yemnyh:" << countMin;
	cout << "\nNulevyh:" << count0;
}
void main()
{
	int max, min;
	srand(unsigned(time(NULL)));
	const int size = 10;
	int ar[size];
	for (int i = 0; i < size; ++i)
	{
		ar[i] =-5+ rand()%10;
		cout << ar[i]<<"  ";
	}
	func(ar, size);
	system("pause");
}