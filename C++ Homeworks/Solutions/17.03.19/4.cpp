#include <iostream>
#include<stdio.h>
#include<iomanip>
using namespace std;
void print(int* mas[], int size, int size2)
{
	for (int i = 0; i < size; ++i)
	{
		for (int e = 0; e<size2; ++e)
		{
			cout << setw(3) << mas[i][e] << " ";
		}
		cout << endl;
	}
}
void Trans(int* arr1[], int* arr2[], int s1, int s2)
{
	for (int i = 0; i < s1; ++i)
	{
		arr2[i] = new int[s2];
	}
	for (int i = s2-1,p=0; i>=0; --i,++p)
	{
		for (int e = 0; e<s2; ++e)
		{
			arr2[p][e] = arr1[e][i];
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
	for (int i = 0; i < size1; ++i)
	{
		arr[i] = new int[size2];
		cout << "Vkazhit elementy " << i + 1 << "ryadka:\n";
		for (int y = 0; y < size2; ++y)
		{
			cout << " ";
			cin >> arr[i][y];
		}
	}
	cout << "Potochnyy masyv\n";
	print(arr, size1, size2);
	int**arrNew = new int *[size1];
	Trans(arr, arrNew, size1, size2);
	cout << endl << "Novyy masyv\n";
	print(arrNew, size1, size2);
	for (int i = 0; i < size1; ++i)
	{
		delete[]arr[i];
		delete[]arrNew[i];
    }
	delete[]arr;
	delete[]arrNew;
	system("pause");
	return 0;
}



