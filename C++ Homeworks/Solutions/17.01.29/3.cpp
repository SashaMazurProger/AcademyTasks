#include<iostream>
using namespace std;
void func(int a,int x)
{
	int sum;
	cout << "Chyslo"<<"\tDilnyk";
	for (int y= a + 1; y < x; ++y)
	{
		sum = 0;
		for (int i = 1; i <  y; ++i)
		{
			if (y%i == 0)
			{
				sum += i;
				cout << "\n" <<y<<"\t" <<i;
			}
		}
		if (sum == y)
		{
			cout << "\n" << "Chyslo " << y << " idealne!";
		}
		cout << endl;
	}
}
void main()
{
	int a, x;
	cout << "Pochatok diapazonu:";
	cin >> a;
	do
	{
		cout << "\n Kinets(<=100):";
		cin >> x;
	} while (x <= a||x>100);
	func(a, x);
	system("pause");
}