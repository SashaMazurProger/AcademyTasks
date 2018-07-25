#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
void func(int arr[],int size)
{
	int sum = 0;
	for (int i = 0; i < size; ++i)
	{
		sum+=arr[i];
	}
	cout << "\nSer.aryph.=" << (float)sum / size;
}
void main()
{
	int max, min;
	srand(unsigned(time(NULL)));
	const int size = 5;
	int ar[size];
	for (int i = 0; i < size; ++i)
	{
		ar[i] = rand()%10;
		cout << ar[i]<<"  ";
	}
	func(ar, size);
	system("pause");
}