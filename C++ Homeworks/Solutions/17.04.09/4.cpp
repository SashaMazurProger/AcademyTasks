#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<string.h>
using namespace std;

struct Auto
{
	char Model[20];
	char Kolir[20];
	char Nomer[9];
};
void Print(Auto a)
{
	cout << "\n\tModel:" << a.Model;
	cout << "\n\tKolir:" << a.Kolir;
	cout << "\n\tNomer:" << a.Nomer;
}
void Print(Auto a[],int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (atoi(a[i].Nomer)==0)
			continue;
		cout << i + 1 << " avto";
		cout << "\n\tModel:" << a[i].Model;
		cout << "\n\tKolir:" << a[i].Kolir;
		cout << "\n\tNomer:" << a[i].Nomer;
		cout << endl;
	}
}
void Detali(Auto &a)
{
	int key = 1;
	do
	{
		cout << "Vkazhit harakterystyky auto";
		cout << "\n\tModel avto";
		do
		{
			gets_s(a.Model);
		} while (!isalpha(a.Model[0]));
		cout << "\n\tKolir";
		do
		{
			gets_s(a.Kolir);
		} while (!isalpha(a.Kolir[0]));
		cout << "\n\tNomer";
		do
		{
			gets_s(a.Nomer);
		} while (!isdigit(a.Nomer[0]));

		Print(a);
		cout << "\n\nZberehty?(1-Tak,0-Ni)\n\n";
		do
		{
			cin >> key;
		} while (key != 0 && key != 1);
	} while (!key);
}
void PoshukN(Auto m[], int size, char s[])
{
	int count = 0;
	for (int i = 0; i < size; ++i)
	{
		count = 0;
		for (int e = 0; e < strlen(s); ++e)
		{
			if (m[i].Nomer[e] != s[e])
				break;
			else
				++count;
		}
		if (count == strlen(s))
		{
			cout << "\nTakyy nomer maye " << i + 1 << "-te avto";
			Print(m[i]);
			return;
		}
	}
	cout << "\nAvto z takym nomerom ne znaydeno";
}
int main()
{
	char arr[2];
	cout <<atoi(arr);
	const int size = 10;
	char masN[9];
	Auto myCar = {};
	Auto myCars[size];
	int key,nAvto;
	cout << "\t\t***Avto***";
	do
	{
		cout << "\n--------------------------"
			<< "\n     \\\\\\Menu///"
			<< "\n1 - Dodaty avto"
			<< "\n2 - Druk avto"
			<< "\n       ***"
			<< "\n3 - Redahuvaty avto"
			<< "\n4 - Druk vsih avto"
			<< "\n5 - Poshuk avto po nomerom"
			<<"\n\n0 - Vyhid"
			<<"\n--------------------------\n";
		do
		{
			cout << "\nZrobit vash vybir";
			cin >> key;
		} while (key<0||key>5);
		switch (key)
		{
		case 1:
			Detali(myCar);
			break;
		case 2:
			Print(myCar);
			break;
		case 3:
			do
			{
				cout << "\nVkazhit poryadkovyy nomer avto(<=10)";
				cin >> nAvto;
			} while (nAvto <= 0 || nAvto > 10);
			Detali(myCars[nAvto -1]);
			break;
		case 4:
			Print(myCars, size);
			break;
		case 5:
			cout << "\nVkazhit nomer avto(8 tsyfr)";
			do
			{
				gets_s(masN);
			} while (!atoi(masN));
			PoshukN(myCars, size, masN);
			break;
		}
	} while (key);
	system("pause");
	return 0;
}



