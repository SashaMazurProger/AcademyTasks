#include<iostream>
using namespace std;
void main()
{	
	float v,t,a;
	cout << "\t\t::[Vidstan]::\n";
    cout << "Vkazhit pochtkovu shvydkist(m/s):\n"
		   << "\tV:";
	cin >> v;
	while (v<0)
	{
		cout << "Nemozhlyve znachennia!!!\n"
		<< "\tV:";
		cin >> v;
	}
	cout << "Vkazhit chas ruhu(s):\n"
		<< "\tT:";
	cin >> t;
	while (t<=0)
	{
		cout << "Nemozhlyve znachennia!!!\n"
			<< "\tT:";
		cin >> t;
	}
	cout << "Vkazhit pryshvydchennia(m/s^2):\n"
		<< "\tA:";
	cin >> a;
	while (a<0)
	{
		cout << "Nemozhlyve znachennia!!!\n"
			<< "\tA:";
		cin >> a;
	}
	cout << "\nVidstan: " << v*t+(a*t*t)/2<<"m";
}