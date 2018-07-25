#include<iostream>
using namespace std;
int Search(int arr[], int L, int r, int x)
{
	int m =L+(r-L) / 2;
	if (L<=r)
	{
		if (arr[m] < x)
		    Search(arr, m + 1, r, x);
		else if (arr[m] > x)
		    Search(arr, L, m - 1, x);
		else if (arr[m] == x)
			return m;
	}
	return -1;
}
void main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int a;
	do
	{
		cout << "\nNumber:";
		cin >> a;
		cout << "Index of number:" << Search(arr, 0, 9, a);
	} while (true);
	system("pause");
}