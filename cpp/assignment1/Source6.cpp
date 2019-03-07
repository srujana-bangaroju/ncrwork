#include<iostream>
#include<cmath>
using namespace std;
class point;

class point
{
	int x, y;
public:
	void input()
	{
		cout << "enter a point in cartesian space";
		cin >> x >> y;
		cout << endl;
	}
	friend float distance(point, point);
};
float distance(point a, point b)
{
	float d;
	d = sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2));
	return d;
}

void main()
{
	point p1, p2;
	p1.input();
	p2.input();
	float k;
	k = distance(p1, p2);
	cout << "distance is " << k;
}