#include<iostream>
using namespace std;
void main()
{
	int x,y,a;
	cout << "Vvedit chyslo:";
	cin >> x;
	cout << "Vvedit stepin:";
	cin >> y;
	if (y > 0)
	{
		a = x;
		while (y > 1)
		{
			a *= x;
			--y;
		}
		cout << "Resultat:" << a;
	}
	else if(y==0)
	{
		cout << "Resultat:" << 1;
	}
	else
	{
		a = x;
		while (y < -1)
		{
			a *= x;
			++y;
		}
		cout << "Resultat:" << (double)1/a;
	}
	system("pause");
}
