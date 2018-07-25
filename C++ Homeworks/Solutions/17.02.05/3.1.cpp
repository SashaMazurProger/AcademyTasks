#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
template <typename T1, typename T2> T1 Arr(T1 size, T2 array);
template <typename T1, typename T2> T2 sort(T1 size, T2 arr);
void main()
{
	srand(unsigned(time(NULL)));
	const int size = 5;
	int arrayInt[size][size];
	double arrayDouble[size][size];
	char arraySymbol[size][size];
	Arr(size, arrayInt);
	cout << "\n" << "_________________________________";
	Arr(size, arrayDouble);
	cout << "\n" << "_________________________________";
	Arr(size, arraySymbol);
	cout << "\n" << "_________________________________";
	system("pause");
}
template <typename T1, typename T2> T1 Arr(T1 size, T2 array)
{
	cout << "\n";
	int maxIndexI = 0, minIndexI = 0;
	int maxIndexE = 0, minIndexE = 0;
	for (int i = 0; i < size; ++i)
	{
		for (int e = 0; e < size; ++e)
		{
			array[i][e] = 'a' + rand() % 26;
			cout << array[i][e] << " ";
		}
		cout << endl;
	}
	int max = array[0][0];
	int min = array[0][0];
	for (int i = 0; i < size; ++i)
	{
		for (int e = 0; e < size; ++e)
		{
			if (i == e&&array[i][e] < min)
			{
				min = array[i][e];
				minIndexI = i;
				minIndexE = e;
			}
			if (i == e&&array[i][e] > max)
			{
				max = array[i][e];
				maxIndexI = i;
				maxIndexE = e;
			}
		}
	}
	cout << "max: [" << maxIndexI << "][" << maxIndexE << "]..." << array[maxIndexI][maxIndexE]
		<< "\nmin: [" << minIndexI << "][" << minIndexE << "]..." << array[minIndexI][minIndexE];
	cout << endl;
	sort(size, array);
	return 0;
}
template <typename T1, typename T2> T2 sort(T1 size, T2 arr)
{
	cout << "\nSort(min->max)";
	int k;
	double x;
	for (int str = 0; str < size; ++str)
	{
		cout << "\n\t";
		for (int i = 0; i < size; ++i)
		{
			k = i;
			x = arr[str][i];

			for (int j = i + 1; j < size; j++)
			{
				if (arr[str][j] < x)
				{
					k = j;
					x = arr[str][j];
				}
			}
			arr[str][k] = arr[str][i];
			arr[str][i] = x;
			cout << arr[str][i] << " ";
		}
		cout << endl;
	}
	return 0;
}





