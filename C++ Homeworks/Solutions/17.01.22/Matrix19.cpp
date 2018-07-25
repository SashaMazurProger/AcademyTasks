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
	int sum=0;

	for (int i = 0; i < M; ++i)
	{
		sum = 0;
		for (int e = 0; e < N; ++e)
		{
			arr[i][e] = rand() % 10;
			cout << setw(3) << arr[i][e];
			sum += arr[i][e];
		}
		cout <<"\tsum:"<<sum<< endl;
	}
	system("pause");
}