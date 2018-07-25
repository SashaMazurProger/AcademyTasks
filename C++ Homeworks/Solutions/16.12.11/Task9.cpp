#include<iostream>
using namespace std;
void main()
{
	int y,a, b, k = 0,k0=0, sum = 0;
	do
	{
		cout << "Vvedit tsile chyslo:";
		cin >> a;
		while (1)
		{
			b = a % 10;
			++k;
			if (b == 0)
				++k0;
			if (a > -10 && a < 10)
			{
				sum += a;
				break;
			}
			sum += b;
			a /= 10;
		}
		cout << " 0 - Vse;\n"
			<< " 1 - Suma tsyfr;\n "
			<< "2 - Kil'kist tsyfr;\n"
			<< " 3 - Kil'kist nuliv;\n"
			<< " 4 - Serednye aryphmetychne;\n"
			<< " 5 - Vyhid;" << endl;
		cin >> y;
		switch (y)
		{
		case 0:
			cout << "\t\tZnachennya\n "
				<< "Suma tsyfr\t    " << sum << endl;
			cout <<"\n K-st tsyfr\t    " << k << endl;
			cout <<"\n K-st nuliv\t    " << k0 << endl;
			cout <<"\n Ser. aryph.\t    " << (double)sum / k << endl;
			break;
		case 1:
			cout << "\t\tZnachennya\n "
				<< "Suma tsyfr\t    " << sum << endl;
			break;
		case 2:
			cout << "\t\tZnachennya\n "
				<< "K-st tsyfr\t    " << k << endl;
			break;
		case 3:
			cout << "\t\tZnachennya\n "
				<< "\nK-st nuliv\t    " << k0 << endl;
			break;
		case 4:
			cout << "\t\tZnachennya\n "
				<< "\nSer. aryph.\t    " << (double)sum / k << endl;
			break;
		case 5:
			cout << "Bye...";
			break;
		default:
			cout << "Nemozhlyve znachennya!!!";
		}
	} while (y != 5);
	system("pause");
}