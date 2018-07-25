#include<iostream>
using namespace std;
void main()
{
    long long a;
	cout << "Vvedit tsile chyslo:";
	cin >> a;
	for (long long i = -100000; i <100000; ++i)
	{
		if (i == 0)
			continue;
		if (a % (i*i) == 0 && a % (i*i*i) != 0)
		{
			cout << i << "\n";
		}
	}
	system("pause");
}