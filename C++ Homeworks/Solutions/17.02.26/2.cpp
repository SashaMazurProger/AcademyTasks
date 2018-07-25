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
void func(int *m, int size)
{
	int tmp;
	for(int L=0,R=size-1;L<=R;++L,--R)
	{
		tmp = *(m+L);
		*(m+L) = *(m+R);
		*(m+R) = tmp;
	}
}
void main()
{
	srand(unsigned(time(NULL)));
	const int size = 9;
	int arr[size];
	for (int i = 0; i<size; ++i)
	{
		arr[i] =rand() % 20;
	}
	Print(arr, size);
	func(arr, size);
	Print(arr, size);
	system("pause");
}
