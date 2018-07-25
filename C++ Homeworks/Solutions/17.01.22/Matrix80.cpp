#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<iomanip>
using namespace std;
void main()
{
	srand(unsigned(time(NULL)));
	const int size = 5;
	int arr[size][size];
	int sum = 0;
	for (int i = 0; i < size; ++i)
	{
		for (int e = 0; e < size; ++e)
		{
			arr[i][e] = rand() % 10;
			cout << setw(3) << arr[i][e];
			if (i == e)
			{
				sum += arr[i][e];
			}
		}
		cout << endl;
	}
	cout << "\nSuma elementiv holovnoyi diahonali:" << sum << endl;
	system("pause");
}