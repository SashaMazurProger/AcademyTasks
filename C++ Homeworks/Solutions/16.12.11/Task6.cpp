#include<iostream>
using namespace std;
void main()
{
	int a, b, c,d, sum = 0;
	bool tf;
	cout << "Vvedit tsile chyslo a:";
	cin >> a;
	while(1)
	{
		b = a%10;
		sum+=b;
		if (a > -10 && a < 10)
		{
			if (a == 1)
				break;
			sum += a;
			break;
		}
		a /= 10;
	}
	if (sum*sum*sum == a*a)
		tf = true;
	else
		tf = false;
	cout << "(Suma tsyfr a)^3=a^2...................... " << boolalpha << tf;
	system("pause");
}