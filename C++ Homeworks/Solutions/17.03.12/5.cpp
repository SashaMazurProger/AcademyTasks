#include<string.h>
#include<stdio.h>
#include<iostream>
using namespace std;
int SearchSymb(char *arr,char &symb)
{
	int count = 0;
	for (int i = 0; i < strlen(arr); ++i)
	{
		if (arr[i] == symb)
			++count;
	}
	return count;
}
void main()
{
	const int size=50;
	char arr[size];
	char symb;
	cout << "Vvedit symvolnyy ryadok:";
	gets_s(arr);
	cout << "Vvedit shukanyy symvol:";
	cin >> symb;
	cout << "K-st symvoliv "<<symb<<":"<< SearchSymb(arr, symb)<<"\n";
	system("pause");
}
