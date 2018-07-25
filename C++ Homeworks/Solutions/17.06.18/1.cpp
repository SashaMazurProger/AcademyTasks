#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<string.h>
#include<time.h>
#include <conio.h>
#include <windows.h>
using namespace std;
void ShowAnim();
struct Element
{
	int numb;
	Element* next;
};
class List
{
	Element *Head;
	Element *Tail;
public:
	int sum;
	List();
	~List();
	int Add(int numb);
};
List::List()
{
	Head = NULL;
	sum = 0;
}
List::~List()
{
	while (Head != NULL)
	{
		Element *temp = Head->next;
		delete Head;
		Head = temp;
	}
}
int List::Add(int numb)
{
	Element *tmp = new Element;
	tmp->numb = numb;
	tmp->next = NULL;
	if (Head != NULL)
	{
		Tail->next = tmp;
		Tail = tmp;
	}
	else
		Head = Tail = tmp;
	sum += tmp->numb;
	ShowAnim();
	return numb;
}
void ShowAnim()
{
	cout << "\n";
		for (int i = 0; i < 3; ++i)
		{
			cout << ".";
			Sleep(200);
		}
}

int Random()
{
	return rand() % 11 + 1;
}
int main()
{
	srand((unsigned)time(NULL));
	int key,lastNumb;
	do
	{
		List player;
		List dealer;
		cout << "\n--------------------------"
			<< "\n     \\\\\\Menu///"
			<< "\n1 - Pochaty gru"
			<< "\n\n2 - Vyhid"
			<< "\n--------------------------\n";
		cin >> key;
		if (key != 2)
		{
			lastNumb = Random();
			dealer.Add(lastNumb);
			lastNumb = Random();
			player.Add(lastNumb);
			lastNumb = Random();
			player.Add(lastNumb);
			if (player.sum == 21)
			{
				cout << "\nSuma:" << player.sum
					<< "\nBLACKJACK!!!VY VYGRALY";
				key = 0;
				break;
			}
			do
			{
				system("cls");
				cout << "\nVasha suma:" << player.sum
					<< "\nSuma dylera:" << dealer.sum;
				if (dealer.sum < 17)
				{
					lastNumb = Random();
					dealer.Add(lastNumb);
				}
				if (dealer.sum > 21)
				{
					cout << "\nSuma:" << dealer.sum
						<< "\nVY VYGRALY!!!";
					key = 0;
					break;
				}
				else if (dealer.sum == 21)
				{
					cout << "\nSuma:" << dealer.sum
						<< "\nBLACKJACK U DYLERA!!!VY PROGRALY";
					key = 0;
					break;
				}
				cout << "\n--------------------------"
					<< "\n1 - Zupynytysya"
					<< "\n2 - Uzyaty shche kartu"
					<< "\n3 - Vidmovytysya vid gry(0.5 stavky)"
					<< "\n4 - Podvoyity"
					<< "\n--------------------------\n";
				do
				{
					cout << "\nZrobit vash vybir";
					cin >> key;
				} while (key < 1 || key>4);
				switch (key)
				{
				case 1:
					cout << "\n.................\n";
					if (dealer.sum > 17&&player.sum>dealer.sum)
					{
						cout << "\nSuma:" << player.sum
							<< "\nBLACKJACK!!!VY VYGRALY";
						key = 0;
						break;
					}
					break;
				case 2:
					lastNumb = Random();
					player.Add(lastNumb);
					if (player.sum > 21)
					{
						cout <<"\nSuma:"<<player.sum
							<< "\nPEREBIR!!!VY PROGRALY";
						key = 0;
					}
					else if (player.sum == 21)
					{
						cout << "\nSuma:" << player.sum
							<< "\nBLACKJACK!!!VY VYGRALY";
						key = 0;
					}
					else
					{
						cout << "\nVypalo:" << lastNumb;
						Sleep(1000);
					}
					break;
				case 3:
					cout << "Vy vidmovytylysya vid gry(0.5 stavky)";
					key = 0;
					break;
				case 4:

					break;
				}
			} while (key);
		}
		}while (key!=2);
system("pause");
return 0;
}
