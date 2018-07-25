#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<string.h>
using namespace std;

class Directory
{
	double* vect;
	double length;
	static int count;
public:
	Directory()
	{
		++count;
	}
    Directory(double v[])
	{
		vect = v;
		++count;
	}
	void SetVector(double v[])
	{
		vect = v;
	}

	void operator ++()
	{
		for(int i=0;i<3;++i)
		++vect[i];
	}
	void operator --()
	{
		for (int i = 0; i<3; ++i)
			--vect[i];
	}
	double operator [](int index)
	{
		return vect[index];
	}
	Directory operator +(Directory b)
	{
		double vector[3];
		vector[0] = vect[0] + b.vect[0];
		vector[1] = vect[1] + b.vect[1];
		vector[2] = vect[2] + b.vect[2];
		Directory tmp(vector);
		return tmp;
	}
	Directory operator -(Directory b)
	{
		double vector[3];
		vector[0] = vect[0] - b.vect[0];
		vector[1] = vect[1] - b.vect[1];
		vector[2] = vect[2] - b.vect[2];
		Directory tmp(vector);
		return tmp;
	}
	Directory operator +=(Directory b)
	{
		double vector[3];
		vector[0] = vect[0] + b.vect[0];
		vector[1] = vect[1] + b.vect[1];
		vector[2] = vect[2] + b.vect[2];
		Directory tmp(vector);
		return tmp;
	}
	Directory operator -=(Directory b)
	{
		double vector[3];
		vector[0] = vect[0] - b.vect[0];
		vector[1] = vect[1] - b.vect[1];
		vector[2] = vect[2] - b.vect[2];
		Directory tmp(vector);
		return tmp;
	}
	Directory operator *(int a)
	{
		double vector[3];
		vector[0] = vect[0]*a;
		vector[1] = vect[1]*a;
		vector[2] = vect[2]*a;
		Directory tmp(vector);
		return tmp;
	}
	double operator *(Directory b)
	{
		double res = (vect[0] * b.vect[0]) + (vect[1] * b.vect[1]) + (vect[2] * b.vect[2]);
		return res;
	}
	ostream& operator <<(ostream os)
	{
		os << "(" << vect[0] << ";" << vect[1] << ";" << vect[2] << ")";
		return os;
	}
	istream& operator >>(istream is)
	{
		cout << "x:";
		is>>vect[0];
		cout << "y:";
		is >> vect[1];
		cout << "z:";
		is >> vect[2];
	}
    void operator ==( Directory m)
	{
		if (!isdigit(vect[0]) && !isalpha(m.vect[0]))
		{
			if (vect[0]== m.vect[0]&& vect[1] == m.vect[1]&& vect[2] == m.vect[2])
				cout << "\nvector1 == vector2";
			else
				cout << "\nvector1!=vector2";
		}
		else
			cout << "\nSpochatku vkazhit koordynaty vektoriv";
	}
	Directory operator =(Directory m)
	{
		if (!isdigit(m.vect[0]))
		{
			this->length = m.length;
			this->vect = m.vect;
			return *this;
		}
		else
			cout << "\nSpochatku vkazhit parametry vektora";
	}
	void operator >(Directory m)
	{
		if (length != 0 && m.length != 0)
		{
			if (length == m.length)
				cout << "\nlength1 == length2";
			else if(length>m.length)
				cout << "\nlength1 > length2";
			else
				cout << "\nlength1 < length2";
		}
		else
			cout << "\nSpochatku vkazhit znachennya tciny";
	}
	~Directory()
	{
		cout << "Destructor";
    }
};

