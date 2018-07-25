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
	float SerAryph, add, AddElem;
	int ResIndexString = 0, ResIndexElem = 0;
	int SizeCount;
	for (int i = 0; i < size; ++i)
	{
		for (int e = 0; e < size; ++e)
		{
			arr[i][e] = rand() % 10;
			cout << setw(3) << arr[i][e];
			sum += arr[i][e];
		}
		cout << endl;
	}
	SizeCount = size*size;
	SerAryph = (float)sum / SizeCount;
	add = SerAryph - arr[0][0];
	if (add < 0)
	{
		add *= -1;
	}
	for (int i = 0; i < size; ++i)
	{
		for (int e = 0; e < size; ++e)
		{
			AddElem = SerAryph - arr[i][e];
			if (AddElem < 0)
			{
				AddElem *= -1;
			}
			if (add > AddElem)
			{
				add = AddElem;
				ResIndexString = i;
				ResIndexElem = e;
			}

		}
	}
	cout << "Serednye znachennya:" << SerAryph
		<<"\n\n\tElement nablyzhenyy za znachennyam"
		<< "\nStroka:" << ResIndexString+1
		<< "\nStovbets:" << ResIndexElem+1
		<< "\nZnachennya:" << arr[ResIndexString][ResIndexElem];
	system("pause");
}