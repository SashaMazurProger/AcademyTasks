#include<iostream>
using namespace std;
void main()
{	
	float l,r,p=3.14;
	cout << "\t\t::[Ploshcha]::\n";
    cout << "Vkazhit dovzhynu kruha:\n"
		   << "\tL:";
	cin >> l;
	while (l<=0)
	{
		cout << "Nemozhlyve znachennia!!!\n"
		<< "\tL:";
		cin >> l;
	}
	r = l / (2 * p);
	cout << "\nPloshcha kruha: " << p*r*r;
}