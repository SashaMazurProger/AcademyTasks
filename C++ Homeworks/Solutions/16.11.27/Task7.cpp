#include<iostream>
using namespace std;
void main()
{
	float time, dist, speed;
	cout << "\t\.\.\:\:Speed\:\:\.\.\n";
	cout << "Vkazhit chas(hour):\n";
	cin >> time;
	while (time <= 0)
	{
		cout << "Nemozhlyve znachennia!!!\n";
		cout << "Vkazhit chas(hour):\n";
		cin >> time;
	}
	cout << "Vkazhit vidstan(km):\n";
	cin >> dist;
	while (dist <= 0)
	{
		cout << "Nemozhlyve znachennia!!!\n";
		cout << "Vkazhit vidstan(km):\n";
		cin >> dist;
	}
		speed = dist / time;
		cout << "Optymalna shvydkist: " << speed<<" km/h\n";
		cout << "Vdaloho polyotu;)";
}
