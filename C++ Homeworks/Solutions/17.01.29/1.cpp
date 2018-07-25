#include<iostream>
using namespace std;
void func(int a, int x)
{
	int res = 1;
	for (int i = 0; i < x; ++i)
	{
		res *= a;
	}
	cout << "\n  Result:"<<res<<endl<<endl;
}
void main()
{
	int a, x;
		cout << "Chyslo:";
		cin >> a;
	do
	{
		cout << "\nStepin:";
		cin >> x;
	} while (x <= 1);
	func(a, x);
	system("pause");
}