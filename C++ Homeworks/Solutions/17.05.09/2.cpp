#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<string.h>
using namespace std;

class Contact
{
	char FIO[30];
	char HomeTel[10];
	char WorkTel[10];
	char MobileTel[10];
	char About[50];
public:
    Contact(char fio[], char homeTel[], char workTel[], char mobileTel[], char about[])
	{
		int size = strlen(fio);
		char *FIO = new char[size];
		FIO = fio;
		strcpy_s(HomeTel, homeTel);
		strcpy_s(WorkTel, workTel);
		strcpy_s(MobileTel, mobileTel);
		strcpy_s(About, about);
	}
	Contact(char fio[])
	{
		int size = strlen(fio);
		char *FIO = new char[size];
		FIO = fio;
	}
	void SetFIO(char fio[])
	{
		strcpy_s(FIO, fio);
	}
	char* GetFIO()
	{
		return FIO;
	}
	void SetHomeTel(char homeTel[])
	{
		strcpy_s(HomeTel, homeTel);
	}
	char* GetHomeTel()
	{
		return HomeTel;
	}
	void SetWorkTel(char workTel[])
	{
		strcpy_s(WorkTel, workTel);
	}
	char* GetWorkTel()
	{
		return WorkTel;
	}
	void SetMobileTel(char mobileTel[])
	{
		strcpy_s(MobileTel, mobileTel);
	}
	char* GetMobileTel()
	{
		return MobileTel;
	}
	void SetAbout(char about[])
	{
		strcpy_s(About, about);
	}
	char* GetAbout()
	{
		return About;
	}
	Contact()
	{

	}
	~ Contact()
	{
		cout << "Destruktor";
	}
};
void PrintAll(Contact a[],int endIndex)
{
	for (int i = 0; i <=endIndex; ++i)
	{
		if (strlen(a[i].GetFIO()) ==0)
			continue;
		cout << "\n\n#" << i + 1;
		cout << "\n\tFIO:" << a[i].GetFIO();
		cout << "\n\tDomashniy tel.:" << a[i].GetHomeTel();
		cout << "\n\tRobochyy tel.:" << a[i].GetWorkTel();
		cout << "\n\tMobilnyy tel.:" << a[i].GetMobileTel();
		cout << "\n\tOpys:" << a[i].GetAbout();
	}
}
void Print(Contact a)
{
	cout << "\n\tFIO:"<< a.GetFIO();
	cout << "\n\tDomashniy tel.:" << a.GetHomeTel();
	cout << "\n\tRobochyy tel.:" << a.GetWorkTel();
	cout << "\n\tMobilnyy tel.:" << a.GetMobileTel();
	cout << "\n\tOpys:" << a.GetAbout();
}
void AddContact(Contact *arr,int index)
{
	if (index <= 20)
	{
		char tmp[30];
		int key = 1;
		do
		{
			cout << "Vkazhit dani";
			cout << "\n\tFIO:";
			do
			{
				gets_s(tmp);
			} while (!isalpha(tmp[0]));
			arr[index].SetFIO(tmp);
			cout << "\n\tDomashniy tel. :";
			do
			{
				gets_s(tmp);
			} while (!isdigit(tmp[0]));
			arr[index].SetHomeTel(tmp);
			cout << "\n\tRobochyy tel. :";
			do
			{
				gets_s(tmp);
			} while (!isdigit(tmp[0]));
			arr[index].SetWorkTel(tmp);
			cout << "\n\tMobilnyy tel. :";
			do
			{
				gets_s(tmp);
			} while (!isdigit(tmp[0]));
			arr[index].SetMobileTel(tmp);
			cout << "\n\tOpys:";
			do
			{
				gets_s(tmp);
			} while (!isalpha(tmp[0]));
			arr[index].SetAbout(tmp);

			Print(arr[index]);

			cout << "\n\nZberehty?(1-Tak,0-Ni)\n\n";
			do
			{
				cin >> key;
			} while (key != 0 && key != 1);
		} while (!key);
	}
	else
	{
		int key;
		cout << "Zapysnyk zapovnenyy!!!"
			<< "\nVkazhit nomer kontaktu dlya zaminy:";
		do
		{
			cin >> key;
		} while (key < 1 || key>20);
		AddContact(arr, key - 1);
	}
}
void PoshukFIO(Contact *arr,char search[])
{
	int count = 0;
	for (int i = 0; i < 30; ++i)
	{
		count = 0;
		for (int e = 0; e < strlen(search); ++e)
		{
			if (arr[i].GetFIO()[e] != search[e])
				break;
			else
				++count;
		}
		if (count == strlen(search))
		{
			cout << "\nTaki FIO maye " << i + 1 << "-y contakt";
			Print(arr[i]);
			return;
		}
	}
	cout << "\nContakt z takym FIO ne znaydeno";
}
void DeleteContact(Contact *contacts,int index)
{
	/*delete contacts[index];*/
	/*contacts[index] = NULL;*/
	contacts[index].SetFIO("");
	contacts[index].SetHomeTel("");
	contacts[index].SetMobileTel("");
	contacts[index].SetWorkTel("");
	contacts[index].SetAbout("");
	cout << "\nContakt vydaleno";
}
void main()
{
	Contact *arr = new Contact[20];
	int key,countContact=0;
	char searchFIO[30];
	cout << "\t\t***Contacts***";
	do
	{
		cout << "\n\n\t\t     \\\\\\Menu///"
			<< "\n\t\t1 - Dodaty contakt"
			<< "\n\t\t2 - Perehlyanuty vsi contakty"
			<< "\n\t\t3 - Poshuk contaktu za FIO"
			<< "\n\t\t4 - Vydalyty contakt"
			<< "\n\n\t\t0 - Vyhid";
		do
		{
			cout << "\n\n\nZrobit vash vybir";
			cin >> key;
		} while (key != 0 && key != 1 && key != 2 &&
			key != 3&&key!=4);
		switch (key)
		{
		case 1:
			AddContact(arr, countContact);
			++countContact;
			break;
		case 2:
			if (countContact == 0)break;
			PrintAll(arr,countContact-1);
			break;
		case 3:
			cout << "\nVkazhit FIO:";
			do
			{
				gets_s(searchFIO);
			} while (!isalpha(searchFIO[0]));
			PoshukFIO(arr,searchFIO);
			break;
		case 4:
			cout << "Vkazhit nomer kontaktu:";
			do
			{
				cin >> key;
			} while (key < 1 || key>20);
			DeleteContact(arr,key-1);
		}
	} while (key);
	system("pause");
}



