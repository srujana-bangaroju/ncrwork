#include <iostream>
using namespace std;
class COMPLEX
{
public:
	float real, img;
	COMPLEX()
	{
		real = 0;
		img = 0;
	}
	COMPLEX(float r)
	{
		real = img = r;
	}
	COMPLEX(float r, float i)
	{
		real = r;
		img = i;
	}
	COMPLEX(const COMPLEX& c)
	{
		real = c.real;
		img = c.img;
	}
	~COMPLEX()
	{
	}
	COMPLEX operator+(COMPLEX c)
	{
		COMPLEX res;
		res.real = real + c.real;
		res.img = img + c.img;
		return res;
	}
	COMPLEX operator-(COMPLEX c)
	{
		COMPLEX res;
		res.real = real - c.real;
		res.img = img - c.img;
		return res;
	}
	COMPLEX operator-()
	{
		COMPLEX c;
		c.real = -real;
		c.img = -img;
		return c;
	}
	COMPLEX operator++()
	{
		COMPLEX c;
		c.real = ++real;
		c.img = ++img;
		return c;
	}
	COMPLEX operator++(int x)
	{
		COMPLEX temp;
		temp.real = real++;
		temp.img = img++;
		return temp;
	}
	COMPLEX operator=(COMPLEX c)
	{
		real = c.real;
		img = c.img;
		return *this;
	}
	COMPLEX operator,(COMPLEX c)
	{
		return c;
	}
	friend istream& operator >> (istream& cin, COMPLEX& c);
	friend ostream& operator<<(ostream& cout, COMPLEX c);
};
istream& operator >> (istream& cin, COMPLEX& c)
{
	cin >> c.real;
	cin >> c.img;
	return cin;
}
ostream& operator<<(ostream& cout, COMPLEX c)
{
	cout << "real=" << c.real << endl;
	cout << "imaginary=" << c.img << endl;
	return cout;
}
int main()
{
	COMPLEX c1, c2(3), c3(3, 4), cx(c2);
	COMPLEX c5 = c1 + c2;
	COMPLEX c6 = c2 - c3;
	COMPLEX c7 = -c1;
	COMPLEX c4 = ++c1;
	COMPLEX c8 = c2++;
	COMPLEX c9 = c2;
	COMPLEX c10 = (c1, c2);
	cout << c1;
	cout << c2;
	cout << c3;
	cout << c4;
	cout << c5;
	cout << c6;
	cout << c7;
	cout << c8;
	cout << c9;
	cout << c10;
}