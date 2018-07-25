#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
template <typename T> T maxElement(T array[], int size)
{
	T max = array[0];
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

template <typename T, int h, int w> T maxElementM(T (&array)[h][w])
{
	cout << "\n";
	T max = array[0][0];
	for (int i = 0; i < h; ++i)
	{
		for (int e = 0; e < w; ++e)
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
template <typename T,int w, int h, int L> T maxElementB(T (&array)[w][h][L])
{
	cout << "\n";
	T max = array[0][0][0];
	for (int i = 0; i < w; ++i)
	{
		for (int e = 0; e < h; ++e)
		{
			for (int a = 0; a < L; ++a)
			{
				if (array[i][e][a] > max)
				{
					max = array[i][e][a];
				}
				cout << array[i][e][a] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	return max;
}
template <typename T1> T1 maxElement2(T1 a,T1 b) {
	cout << "\n" << a << " " << b;
	T1 max = a > b ? a : b;
	return max;
}
template <typename T> T maxElement3(T a, T b, T c)
{
	cout << "\n" << a << " " << b << " " << c << endl;
	T max = a;
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
			arrayMedium[i][a] =10+ rand() %90 ;
			for (int e = 0; e < size; ++e)
			{
				arrayBig[i][a][e] = 10+rand() % 90;
			}
		}
	}
	cout << "\nmax :" << maxElement(arraySmall, size) << "\n" << "_________________________________";
	cout << "\nmax :" << maxElementM(arrayMedium) << "\n" << "_________________________________";
	cout << "\nmax :" << maxElementB(arrayBig) << "\n" << "_________________________________";
	cout << "\nmax:" << maxElement2(firstNumb, secondNumb) << "\n" << "_________________________________";
	cout << "\nmax:" << maxElement3(firstNumb, secondNumb, thirdNumb);
	system("pause");
}
