#include<iostream>
#include<iomanip>
#include<time.h>
#include<vector>
using namespace std;
void main()
{
	srand(time(0));
	int numbers[10];
	vector<int>square(10);
	vector<int>::iterator iter;
	iter = square.begin();
	cout << "\nNumbers    Square";
	for (int i = 0; iter != square.end()&&i<10; ++iter)
	{
		numbers[i] = rand() % 15;
		*iter = numbers[i] * numbers[i];
		cout << "\n  " << numbers[i] << "\t     " << *iter;
	}
	system("pause");
}