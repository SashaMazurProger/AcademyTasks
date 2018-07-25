#include<iostream>
#include<iomanip>
#include<time.h>
#include<vector>
#include<map>
#include<sstream>
#include<string>
#include<iterator>
#include<ostream>
using namespace std;

template <typename T1, typename T2>ostream &operator<<(ostream &stream, const map<T1, T2>& map)
{
	for (typename std::map<T1, T2>::const_iterator it = map.begin();
		it != map.end(); ++it)
	{
		stream << "\n" << (*it).first << " = " << (*it).second;
		return stream;
	}
}
void Show(map<string, int> matrix)
{
	map<string, int>::iterator iter = matrix.begin();
	for (int countStr = 1; iter != matrix.end(); ++countStr, ++iter)
	{
		cout << "\n" << iter->first << " = " << iter->second;
		if (countStr % 10 == 0)
			cout << "\n\n";
	}
}
string intParser(int x, int y)
{
	string tmp;
	stringstream a, b;
	a << x;
	b << y;
	tmp = a.str() + " x " + b.str();
	return tmp;
}
void CreateMatrix(map<string, int> matrix)
{
	string tmp;

	for (int countStr = 0, x = 1; x <= 10; ++x)
	{
		for (int y = 1; y <= 10; ++y)
		{
			matrix.insert(pair<string, int>(intParser(x, y), x*y));
			countStr++;
		}
	}
	//copy(matrix.begin(), matrix.end(), ostream_iterator<string,int>(cout, "\n",));
	Show(matrix);
}
//void CreateMatrix(vector<vector<int>> matrix)
//{
//}
void main()
{
	/*srand(time(0));
	vector<vector<int>>square(10);
	vector<int>::iterator iter;
	iter = square.begin();*/

	map<string, int> matrix;
	CreateMatrix(matrix);
	//Show(matrix);

	system("pause");
}