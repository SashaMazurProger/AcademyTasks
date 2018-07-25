//"Schaslyvi" chysla
/*
#include<iostream>
using namespace std;
bool func(int mas[],int size)
{
	for (int i = 0; i < size; ++i)
	{
		if(mas[i]%2==0)
		mas[i] =0;
	}
	int countIteration = 0, indexOff = 0, countElemNotZero = 0;
	for (int iterationNumb = 2; iterationNumb < size; ++iterationNumb)
	{
		countIteration = 0, indexOff = 0,countElemNotZero=0;
		for (int a = 0; countIteration != iterationNumb&&a<size; ++a)
		{
			if (mas[a] != 0)
			{
				++countIteration;
				indexOff = a;
			}
		}
		for (int e = 0; e < size; ++e)
		{
			if (mas[e] != 0)
			{
				++countElemNotZero;
			}
			if (countElemNotZero == mas[indexOff])
			{
				mas[e] = 0;
				countElemNotZero = 0;
			}
		}
	}
	for (int i = 0; i < size; ++i)
	{
		if (mas[i] != 0)
		{
			cout << "  " << mas[i];
		}
	}
	return mas[size - 1] ? true : false;
}
void main()
{
	const int size = 1000;
	int mas[size];
	for (int i = 0; i < size; ++i)
	{
		mas[i] = i + 1;
	}
	cout<<"Chyslo \"schaslyve\":"<<boolalpha<<func(mas,size);
	system("pause");
}
*/
#include<iostream>
using namespace std;
bool func(int numb)
{
	const int size = 6;
	int ar[size];
	for (int i = 0, numbZero = 100000; i < size-1; numbZero /= 10, ++i)
	{
		ar[i] = numb / numbZero;
		numb -= ar[i] * numbZero;
		if (numb < 10)
		{
			ar[i + 1] = numb;
		}
	}
	return (ar[0] + ar[1] + ar[2]) == (ar[3] + ar[4] + ar[5])?true:false;
}
void main()
{
	int numb;
	do
	{
		do
		{
			cout << "6-znachne chyslo:";
			cin >> numb;
		} while (numb < 100000 || numb >= 1000000);
		cout << "Chyslo schaslyve:" << boolalpha << func(numb)<<"\n\n";
	} while (true);
	system("pause");
}

