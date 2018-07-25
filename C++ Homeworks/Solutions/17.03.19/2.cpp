#include <iostream>
#include<stdio.h>
#include<iomanip>
using namespace std;
void print(int* mas[], int size, int size2)
{
	cout << endl << "Novyy masyv\n";
	for (int i = 0; i < size; ++i)
	{
		for (int e = 0; e<size2; ++e)
		{
			cout << setw(3) << mas[i][e] << " ";
		}
		cout << endl;
	}
}
void Copy(int* arr1[], int* arr2[], int s1, int s2, int newStr)
{
	for (int i = 0, p = 0; p<s1 - 1; ++i, ++p)
	{
		if (i == newStr - 1)
		{
			--p;
			continue;
		}
		arr2[p] = new int[s2];
		for (int e = 0; e<s2; ++e)
		{
			arr2[p][e] = arr1[i][e];
		}
	}
}
int main()
{
	int size1, size2, newStr;
	cout << "Rozmir masyvu"
		<< "\n\tRyadkiv:";
	cin >> size1;
	cout << "\tStovpiv:";
	cin >> size2;
	int **arr = new int *[size1];
	for (int i = 0; i<size1; ++i)
	{
		arr[i] = new int[size2];
		cout << "Vkazhit elementy " << i + 1 << "ryadka:\n";
		for (int y = 0; y<size2; ++y)
		{
			cout << " ";
			cin >> arr[i][y];
		}
	}
	do
	{
		cout << "Vkazhit nomer ryadka dlya vydalennya ";
		cin >> newStr;
	} while (newStr<1 || newStr>size1);
	int**arrNew = new int *[size1 - 1];
	Copy(arr, arrNew, size1, size2, newStr);
	print(arrNew, size1 - 1, size2);
	for (int i = 0; i < size1; ++i)
	{
		delete[]arr[i];
		if (i < size1 - 1)
		{
			delete[]arrNew[i];
		}
	}
	delete[]arr;
	delete[]arrNew;
	system("pause");
	return 0;
}



