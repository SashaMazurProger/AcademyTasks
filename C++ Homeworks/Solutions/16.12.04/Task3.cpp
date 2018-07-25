#include<iostream>
using namespace std;
void main()
{
	int x = 1, y = 1000, sum = 0;
	while (x <= 1000)
	{
		sum += x;
		++x;
	}
	cout << "Serednye aryphmetychne:" << (float)sum / 1000;
	system("pause");
}