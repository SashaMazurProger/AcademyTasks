#include<iostream>
using namespace std;
void main()
{	
	float r0,r1,r2,r3;
	cout << "\t\t::[Opir]::\n";
    cout << "Vkazhit opir:\n\n"
		   << "\t\tR1:";
	cin >> r1;
	while (r1<=0)
	{
		cout << "Nemozhlyve znachennya!!!\n"
		<< "\tR1:";
		cin >> r1;
	}
	cout << "\t\tR2:";
	cin >> r2;
	while (r2 <= 0)
	{
		cout << "Nemozhlyve znachennya!!!\n"
			<< "\tR2:";
		cin >> r2;
	}
	cout << "\t\tR3:";
	cin >> r3;
	while (r3<= 0)
	{
		cout << "Nemozhlyve znachennya!!!\n"
			<< "\tR3:";
		cin >> r3;
	}
	r0 = 1 / (1 / r1 + 1 / r2 + 1 / r3);
	cout << "\nR0= "<<r0;
}