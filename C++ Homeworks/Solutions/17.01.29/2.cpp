 #include<iostream>
using namespace std;
int func(int a, int x)
{
	int sum = 0;
	for (int i = a+1; i < x; ++i)
	{
		sum+= i;
	}
	return sum;
}
void main()
{
	int a, x;
		cout << "Pochatok diapazonu:";
		cin >> a;
	do
	{
		cout << "\n Kinets:";
		cin >> x;
	} while (x<=a);
	cout << "\n  Result:" << func(a, x) << endl << endl;
	system("pause");
}