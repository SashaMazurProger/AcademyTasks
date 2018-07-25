#include<iostream>
using namespace std;

class Passport
{
	char FIO[30];
	char Birthday[20];
	int Age;
	char SerialNumb[10];
	char Address[20];
public:
	Passport()
	{
	}
	void SetFIO(char p[])
	{
		strcpy_s(FIO,p);
	}
	char* GetName()
	{
		return FIO;
	}
	void SetBirthday(char p[])
	{
		strcpy_s(Birthday, p);
	}
	char* GetBirthday()
	{
		return Birthday;
	}
	void SetAge(int a)
	{
		Age = a;;
	}
	int GetAge()
	{
		return Age;
	}
	void SetSerNumb(char p[])
	{
		strcpy_s(SerialNumb, p);
	}
	char* GetSerNumb()
	{
		return SerialNumb;
	}
	void SetAddress(char p[])
	{
		strcpy_s(Address, p);
	}
	char* GetAddress()
	{
		return Address;
	}
};
class ForeignPassport :public Passport
{
	char NumbVisa[20];
	char TypeVisa[10];
	char NumbForeignPass[10];
 };
int main()
{
	system("pause");
	return 0;
}




















