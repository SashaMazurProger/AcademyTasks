#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<string.h>
using namespace std;

struct Book
{
	char Nazva[20];
	char Avtor[20];
	char Vydavn[20];
	char Zhanr[20];
};
void Print(Book a)
{
		cout << "\n\tNazva:" << a.Nazva;
		cout << "\n\tAvtor:" << a.Avtor;
		cout << "\n\tVydavn-vo:" << a.Vydavn;
		cout << "\n\tZhanr:" << a.Zhanr;
		cout << endl;
}
void Print(Book a[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (!strlen(a[i].Nazva)>2)
			continue;
		cout << i + 1 << " knyha";
		cout << "\n\tNazva:" << a[i].Nazva;
		cout << "\n\tAvtor:" << a[i].Avtor;
		cout << "\n\tVydavn-vo:" << a[i].Vydavn;
		cout << "\n\tZhanr:" << a[i].Zhanr;
		cout << endl;
	}
}
void Detali(Book &a)
{
	int key = 1;
	do
	{
		cout << "Vkazhit dani knyhy";
		cout << "\n\tNazva:";
		do
		{
			gets_s(a.Nazva);
		} while (!isalpha(a.Nazva[0]));
		cout << "\n\tAvtor:";
		do
		{
			gets_s(a.Avtor);
		} while (!isalpha(a.Avtor[0]));
		cout << "\n\tVydavn-vo:";
		do
		{
			gets_s(a.Vydavn);
		} while (!isalpha(a.Vydavn[0]));
		cout << "\n\tZhanr:";
		do
		{
			gets_s(a.Zhanr);
		} while (!isalpha(a.Zhanr[0]));

		Print(a);
		cout << "\n\nZberehty?(1-Tak,0-Ni)\n\n";
		do
		{
			cin >> key;
		} while (key != 0 && key != 1);
	} while (!key);
}
void PoshukKnyhyNaz(Book m[], int size, char s[])
{
	int count = 0;
	for (int i = 0; i < size; ++i)
	{
		count = 0;
		for (int e = 0; e < strlen(s); ++e)
		{
			if (m[i].Nazva[e] != s[e])
				break;
			else
				++count;
		}
		if (count == strlen(s))
		{
			cout << "\nTaki dani maye " << i + 1 << "-ta knyha";
			Print(m[i]);
			return;
		}
	}
	cout << "\nKnyhy z takymy danymy ne znaydeno";
}
void PoshukKnyhyAvt(Book m[], int size, char s[])
{
	int count = 0;
	for (int i = 0; i < size; ++i)
	{
		count = 0;
		for (int e = 0; e < strlen(s); ++e)
		{
			if (m[i].Avtor[e] != s[e])
				break;
			else
				++count;
		}
		if (count == strlen(s))
		{
			cout << "\nTaki dani maye " << i + 1 << "-ta knyha";
			Print(m[i]);
			return;
		}
	}
	cout << "\nKnyhy z takymy danymy ne znaydeno!!!";
}
int main()
{
	const int size = 10;
	Book myLibrary [size];
	char Poshuk[20];
	int key, PoshKnyhy;
	cout << "\t\t***Biblioteka***";
	do
	{
		cout << "\n--------------------------"
			<< "\n     \\\\\\Menu///"
			<< "\n1 - Redahuvaty knyhu"
			<< "\n2 - Druk vsih knyh"
			<< "\n3 - Poshuk knyhy za nazvoyu"
			<< "\n4 - Poshuk knyhy za avtorom"
			<< "\n\n0 - Vyhid"
			<< "\n--------------------------\n";
		do
		{
			cout << "\nZrobit vash vybir:";
			cin >> key;
		} while (key<0 || key>5);
		switch (key)
		{
		case 1:
			do
			{
				cout << "\nVkazhit poryadkovyy nomer knyhy(<=10)";
				cin >> PoshKnyhy;
			} while (PoshKnyhy <= 0 || PoshKnyhy > 10);
			Detali(myLibrary[PoshKnyhy - 1]);
			break;
		case 2:
			Print(myLibrary, size);
			break;
		case 3:
			cout << "\nVkazhit nazvu knyhy:";
			do
			{
				gets_s(Poshuk);
			} while (!isalpha(Poshuk[0]));
			PoshukKnyhyNaz(myLibrary, size, Poshuk);
			break;
		case 4:
			cout << "\nVkazhit avtora knyhy:";
			do
			{
				gets_s(Poshuk);
			} while (!isalpha(Poshuk[0]));
			PoshukKnyhyAvt(myLibrary, size, Poshuk);
			break;
		}
	} while (key);
	system("pause");
	return 0;
}



