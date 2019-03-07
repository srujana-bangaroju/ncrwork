#include<iostream>
using namespace std;
inline int add(int a, int b)
{
	return a + b;
}
inline int sub(int a, int b)
{
	return a - b;
}
inline int mul(int a, int b)
{
	return a * b;
}
inline int divis(int a, int b)
{
	return (a / b);
}
class arith
{
	int a;
	int b;
public:
	void input(int x, int y)
	{
		a = x;
		b = y;
	}
	//void display()
	
};
int main()
{
	int x, y;
	int res;
	cout << "enter x and y values" << endl;
	cin >> x >> y;
	res = add(x, y);
	cout<<res<<endl;
	res = sub(x, y);
	cout << res << endl;
	res = mul(x, y);
	cout << res << endl;
	res = divis(x, y);
	cout << res << endl;
}