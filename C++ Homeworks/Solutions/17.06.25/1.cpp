#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<string.h>
#include<time.h>
#include <conio.h>
#include <windows.h>
using namespace std;
void Print(char str[], int countSymb, bool key);
void Test(char str[])
{
	char symb;//potochnyy znak
	int countSymb=0;//k-st virnyh znakiv
	bool key=true,keySymb1=false, keySymb2=false, keySymb3=false;//znak - vidkryta duzhka?
	int position1=0, position2=0, position3=0;//pozhitsiya vidkrytoyi duzhky
	int openSymb1=0, openSymb2=0, openSymb3=0;//k-st vidkrytyh znakiv
	for (int i = 0; i < strlen(str); ++i)
	{
	  symb = str[i];

	  
	  if ((symb == ')'&& (openSymb1!=0&&!keySymb1))
		  || (symb == '}'&& openSymb2 != 0&&!keySymb2)
		  || (symb == ']' && openSymb3 != 0&&!keySymb3))
	  {
		  key = false;
		  countSymb = i+1;
		  break;
	  }
	  if(((keySymb1 && (symb == '}'&&position2<position1) || (symb == ']'&&position3<position1))
		  ||(keySymb2 && (symb == ')'&&position1<position2) || (symb == ']'&&position3<position2))
			  || (keySymb3 && (symb == ')'&&position1 < position3) || (symb == '}'&&position2 < position3))))
	  {
		  key = false;
		  countSymb = i + 1;
		  break;
	  }
	  switch (symb)
	  {
	  case '(':
		  keySymb1 = true;
		  position1 = i;
		  openSymb1++;
		  break;
	  case ')':
		  keySymb1 = false;
		  openSymb1--;
		  break;
	  case '{':
		  keySymb2 = true;
		  position2 = i;
		  openSymb2++;
		  break;
	  case '}':
		  keySymb2 = false;
		  openSymb2++;
		  break;
	  case '[':
		  keySymb3 = true;
		  position3 = i;
		  openSymb3++;
		  break;
	  case ']':
		  keySymb3 = false;
		  openSymb3--;
		  break;
	  default:
		  continue;
		  break;
	  }
	}
	Print(str, countSymb, key);
}
void Print(char str[],int countSymb, bool key)
{
	if (!key)
	{
		cout<<"\nStroka:\"" << str<<"\"";
		cout << "\nPomylkovyy "<<countSymb<<" symvol!!!";
		cout << "\n";
		for (int i = 0; i < countSymb; ++i)
		{
			cout << str[i];
			if (i == countSymb - 1)
			{
				cout <<" \"" << str[i] << "\"";
			}
		}
	}
	else
	{
		cout << "\n" << str;
		cout << "Vse virno!";
	}
}
int main()
{
	int key;
	char str[40];
	do
	{

		cout << "\n--------------------------"
			<< "\n     \\\\\\Menu///"
			<< "\n1 - Vkazaty stroku"
			<< "\n2 - Perevirka"
			<< "\n0 - Vyhid"
			<< "\n--------------------------\n";
		cin >> key;
		if (key == 1)
		{
			cout << "\nStroka:";
			cin >> str;
		}
		if (key == 2)
		{
			Test(str);
		}
	}while (key!=0);
system("pause");
return 0;
}
