#include<iostream>
using namespace std;
void main()
{
	long long a;
	cout << "Vvedit tsile chyslo:";
	cin >> a;
	for (int i = -1000000; i <1000000; ++i)
	{
		if (i == 0)
			continue;
		if (a%i==0)
			cout << i << "\n";
	}
	system("pause");
}