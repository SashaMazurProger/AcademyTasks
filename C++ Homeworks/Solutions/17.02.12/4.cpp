#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<iomanip>
using namespace std;
void Print(int array[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << setw(3) << array[i] << " ";
	}
}
void Sort(int array[], int size, bool moreZero)
{
	int sizeSort;
	if (moreZero)
	{
		sizeSort = (size / 3) * 2;
	}
	else
	{
		sizeSort = (size / 3);
	}
		int x;
		int i, j;
		for (i = 0; i<sizeSort; i++) 
		{  
			x = array[i];
			for (j = i - 1; j >= 0 && array[j] > x; j--)
			{
				array[j + 1] = array[j];
			}
			array[j + 1] = x;
		}
		int tmp;
		for (int L = sizeSort, R = size-1; L != R&&L<R; ++L, --R)
		{
			tmp = array[L];
			array[L] = array[R];
			array[R] = tmp;
		}
		cout << "\nSort...\n";
		Print(array, size);
}
void SerA(int array[], int size)
{
	bool moreZero;
	int sum = 0;
	float res;
	for (int i = 0; i < size; ++i)
	{
		sum += array[i];
	}
	res = sum / size;
	cout << "Ser.aryph. :" << res << "\n";
	moreZero = res >0 ? true : false;
	Sort(array, size, moreZero);
}
void main()
{
	srand(unsigned(time(NULL)));
	const int size = 12;
	int arr[size];
	for(int i=0;i<size;++i)
	{
		arr[i] = -10+rand() % 20;
	}
	Print(arr, size);
	SerA(arr,size);
	system("pause");
}
