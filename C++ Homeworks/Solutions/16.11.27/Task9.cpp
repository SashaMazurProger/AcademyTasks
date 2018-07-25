#include<iostream>
using namespace std;
void main()
{
	cout << "\t..::Vartist poizdky::..\n";
	float dist, cost,cost0, price1, price2, price3,trip1,trip2,trip3;
	cout << "Vkazhit vidstan(km):\n";
	cin >> dist;
	(dist <= 0)
	{
		cout << "Nemozhlyve znachennia!!!\n";
		cout << "Vkazhit vidstan(km):\n";
		cin >> dist;
	}
	cout << "Vkazhit vytratu benzynu(l/100km):\n";
	cin >> cost;
	while (cost <= 0)
	{
		cout << "Nemozhlyve znachennia!!!\n";
		cout << "Vkazhit vytratu benzynu(l/100km):\n";
		cin >> cost;
	}
		cout << "Vkazhit cinu 1 benzynu:\n";
		cin >> price1;
	while (price1 <= 0)
	{
		cout << "Nemozhlyve znachennia!!!\n";
		cout << "Vkazhit cinu 1 benzynu:\n";
		cin >> price1;
	}
	cout << "Vkazhit cinu 2 benzynu:\n";
	cin >> price2;
	while (price2 <= 0)
	{
		cout << "Nemozhlyve znachennia!!!\n";
		cout << "Vkazhit cinu 2 benzynu:\n";
		cin >> price2;
	}
	cout << "Vkazhit cinu 3 benzynu:\n";
	cin >> price3;
	while (price3 <= 0)
	{
		cout << "Nemozhlyve znachennia!!!\n";
		cout << "Vkazhit cinu 3 benzynu:\n";
		cin >> price3;
	}
	cost0= dist*cost / 100;
	trip1 = cost0 * price1;
	trip2= cost0 * price2;
	trip3= cost0 * price3;
	cout << "\nBenzyn\tVartist poizdky\n";
	cout << "1\t" << trip1<<"\n";
	cout << "2\t" << trip2<<"\n";
	cout << "3\t" << trip3<<"\n";
}	