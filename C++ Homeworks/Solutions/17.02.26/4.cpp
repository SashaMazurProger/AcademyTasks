
#include<iostream>
using namespace std;
void func(float *a, float *b, int *res)
{
	if (*a > *b)
		*res = 1;
	else if (*a < *b)
		*res = 2;
	else *res = 0;
}
void main()
{
	float a, b;
	int res;
	do
	{
		cout << "1 chyslo:";
		cin >> a;
		cout << "2 chyslo:";
		cin >> b;
		func(&a, &b, &res);
		if (res)
			cout << "\nChyslo " << res << " bilshe";
		else
			cout << "Chysla rivni";
		cout << endl <<endl;
	} while (true);
	system("pause");
}
