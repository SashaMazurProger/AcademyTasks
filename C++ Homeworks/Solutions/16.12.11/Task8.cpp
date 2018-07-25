#include<iostream>
using namespace std;
void main()
{
	long long a,b;
	cout << "Vvedit tsile chyslo a:";
	cin >> a;
	cout << "Vvedit tsile chyslo b:";
	cin >> b;
	for (int i = -1000000; i <1000000; ++i)
	{
		if (i == 0)
			continue;
		if (a%i==0&&b%i==0)
			cout << i << "\n";
	}
	system("pause");
}