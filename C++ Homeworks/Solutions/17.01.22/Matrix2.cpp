#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<iomanip>
using namespace std;
void main()
{
	srand(unsigned(time(NULL)));
	const int M = 8, N = 7;
	int arr[M][N];
	int j;
	do
	{
		cout << "Nomer stovba(1...7):";
		cin >> j;
	} while (j < 1 || j>7);
	for (int i = 0; i < M; ++i)
	{
		for (int e = 0; e < N; ++e)
		{
			arr[i][e] = rand() % 10;
			cout << setw(3) << arr[i][e];
		}
		cout << endl;
	}
	cout << endl << endl;
	for (int i = 0; i < M; ++i)
	{
		for (int e = 0; e < N; ++e)
		{
			if (j == e+1)
			{
				arr[i][e] = j*5;
			}
			cout << setw(3) << arr[i][e];
		}
		cout << endl;
	}
	system("pause");
}