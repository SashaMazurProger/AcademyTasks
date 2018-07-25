#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<string.h>
#include<thread>
using namespace std;

class Directory
{
	char name[30];
	char owner[30];
	char tel[20];
	char address[50];
	char line[30];
public:
	Directory()
	{
	}
	void SetName(char p[])
	{
		strcpy_s(name,p);
	}
	char* GetName()
	{
		return name;
	}
	void SetOwner(char p[])
	{
		strcpy_s(owner, p);
	}
	char* GetOwner()
	{
		return owner;
	}
	void SetTel(char p[])
	{
		strcpy_s(tel, p);
	}
	char* GetTel()
	{
		return tel;
	}
	void SetAddress(char p[])
	{
		strcpy_s(address, p);
	}
	char* GetAddress()
	{
		return address;
	}
	void SetLine(char p[])
	{
		strcpy_s(line, p);
	}
	char* GetLine()
	{
		return line;
	}
	~Directory()
	{
		cout << "Destructor";
	}
};
 void Print(Directory n,int position)
{
	cout << "------------------------";
	cout << "\n#" << position;
	cout << "\nNazva firmy:" << n.GetName();
	cout << "\nVlasnyk:" << n.GetOwner();
	cout << "\nTelefon:" << n.GetTel();
	cout << "\nAdres:" << n.GetAddress();
	cout << "\nRid diyalnosti:" << n.GetLine();
	cout << "------------------------";
}
void PrintAll(Directory n[], int size)
 {
	for (int i = 0; i < size; ++i)
	{
		cout << "------------------------";
		cout << "\n#" <<i+1;
		cout << "\nNazva firmy:" << n[i].GetName();
		cout << "\nVlasnyk:" << n[i].GetOwner();
		cout << "\nTelefon:" << n[i].GetTel();
		cout << "\nAdres:" << n[i].GetAddress();
		cout << "\nRid diyalnosti:" << n[i].GetLine();
		cout << "------------------------";
	}
 }
void Search(Directory *arr, char search[],int size)
{
	int count = 0;
	for (int i = 0; i<size; ++i)
	{
		count = 0;
		for (int e = 0; e < strlen(search); ++e)
		{
			if (arr[i].GetName()[e] != search[e])
				break;
			else
				++count;
		}
		if (count == strlen(search))
		{
			cout << "\nTaki dani maye " << i + 1 << "-a firma";
			Print(arr[i],i+1);
			continue;
		}
		count = 0;
		for (int e = 0; e < strlen(search); ++e)
		{
			if (arr[i].GetOwner()[e] != search[e])
				break;
			else
				++count;
		}
		if (count == strlen(search))
		{
			cout << "\nTaki dani maye " << i + 1 << "-a firma";
			Print(arr[i], i + 1);
			continue;
		}
		count = 0;
		for (int e = 0; e < strlen(search); ++e)
		{
			if (arr[i].GetTel()[e] != search[e])
				break;
			else
				++count;
		}
		if (count == strlen(search))
		{
			cout << "\nTaki dani maye " << i + 1 << "-a firma";
			Print(arr[i], i + 1);
			continue;
		}
		count = 0;
		for (int e = 0; e < strlen(search); ++e)
		{
			if (arr[i].GetAddress()[e] != search[e])
				break;
			else
				++count;
		}
		if (count == strlen(search))
		{
			cout << "\nTaki dani maye " << i + 1 << "-a firma";
			Print(arr[i], i + 1);
			continue;
		}
		count = 0;
		for (int e = 0; e < strlen(search); ++e)
		{
			if (arr[i].GetLine()[e] != search[e])
				break;
			else
				++count;
		}
		if (count == strlen(search))
		{
			cout << "\nTaki dani maye " << i + 1 << "-a firma";
			Print(arr[i], i + 1);
		}
	}
	cout << "\nFirm z takymy danymy ne znaydeno";
}
void Add(Directory *d,int count)
{
	char tmp[50];
	cout << "\nNazva:";
	do
	{
		gets_s(tmp);
	} while (!isalpha(tmp[0]));
	d[count].SetName(tmp);
	cout << "\nVlasnyk:";
	do
	{
		gets_s(tmp);
	} while (!isalpha(tmp[0]));
	d[count].SetOwner(tmp);
	cout << "\nAdres:";
	do
	{
		gets_s(tmp);
	} while (!isalpha(tmp[0]));
	d[count].SetAddress(tmp);
	cout << "\nTelefon:";
	do
	{
		gets_s(tmp);
	} while (!isalpha(tmp[0]));
	d[count].SetTel(tmp);
	cout << "\nRid diyalnosti:";
	do
	{
		gets_s(tmp);
	} while (!isalpha(tmp[0]));
	d[count].SetLine(tmp);
}
int main()
{
	Directory d[10];
	int count = 0;
	char tmp[50];
	int key;
	do
	{
		cout << "\n--------------------------"
			<< "\n     \\\\\\Menu///"
			<< "\n1 - Dodaty firmu"
			<< "\n2 - Pokazaty spysok"
			<< "\n3 - Poshuk po parametru"
			<< "\n\n0 - Vyhid"
			<< "\n--------------------------\n";
		do
		{
			cout << "\nZrobit vash vybir";
			cin >> key;
		} while (key<0 || key>4);
		switch (key)
		{
		case 1:
			if(count<10)
			{
				Add(d,count);
			    ++count;
		    }
			else
			{
				cout << "Spravochnyk zapovneno";
			}
			break;
		case 2:
			PrintAll(d,10);
			break;
		case 3:
			cout << "\nPoshuk:";
			do
			{
				gets_s(tmp);
			} while (!isalpha(tmp[0]));
			thread t(Search, d, tmp, 10);
			if (t.joinable())
				t.join();
			break;
		}
	} while (key);
	system("pause");
	return 0;
}




















