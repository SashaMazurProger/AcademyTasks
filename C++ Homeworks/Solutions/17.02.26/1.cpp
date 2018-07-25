#include<time.h>
#include<stdlib.h>
#include<iostream>
#include<iomanip>
using namespace std;
void Print(int *m, int size)
{
	for (int i = 0; i < size; ++i, ++m)
		cout <<setw(2)<< *m << " ";
	cout << endl;
}
void func(int *m,int *n, int size)
{
	int tmp;
	for(int L=0,R=size-1;L<=R;++L,--R)
	{
		*(n+L) = *(m+L);
		*(n+R) = *(m + R);
	}
}
void main()
{
	srand(unsigned(time(NULL)));
	const int size = 9;
	int arr1[size];
	int arr2[size];
	for (int i = 0; i<size; ++i)
	{
		arr1[i] =rand() % 20;
	}
	cout << "arr1\t";
	Print(arr1, size);
	func(arr1,arr2, size);
	cout << "arr2\t";
	Print(arr2, size);
	system("pause");
}
