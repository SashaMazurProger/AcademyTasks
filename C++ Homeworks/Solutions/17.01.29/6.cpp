#include<iostream>
using namespace std;
void func(int oldYear, int oldMonth, int oldDay, int Year, int Month, int Day)
{
	int timeDay = (Year * 365 + Month * 30 + Day) - (oldYear * 365 + oldMonth * 30 + oldDay);
	cout << "\n\nMynulo "<<timeDay<<" dniv...";
}
void main()
{
	int oldYear, oldMonth, oldDay, Year, Month, Day;
	cout << "Pochatok vidliku:";
	cout << "\n  Year:";
	cin >> oldYear;
	cout << "\n  Month:";
	cin >> oldMonth;
	cout << "\n  Day:";
	cin >> oldDay;
	cout << "\nKinets:";
	do
	{
		cout << "\n  Year:";
		cin >> Year;
	} while (Year<oldYear);
	do
	{
		cout << "\n  Month:";
		cin >> Month;
	} while (Year==oldYear&&Month<oldMonth);
	do
	{
		cout << "\n  Day:";
		cin >> Day;
	} while (Year == oldYear&&Month==oldMonth&&Day<oldDay);
	func(oldYear, oldMonth, oldDay, Year, Month, Day);
	system("pause");
}