#include<iostream>
#include<iomanip>
using namespace std;
void Print(float array[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout <<setw(3)<< array[i] << " ";
	}
}
void New(float array[], int i, float n)
{
	array[i - 1] = n;
}
bool Stype(float array[], int size)
{
	bool tf;
	float sum = 0,res;
	for (int i = 0; i < size;++i)
	{
		sum += array[i];
	}
	res = sum / size;
	cout << "Ser.aryph. :" << res<<"\n";
	tf = res >= 10.7 ? true : false;
	return tf;
}
void main()
{
	int key,arrE;
	const int size = 10;
	float arr[size], newE;
	for (int i = 0; i < size; ++i)
	{
		do
		{
			cout << "Otsinka " << i + 1 << ":";
			cin >> arr[i];
		} while (arr[i] <= 0 || arr[i] > 12);
		}
	do
	{
		cout<<"\n\t\t*****************************"
			<< "\n\t\t\t  MENU"
			<< "\n\t\t1-Pokazaty vsi otsinky"
			<< "\n\t\t2-Vkazaty novu otsinku"
			<< "\n\t\t3-Stypendiya"
			<< "\n\t\t0-EXIT"
			<<"\n\t\t******************************\n";
		do
		{
			cin >> key;
		} while (key != 1 && key != 2 && key != 3 && key != 0);
		cout << endl;
		switch (key)
		{
		case 1:
			Print(arr, size);
			break;
		case 2:
			cout << "\nNomer otsinky:";
			cin >> arrE;
			cout << "\nNova otsinka:";
			cin >> newE;
			New(arr, arrE, newE);
			break;
		case 3:
			cout << "Stypendiya:" << boolalpha << Stype(arr, size);
			break;
		}
	} while (key != 0);
	system("pause");
}
