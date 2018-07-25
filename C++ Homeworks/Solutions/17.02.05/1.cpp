#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
void Array(int size, int array[5][5]);
void Array(int size, double array[5][5]);
void Array(int size, char array[5][5]);
template <typename T1, typename T2> T2 sort(T1 size, T2 arr);

void main()
{
	srand(unsigned(time(NULL)));
	const int size = 5;
	int arrayInt[size][size];
	double arrayDouble[size][size];
	char arraySymbol[size][size];
	Array (size, arrayInt); 
	cout << "\n" << "_________________________________";
	Array (size, arrayDouble); 
	cout << "\n" << "_________________________________";
	Array(size, arraySymbol); 
	cout << "\n" << "_________________________________";
	system("pause");
}
void Array(int size, int array[5][5])
{
	cout << "\n";
	for (int i = 0; i < size; ++i)
	{
		for (int e = 0; e < size; ++e)
		{
			array[i][e] =10+ rand() % 40;
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
			if (i == e&&array[i][e] > max)
			{
				max = array[i][e];
			}
			if (i == e&&array[i][e] < min)
			{
				min = array[i][e];
			}
		}
	}
	cout << "max:" << max
		<< "\nmin:" << min;
	cout << endl;
	sort(size, array);
}
void Array(int size, double array[5][5])
{
	cout << "\n";
	for (int i = 0; i < size; ++i)
	{
		for (int e = 0; e < size; ++e)
		{
			double add = rand() % 1000;
			array[i][e] =10+ rand() % 40 + (add/ 1000);
			cout << array[i][e] << " ";
		}
		cout << endl;
	}
	double max = array[0][0];
	double min = array[0][0];
	for (int i = 0; i < size; ++i)
	{
		for (int e = 0; e < size; ++e)
		{
			if (i == e&&array[i][e] > max)
			{
				max = array[i][e];
			}
			if (i == e&&array[i][e] < min)
			{
				min = array[i][e];
			}
		}
	}
	cout << "max:" << max
		<< "\nmin:" << min;
	cout << endl;
	sort(size, array);
}
void Array(int size, char array[5][5])
{
	cout << "\n";
	int maxIndexI = 0, minIndexI = 0;
	int maxIndexE = 0, minIndexE = 0;
	for (int i = 0; i < size; ++i)
	{
		for (int e = 0; e < size; ++e)
		{
			array[i][e] ='a'+ rand() % 26;
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

