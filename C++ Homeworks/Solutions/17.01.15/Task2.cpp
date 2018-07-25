#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int maxElement(int size, int array[]);
int maxElement(int size, long array[5][5]);
float maxElement(int size, float array[5][5][5]);
int maxElement(int a, int b);
int maxElement(int a, int b, int c);

void main()
{
	srand(time(NULL));
	int firstNumb = rand() % 10, secondNumb = rand() % 10,
		thirdNumb = rand() % 10;
	const int size = 5;
	int arraySmall[size];
	long arrayMedium[size][size];
	float arrayBig[size][size][size];
	for (int i = 0; i < size; ++i)
	{
		arraySmall[i] = rand() % 20;
		for (int a = 0; a < size; ++a)
		{
			arrayMedium[i][a] = rand() % 20;
			for (int e = 0; e < size; ++e)
			{
				arrayBig[i][a][e] = rand() % 50;
			}
		}
	}
	cout << "\nmax :" << maxElement(size, arraySmall) << "\n" << "_________________________________";
	/*cout << "\nmax :" << maxElement(size, arrayMedium) << "\n" << "_________________________________";
	cout << "\nmax :" << maxElement(size, arrayBig) << "\n" << "_________________________________";
	cout << "\nmax:" << maxElement(firstNumb, secondNumb) << "\n" << "_________________________________";
	cout << "\nmax:" << maxElement(firstNumb, secondNumb, thirdNumb);*/
	system("pause");
}
int maxElement(int size, int array[])
{
	int max = array[0];
	for (int i = 0; i < size; ++i)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
		cout << array[i] << " ";
	}
	return max;
}
int maxElement(int size, long array[5][5])
{
	cout << "\n";
	int max = array[0][0];
	for (int i = 0; i < size; ++i)
	{
		for (int e = 0; e < size; ++e)
		{
			if (array[i][e] > max)
			{
				max = array[i][e];
			}
			cout << array[i][e] << " ";
		}
		cout << endl;
	}
	return max;
}
float maxElement(int size, float array[5][5][5])
{
	cout << "\n";
	int max = array[0][0][0];
	for (int i = 0; i < size; ++i)
	{
		for (int a = 0; a < size; ++a)
		{
			for (int e = 0; e < size; ++e)
			{
				if (array[i][a][e] > max)
				{
					max = array[i][a][e];
				}
				cout << array[i][a][e] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	return max;
}
int maxElement(int a, int b)
{
	cout << "\n" << a << " " << b;
	int max = a > b ? a : b;
	return max;
}
int maxElement(int a, int b, int c)
{
	cout << "\n" << a << " " << b << " " << c << endl;
	int max = a;
	if (a < b)
	{
		max = b;
	}
	if (b<c&&a<c)
	{
		max = c;
	}
	return max;
}





