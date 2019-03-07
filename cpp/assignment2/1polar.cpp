#include<iostream>
using namespace std;
class polar
{
	
	float r,angle;
public:
	static int count;
	polar()
	{
		r = 0;
		angle = 0;
		count++;
	}
	polar(float a, float b)
	{
		r = a;
		angle = b;
		count++;
	}
	polar(polar &k)
	{
		r = k.r;
		angle = k.angle;
		count++;
	}
	void display()
	{
		cout << count;
	}
	
};
int polar::count;
void main()
{
	polar p1, p2(4.1, 2.1), p3(p2);
	p1.display();
}