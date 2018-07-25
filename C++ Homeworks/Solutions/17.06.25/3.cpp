#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<string.h>
#include<ctime>
using namespace std;

struct Directory
{
	int id;
	char document[50];
};
class Queue
{
	Directory queue[20];
	QueueTime timeSaved[20];
	int lastClient = 0;
public:
	void Add(Client tmp,int priority);
	void Delete(int position);
	void Past(int priority);
	void ShowQueueTime();
	void Show();
};
void Queue::Add(Directory tmp,int priority)
{
	if (lastClient < 19)
	{
		Past(priority);
		queue[priority] = tmp;
		timeSaved[priority] = new QueueTime(tmp.id);
	}
	else
		cout << "\nCherha zapovnena! Vydalit document";
}
void Queue::Past(int priority)
{
	Directory tmp;
	for (int i = priority; queue[i].id!=0; ++i)
	{
		tmp = queue[i+1];
		queue[i + 1] = queue[i];
	}
}
void Queue::Delete(int position)
{
	for (int i = position; queue[i].id != 0; i++)
	{
		queue[i] = queue[i + 1];
		timeSaved[i] = timeSaved[i + 1];
	}
}
void Queue::Show()
{
	cout << "\n\t|Cherha|";
	for (int i = 0; queue[i].id != 0; ++i)
	{
		cout << "\n------------------------";
		cout << "\nID:" << queue[i].id
			<< "\nPriorytet:" << i + 1
			<< "\nText:" << queue[i].document;
		cout << "\n------------------------";
	}
}
void Queue::ShowQueueTime()
{
	cout << "\n\t|Cherha|";
	for (int i = 0; timeSaved[i].id != 0; ++i)
	{
		cout << "\n------------------------";
		cout << "\nID:" << timeSaved[i].id
			<< "\nTime:" <<asctime(timeSaved[i].timeSave);
		cout << "\n------------------------";
	}
}
class QueueTime
{
	int id;
	tm* timeSave;
public:
	QueueTime() {};
	QueueTime(int ID);
};
QueueTime::QueueTime(int ID)
{
	id = ID;
	time_t seconds = time(NULL);
	tm* timeSave = localtime(&seconds);
}

int main()
{
	int key, ID=1,priority;
	Queue que;
	do
	{
		cout << "\n--------------------------"
			<< "\n     \\\\\\Menu///"
			<< "\n1 - Dodaty dokument v cherhu"
			<< "\n2 - Vydalyty dokument z cherhy"
			<< "\n3 - Pokazaty cherhu"
			<< "\n4 - Pokazaty statystyku"
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
			Directory client;
			
			client.id = ID;
			ID++;
			cout << "\nid:"<<client.id;
			cout << "\n\nPriorytet(>1&&<20)";
			do
			{
				cin >> priority;
			} while (priority < 1 || priority>20);
			cout << "\nText dlya druku";
			do
			{
				gets_s(client.document);
			} while (!isalpha(client.document[0]));
			que.Add(client, priority);
			break;
		case 2:
			int element;
			que.Show();
			cout << "\nVkazhit element dlya vydalennya:";
			cin >> element;
			que.Delete(element);
			break;
		case 3:
			que.Show();
			break;
		case 4:
			que.ShowQueueTime();
			break;
		}
	} while (key);
	system("pause");
	return 0;
}

