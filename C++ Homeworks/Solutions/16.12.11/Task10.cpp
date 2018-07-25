#include<iostream>
using namespace std;
void main()
{
    int size,a=0;
	cout << "Vkazhit rozmir:";
	cin >> size;
	for(int i=0;i<8;++i,++a)
	{
		if (a % 2 == 0)
		{
			for (int i = 0; i < size; ++i)
			{
				for (int i = 0; i < 4; ++i)
				{
					for (int i = 0; i < size; ++i)
						cout << "*";
					for (int i = 0; i < size; ++i)
					{
						cout << "_";
					}
				}
				cout << "\n";
			}
		}
		else
		{
			for (int i = 0; i < size; ++i)
			{
				for (int i = 0; i < 4; ++i)
				{
					for (int i = 0; i < size; ++i)
					{
						cout << "_";
					}
					for (int i = 0; i < size; ++i)
						cout << "*";
				}
				cout << "\n";
			}
		}
	}
	system("pause");
}