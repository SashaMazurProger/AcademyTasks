#include<string.h>
#include<stdio.h>
#include<iostream>
using namespace std;
int SearchWord(char *arr, char *word)
{
	int countSymb = 0,countWord=0;
	for (int i = 0; i < strlen(arr); ++i)
	{
		if (arr[i] == ' ')
		{
			countSymb = 0;
			continue;
		}
		if (arr[i-1]==' '&&arr[i] == word[0])
		{
			for (int j = 0; j < strlen(word); ++j,++i)
			{
				if (arr[i] == word[j])
					countSymb++;
				else
				{
					countSymb = 0;
					break;
				}
				if (countSymb == strlen(word))
				{
					++countWord;
					countSymb = 0;
					break;
				}
			}
		}

	}
	return countWord;
}
void main()
{
	const int size = 50;
	char arr[size];
	char word[size];
	cout << "Vvedit symvolnyy ryadok:";
	do
	{
		gets_s(arr);
	} while (!isalpha(arr[0]));
	cout << "Vvedit shukane slovo:";
	do
	{
		gets_s(word);
	} while (!isalpha(word[0]));
	cout<<"Znaydeno "<<SearchWord(arr, word)<<" takyh sliv";
	system("pause");
}
