#include<iostream>
using namespace std;
void main()
{	
	int hour0, min0, hour1, min1,price;
	float sec0, sec1,minute0,minute1,pricem = 0.3;
	cout << "\t\t::[Vartist dzvinka]::\n";
    cout << "Vkazhit pochatok dzvinka:\n"
		   << "\tHodyn:";
	cin >> hour0;
	cout << "\tHvylyn:";
	cin >> min0;
	cout << "\tSecund:";
	cin >> sec0;
	cout << "Vkazhit kinec dzvinka:\n"
		<< "\tHodyn:";
	cin >> hour1;
	while(hour1 < hour0)
	{
		cout << "Nemozhlyve znachennia!!!\n";
		cout << "Vkazhit kinec dzvinka:\n"
			<< "\tHodyn:";
		cin >> hour1;	
	}
	cout << "\tHvylyn:";
	cin >> min1;
	while (hour1 == hour0&min1<=min0)
	{
		cout << "Nemozhlyve znachennia!!!\n";
		cout << "Vkazhit kinec dzvinka:\n"
			<< "\tHvylyn:";
		cin >> min1;
	}
	cout << "\tSecund:";
	cin >> sec1;
	minute0 = hour0 * 60 + min0 + sec0 / 60;
	minute1 = hour1 * 60 + min1 + sec1 / 60;
	price = minute1 - minute0;
	cout << "\nVartist dzvinka:"<<(float)price*pricem<<" grn";
}