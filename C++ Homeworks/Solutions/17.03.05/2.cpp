#include<time.h>
#include<stdlib.h>
#include<iostream>
#include<iomanip>
using namespace std;
void Print(int *m, int size)
{
	for (int i = 0; i < size; ++i)
		cout << setw(2) << m[i] << " ";
	cout << endl;
}
void mas(int *m, int s)
{
	for (int i = 0; i<s; ++i)
	{
		m[i] = rand() % 15;
	}
}
void search(int *a, int *b, int &size1, int &size2, int &size3)
{
	int key;
	for (int i = 0; i < size1; ++i)
	{
		key = 1;
		for (int m = 0; m < i; ++m)
		{
			if (a[m] == a[i])
			{
				--size3;
				key = 0;
				break;
			}
		}
		if (key)
		{
			for (int n = 0; n < size2; ++n)
			{
				if (a[i] == b[n])
				{
					--size3;
					break;
				}
			}
		}
	}
}
void past(int *a, int *b, int *c, int &size1, int &size2, int &size3, int &countIndex)
{
	int key;
	for (int i = countIndex; i < size3; ++i)
	{
		for (int n = 0; n < size1; ++n)
		{
			key = 1;
			for (int k = 0; k < size2; ++k)
			{
				if (a[n] == b[k])
				{
					key = 0;
					break;
				}
			}
			if (key)
			{
				for (int p = 0; p < i; ++p)
				{
					if (c[p] == a[n])
					{
						key = 0;
						break;
					}
				}
			}
			if (key)
			{
				c[i] = a[n];
				++countIndex;
				break;
			}
		}
	}
}
void main()
{
	srand(unsigned(time(NULL)));
	int M, N;
	do {
		cout << "Rozmir 1 masyvu:";
		cin >> M;
	} while (M < 1);
	do {
		cout << "Rozmir 2 masyvu:";
		cin >> N;
	} while (N < 1);
	int *A = new int[M];
	int *B = new int[N];
	mas(A, M);
	mas(B, N);
	cout << "Masyv 1\n\t";
	Print(A, M);
	cout << "Masyv 2\n\t";
	Print(B, N);
	int L = M + N;
	search(A, B, M, N, L);
	search(B, A, N, M, L);
	int *C = new int[L];
	int EndIndex = 0;
	past(A, B, C, M, N, L, EndIndex);
	past(B, A, C, N, M, L, EndIndex);
	cout << "Novyy masyv(masyv 1(! masyv 2)+masyv 2(! masyv 1)) \n\t";
	Print(C, L);
	system("pause");
}
