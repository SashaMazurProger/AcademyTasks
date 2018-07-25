#include<iostream>
using namespace std;
void A();
void B();
void C();
void D();
void E();
void F();
void G();
void H();
void I();
void J();
void main()
{
	int size;
	char var;
	do
	{
		cout << "Zrobit vybir:\n"
			<< "\tA...H - pokaz figury\n"
			<< "\tX - vyhid\n";
		cin >> var;
		switch (var)
		{
		case'a':
		case'A':
			A();
			break;
		case'b':
		case'B':
			B();
			break;
		case'c':
		case'C':
			C();
			break;
		case 'd':
		case'D':
			D();
			break;
		case 'e':
		case 'E':
			E();
			break;
		case 'f':
		case 'F':
			F();
			break;
		case 'g':
		case'G':
			G();
			break;
		case 'h':
		case'H':
			H();
			break;
		case 'i':
		case'I':
			I();
			break;
		case 'j':
		case'J':
			J();
			break;
		case'x':
		case'X':
			cout << "Bye...";
			break;
		default:
			cout << "Nemozhlyve znachennya!!!\n";
			break;
		}
	} while (var != 'x' && var != 'X');
	system("pause");
}
void A()
{
	for (int i = 0; i < 30; ++i)
	{
		cout << "_";
	}
	cout << "\n";
	for (int i = 0, b = 0, c = 0, d = 30, e = 30; i < 30; ++i, ++b, --d)
	{
		c = b;
		if (c < 29)
		{
			for (; c > 0; --c)
			{
				cout << " ";
			}
		}
		e = d;
		for (; e > 0; --e)
		{
			if (d == 1)
			{
				for (int i = 0; i < 29; ++i)
					cout << "_";
			}
			cout << "*";
		}
		cout << "|\n";
	}
	cout << "\n";
}
void B()
{
	for (int i = 0; i < 30; ++i)
	{
		cout << "_";
	}
	cout << "\n";
	for (int i = 0, b = 0, c, d = 30, e = 30; i < 30; ++i, ++b, --d)
	{
		c = b;
		if (c < 30)
		{
			for (; c > -1; --c)
			{
				cout << "*";
			}
		}
		e = d;
		for (; e > 1; --e)
		{
			cout << " ";
		}
		cout << "|\n";
	}
	cout << "\n";
}
void C()
{
	for (int i = 0; i < 30; ++i)
	{
		cout << "_";
	}
	cout << "\n";
	for (int i = 0, b = 0, c = 0, d = 30, e = 30; i < 29; ++i, d -= 2)
	{
		c = b;
		if (c < 15)
		{
			for (; c > 0; --c)
			{
				cout << " ";
			}
		}
		e = d;
		for (; e > 0; --e)
		{
			cout << "*";
		}
		c = b;
		if (c < 15)
		{
			for (; c > 0; --c)
			{
				cout << " ";
			}
		}
		c = b;
		if (c == 30)
		{
			for (; c > 0; --c)
			{
				cout << " ";
			}
		}
		if (b <= 13)
			++b;
		else
			b = 30;
		cout << "|\n";
	}
	for (int i = 0; i < 30; ++i)
		cout << "_";
	cout << "|\n";
}
void D()
{
	for (int i = 0; i < 30; ++i)
	{
		cout << "_";
	}
	cout << "\n";
	for (int i = 0, b = 0, c = 0, d = 0, e = 30; i < 30; ++i)
	{
		if (i <= 14)
			b = 15;
		else if (i == 15)
			b = 14;
		else
			--b;
		c = b;
		for (; c > 0; --c)
		{
			cout << " ";
		}
		if (i == 15)
			d = 2;
		else
			d += 2;
		e = d;
		if (i >= 15)
		{
			for (; e > 0; --e)
				cout << "*";
		}
		c = b;
		for (; c > 0; --c)
			cout << " ";
		cout << "|\n";
	}
	cout << endl;
}
void E()
{
	for (int i = 0; i < 30; ++i)
	{
		cout << "_";
	}
	cout << "\n";
	for (int i = 0, b = 0, c = 0, d = 30, e = 30; i < 15; ++i, d -= 2)
	{
		c = b;
		if (c < 15)
		{
			for (; c > 0; --c)
			{
				cout << " ";
			}
		}
		e = d;
		for (; e > 0; --e)
		{
			cout << "*";
		}
		c = b;
		if (c < 15)
		{
			for (; c > 0; --c)
			{
				cout << " ";
			}
		}
		c = b;
		if (c == 30)
		{
			for (; c > 0; --c)
			{
				cout << " ";
			}
		}
		if (b <= 13)
			++b;
		else
			b = 30;
		cout << "|\n";
	}
	for (int i = 0, b = 14, c = 0, d = 2, e = 0; i <15; ++i, --b, d += 2)
	{
		c = b;
		for (; c > 0; --c)
		{
			cout << " ";
		}
		e = d;
		for (; e > 0; --e)
			cout << "*";
		c = b;
		for (; c > 0; --c)
			cout << " ";
		cout << "|\n";
	}
}
void F()
{
	for (int i = 0; i < 30; ++i)
	{
		cout << "_";
	}
	cout << "\n";
	for (int i = 0, b = 0, c = 0, d = 30, e = 30; i < 15; ++i, d -= 2)
	{
		c = b;
		if (c < 15)
		{
			for (; c > 0; --c)
			{
				cout << "*";
			}
		}
		e = d;
		for (; e > 0; --e)
		{
			cout << " ";
		}
		c = b;
		if (c < 15)
		{
			for (; c > 0; --c)
			{
				cout << "*";
			}
		}
		c = b;
		if (c == 30)
		{
			for (; c > 0; --c)
			{
				cout << "*";
			}
		}
		if (b <= 13)
			++b;
		else
			b = 30;
		cout << "|\n";
	}
	for (int i = 0, b = 14, c = 0, d = 2, e = 0; i <14; ++i, --b, d += 2)
	{
		c = b;
		for (; c > 0; --c)
		{
			cout << "*";
		}
		e = d;
		for (; e > 0; --e)
			cout << " ";
		c = b;
		for (; c > 0; --c)
			cout << "*";
		cout << "|\n";
	}
	for (int i = 0; i < 30; ++i)
		cout << "_";
	cout << "|" << endl;
}
void G()
{
	for (int i = 0; i < 30; ++i)
	{
		cout << "_";
	}
	cout << "\n";
	for (int i = 0, b = 0, c, d = 30, e = 30; i < 29; ++i)
	{
		if (i <= 14)
			++b;
		else
			--b;
		c = b;
		for (; c > 0; --c)
			cout << "*";
		if (i <= 14)
			--d;
		else
			++d;
		e = d;
		for (; e > 0; --e)
		{
			cout << " ";
		}
		cout << "|\n";
	}
	for (int i = 0; i < 30; ++i)
		cout << "_";
	cout << "|\n";
}
void H()
{
	for (int i = 0; i < 30; ++i)
	{
		cout << "_";
	}
	cout << "\n";
	for (int i = 0, b = 0, c, d = 30, e = 30; i < 29; ++i)
	{
		if (i <= 14)
			--d;
		else
			++d;
		e = d;
		for (; e > 0; --e)
		{
			cout << " ";
		}
		if (i <= 14)
			++b;
		else
			--b;
		c = b;
		for (; c > 0; --c)
			cout << "*";
		cout << "|\n";
	}
	for (int i = 0; i < 30; ++i)
		cout << "_";
	cout << "|\n";
}
void I()
{
	for (int i = 0; i < 30; ++i)
	{
		cout << "_";
	}
	cout << "\n";
	for (int i = 0, b = 0, c = 0, d = 30, e = 30; i < 30; ++i, ++b, --d)
	{
		e = d;
		for (; e > 0; --e)
		{
			cout << "*";
		}
		c = b;
		if (c < 29)
		{
			for (; c > 0; --c)
				cout << " ";
		}
		if (d == 1)
		{
			for (int i = 0; i < 29; ++i)
				cout << "_";
		}
		cout << "|\n";
	}
	cout << "\n";
}
void J()
{
	for (int i = 0; i < 30; ++i)
	{
		cout << "_";
	}
	cout << "\n";
	for (int i = 0, b = 0, c = 0, d = 30, e = 30; i < 30; ++i, ++b, --d)
	{
		e = d;
		for (; e > 0; --e)
		{
			cout << " ";
		}
		c = b;
		if (c < 30)
		{
			for (; c > 0; --c)
				cout << "*";
		}
		cout << "|\n";
	}
	cout << "\n";
}