#include<string.h>
#include<stdio.h>
#include<iostream>
using namespace std;
int SearchSymb(char *arr)
{
	int count = 0, key = 1;
	for (int i = 0; i < strlen(arr); ++i)
	{
		if (isalpha(arr[i]) && key)
		{
			++count;
			key = 0;
			continue;
		}
		if (isspace(arr[i]) && isalpha(arr[i - 1]))
			++count;
	}
	return count;
}
void main()
{
	const int size = 50;
	char arr[size];
	cout << "Vvedit symvolnyy ryadok:";
	gets_s(arr);
	cout << "K-st sliv v ryadku: " << SearchSymb(arr) << "\n";
	system("pause");
}
