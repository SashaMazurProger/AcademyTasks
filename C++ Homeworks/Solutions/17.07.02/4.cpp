#include<string.h>
#include<stdio.h>
#include<iostream>
using namespace std;
//int SearchWord(char *arr, char *word,bool *key,int *firstSymb)
//{
//	int countSymb = 0,countWord=0;
//	for (int i = 0; i < strlen(arr); ++i)
//	{
//		if (arr[i] == ' ')
//		{
//			countSymb = 0;
//			continue;
//		}
//		if ((arr[i-1]==' '&&arr[i] == word[0])||(i==0&&arr[i] == word[0]))
//		{
//			firstSymb[countWord] = i;
//			for (int j = 0; j < strlen(word); ++j,++i)
//			{
//				if (arr[i] == word[j])
//					countSymb++;
//				else
//				{
//					countSymb = 0;
//					break;
//				}
//				if (countSymb == strlen(word))
//				{
//					++countWord;
//					countSymb = 0;
//					*key = true;
//					break;
//				}
//			}
//		}
//
//	}
//	return countWord;
//}
int SearchAndPast(char *arr,char *res, char *SearchWord,char *pastWord, bool *key,bool *keyPast )
{
	int countSymb = 0, countWord = 0, endSymb = 0;
	for (int i = 0; i < strlen(arr); ++i)
	{
		if (arr[i] == ' ')
		{
			countSymb = 0;
			continue;
			res[endSymb] = arr[i];
			++endSymb;
		}
		if ((arr[i - 1] == ' '&&arr[i] == SearchWord[0]) || (i == 0 && arr[i] == SearchWord[0]))
		{
			for (int j = 0; j < strlen(SearchWord); ++j, ++i)
			{
				if (arr[i] == SearchWord[j])
					countSymb++;
				else
				{
					countSymb = 0;
					break;
				}
				if (countSymb == strlen(SearchWord))
				{
					++countWord;
					countSymb = 0;
					*key = true;
					if (keyPast)
					{
						for (int e = 0; e < strlen(pastWord); ++e,++endSymb)
						{
							res[endSymb] = pastWord[e];
						}
					}
					break;
				}
			}
		}
		else
		{
			res[endSymb] = arr[i];
			++endSymb;
		}

	}
	return countWord;
}
//int Past(char *arr,char *res,int sizeOldWord, char *newWord, int *firstS)
//{
//	cout << "\nstroka:" << arr;
//	cout << "\nres:" << res;
//	int position,countWord = 0;
//	for (int i = 0,p=0; i<strlen(arr); ++i)
//	{
//		if (i == firstS[p])
//		{
//			int s = strlen(res);
//			for (int t = 0; t < strlen(newWord); ++t,++s)
//			{
//				res[s] = newWord[t];
//			}
//			++countWord;
//			i += (sizeOldWord - 1);
//			++p;
//		}
//		else
//		{
//			position=strlen(res);
//			res[position] = arr[i];
//		}
//	}
//	return countWord;
//}
void main()
{
	const int size = 50;
	bool keySearch=false;
	bool keyPast = false;
	int firstSymb[size];
	int sizeOldWord;
	char arr[size];
	char word[size];
	char past[size];
	char res[size];
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
	cout<<"Znaydeno "<<SearchAndPast(arr, res,word,past,&keySearch,&keyPast)<<" takyh sliv";
	if (keySearch)
	{
		keyPast = true;
		sizeOldWord = strlen(word);
		cout << "\nVvedit slovo dlya zaminy:";
		do
		{
			gets_s(past);
		} while (!isalpha(past[0]));
		/*cout<<"Zamineno "<<Past(arr, res, sizeOldWord, past, firstSymb)<<" sliv";*/
		cout << "Zamineno: " << SearchAndPast(arr, res, word, past, &keySearch, &keyPast)<<" sliv";
		cout << "\nRezultat:" << res;
	}
	system("pause");
}
