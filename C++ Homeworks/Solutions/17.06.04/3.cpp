#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<string.h>
using namespace std;

class Overcoat
{
	char type[20];
	double price;
public:
	Overcoat()
	{
	}
    Overcoat(double s,double p)
	{
		price = s;
		price = p;
	}
	void SetPrice(double s)
	{
		price = s;
	}
	double GetPrice()
	{
		return price;
	}
	void SetType(char p[])
	{
		strcpy_s(type,p);
	}
	char* GetType()
	{
		return type;
	}
    void operator ==( Overcoat m)
	{
		if (isalpha(type[0]) && isalpha(m.type[0]))
		{
			if (strcmp(type,m.type)==0)
				cout << "\ntype1 == type2";
			else
				cout << "\ntype1!=type2";
		}
		else
			cout << "\nSpochatku vkazhit typ odezhi";
	}
	Overcoat operator =(Overcoat m)
	{
		if (isalpha(m.type[0]))
		{
			strcpy_s(type, m.type);
			this->price = m.price;
			return *this;
		}
		else
			cout << "\nSpochatku vkazhit parametry odyahu";
	}
	void operator >(Overcoat m)
	{
		if (price != 0 && m.price != 0)
		{
			if (price == m.price)
				cout << "\nPrice1 == Price2";
			else if(price>m.price)
				cout << "\nPrice1 > Price2";
			else
				cout << "\nPrice1 < Price2";
		}
		else
			cout << "\nSpochatku vkazhit znachennya tciny";
	}
    static void Print( Overcoat n,Overcoat m)
	{
		cout <<"\nTyp Overcoat1:"<<n.type;
		cout << "\nTcina Overcoat1:" << n.price;
		cout << "\n--------";
		cout << "\nTyp Overcoat2:" << m.type;
		cout << "\nTcina Overcoat2:" << m.price;
	}
};

int main()
{
	double tmpArea,tmpPrice;
	int key;
	Overcoat overcoat1;
	Overcoat overcoat2;
	char tmpType[20];
	do
	{
		cout << "\n--------------------------"
			<< "\n     \\\\\\Menu///"
			<< "\n1 - Vkazaty dani odyahu"
			<< "\n2 - Porivnyaty typy odyahu"
			<< "\n3 - Overcoat1=Overcoat2"
			<< "\n4 - Overcoat2=Overcoat1"
			<< "\n5 - Porivnyaty tciny"
			<< "\n\n0 - Vyhid"
			<< "\n--------------------------\n";
		do
		{
			cout << "\nZrobit vash vybir";
			cin >> key;
		} while (key<0 || key>5);
		switch (key)
		{
		case 1:
			cout << "\nPershyy odyah";
			cout << "\n\nTyp=";
			do
			{
				gets_s(tmpType);
			} while (!isalpha(tmpType[0]));
			overcoat1.SetType(tmpType);

			cout << "\n\nTcina=";
			cin >> tmpPrice;
			overcoat1.SetPrice(tmpPrice);

			cout << "\nDruhyy odyah";
			cout << "\n\nTyp=";
			do
			{
				gets_s(tmpType);
			} while (!isalpha(tmpType[0]));
			overcoat2.SetType(tmpType);

			cout << "\n\nTcina=";
			cin >> tmpPrice;
			overcoat2.SetPrice(tmpPrice);
			break;
		case 2:
			Overcoat::Print(overcoat1, overcoat2);
			overcoat1 == overcoat2;
			break;
		case 3:
			Overcoat::Print(overcoat1, overcoat2);
			overcoat1 = overcoat2;
			cout << "\nRezultat";
			Overcoat::Print(overcoat1, overcoat2);
			break;
		case 4:
			Overcoat::Print(overcoat2, overcoat1);
			overcoat2 = overcoat1;
			cout << "\nRezultat";
			Overcoat::Print(overcoat1, overcoat2);
			break;
		case 5:
			Overcoat::Print(overcoat1, overcoat2);
			overcoat1 > overcoat2;
			break;
		}
	} while (key);
	system("pause");
	return 0;
}

