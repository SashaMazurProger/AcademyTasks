#include<string.h>
#include<stdio.h>
#include<iostream>
using namespace std;
bool SearchSymb(char *arr)
{
	bool palin = true;
	for (int i = 0, e = strlen(arr)-1; i <= e; ++i, --e)
	{
		if (arr[i] == arr[e])
		{
			continue;
		}
		else
		{ 
		palin = false;
		break;
		}
	}
	return palin;
}
void main()
{
	const int size = 50;
	char arr[size];
	cout << "Vvedit symvolnyy ryadok:";
	gets_s(arr);
	cout << "Symvolnyy ryadok - palindrom: " <<boolalpha<< SearchSymb(arr) << "\n";
	system("pause");
}