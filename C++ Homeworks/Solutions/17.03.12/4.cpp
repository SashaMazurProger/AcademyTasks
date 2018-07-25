#include<string.h>
#include<stdio.h>
#include<iostream>
using namespace std;
void Print(char *m)
{
	for (int i = 0; i < strlen(m); ++i)
		cout << m[i];
	cout << endl;
}
void ModifyStr(char *arr)
{
	for (int i = 0; i < strlen(arr); ++i)
	{
		if (arr[i] == '.')
			arr[i] = '!';
	}
}
void main()
{
	const int size=50;
	char arr[size];
	cout << "Vvedit symvolnyy ryadok:";
	gets_s(arr);
	ModifyStr(arr);
	cout << "Rezultat\n";
	Print(arr);
	system("pause");
}
