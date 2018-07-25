#include<iostream>
using namespace std;
void main()
{
	int a, b, max, min, maxm, minm;
	const int size = 12;
	int m[size];
	for (int i = 0; i < size; ++i)
	{
		do {
			cout << "Dohid za " << i + 1 << " misyats:" << endl;
			cin >> m[i];
		} while (m[i] < 0);
	}
	do
	{
		cout << "Vvedit pochatok diapazonu: " << endl;
		cin >> a;
	} while (a < 1 || a>12);
	do
	{
		cout << "Vvedit kinets diapazonu: " << endl;
		cin >> b;
	} while (b < 1 || b>12 || b <= a);
	max = m[a - 1];
	min = m[a - 1];
	maxm = a;
	minm = a;
	for (int i = a; i <= b; ++i)
	{
		if (max < m[i - 1])
		{
			max = m[i - 1];
			maxm = i;
		}
		if (min > m[i - 1])
		{
			min = m[i - 1];
			minm = i;
		}
	}
	cout << "min: " << minm << "\tmax: " << maxm;
	system("pause");
}