#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<string.h>
using namespace std;

struct Auto
{
	char Marka[20];
	char Model[20];
	float Dovzhyna;
	float Klirens;
	float Obyem;
	int Potuzhnist;
	float DiametrKoles;
	char Kolir[20];
	char KorobkaPr[20];
};
void Print(Auto a)
{
	cout << "\n\tMarka avto:" << a.Marka;
	cout << "\n\tModel:" << a.Model;
	cout << "\n\tDovzhyna(m):" << a.Dovzhyna;
	cout << "\n\tKlirens(cm): " << a.Klirens;
	cout << "\n\tObyem dvyhuna(l):" << a.Obyem;
	cout << "\n\tPotuzhnist(k syl):" << a.Potuzhnist;
	cout << "\n\tDiametr kolis(cm):" << a.DiametrKoles;
	cout << "\n\tKolir:" << a.Kolir;
	cout << "\n\tTyp korobky peredach:" << a.KorobkaPr;
}

void Detali(Auto &a)
{
	int key = 1;
	do
	{
		cout << "Vkazhit harakterystyky auto";
		cout << "\n\tMarka avto";
		do
		{
			gets_s(a.Marka);
		} while (!isalpha(a.Marka[0]));
		cout << "\n\tModel";
		gets_s(a.Model);
		cout << "\n\tDovzhyna(m)";
		cin >> a.Dovzhyna;
		cout << "\n\tKlirens(cm)";
		cin >> a.Klirens;
		cout << "\n\tObyem dvyhuna(l)";
		cin >> a.Obyem;
		cout << "\n\tPotuzhnist(k syl)";
		cin >> a.Potuzhnist;
		cout << "\n\tDiametr kolis(cm)";
		cin >> a.DiametrKoles;
		cout << "\n\tKolir";
		do
		{
			gets_s(a.Kolir);
		} while (!isalpha(a.Kolir[0]));
		cout << "\n\tTyp korobky peredach";
		gets_s(a.KorobkaPr);
		cout << endl;

		Print(a);
		cout << "\n\nZberehty?(1-Tak,0-Ni)\n\n";
		do
		{
			cin >> key;
		} while (key != 0 && key != 1);
	} while (!key);
}

int main()
{
	Auto myCar = {};
	int key;
	cout << "\t\t***Avto***";
	do
	{
		cout << "\n     \\\\\\Menu///"
			<< "\n1 - Vkazaty h-ky avto"
			<< "\n2 - Perehlyanuty h-ky avto"
			<< "\n3 - Poshuk h-k za parametrom"
			<<"\n\n0 - Vyhid";
		do
		{
			cout << "\nZrobit vash vybir";
			cin >> key;
		} while (key != 0 && key != 1 && key != 2 &&
			     key != 3);
		switch (key)
		{
		case 1:
			Detali(myCar);
			break;
		case 2:
			Print(myCar);
		}
	} while (key);
	system("pause");
	return 0;
}



