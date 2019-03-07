#define _CRT_NO_SECURE_WARNINGS
#include<iostream>
using namespace std;
class distance2;
class distance1;
distance1 add(distance1 x, distance1 y);
distance2 add(distance2 x, distance2 y);
void display(); 
class distance1
{
	int meters;
	int centimeters;
public:
	int notation(int x, int y)
	{
		meters = x;
		centimeters = y;
	}
	friend distance1 add(distance1 x, distance1 y);
	friend distance2 add(distance2 x, distance2 y);
	friend void display();
};
class distance2
{
	int feet;
	int inch;
public:
	int notation(int x, int y)
	{
		feet = x;
		inch = y;
	}
	friend distance1 add(distance1 x, distance1 y);
	friend distance2 add(distance2 x, distance2 y);
	friend void display(); 
};
distance1 add(distance1 x, distance1 y)
{
	distance1 temp;
	temp.meters = x.meters + y.meters;
	temp.centimeters = x.centimeters + y.centimeters;
	return temp;
}
distance2 add(distance2 x, distance2 y)
{
	distance2 temp;
	temp.feet = x.feet + y.feet;
	temp.inch = x.inch + y.inch;
	return temp;
}
void display()
{
	cout << res1 << endl;
	cout << res2 << end;
}
int main()
{
	int choice, m, cm, ft, inch;
	cout << "enter the 'a' value in m and cm" << endl;
	cin >> m >> cm;
	cout << "enter the 'b' value in ft and inch" << endl;
	cin >> ft >> inch;
	distance1 d1,res1;
	distance2 d2,res2;
	d1.notation(m, cm);
	d2.notation(ft, inch);
	cout << "select the units you want the answer to be:\n1.m and cm\n2.ft and inch\n" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1: {
		int i, j, x;
		distance1 d;
		i = d2::distance2.feet;
		j = d2.inch;
		x = (i*30.48) + (j*2.54);
		d.meters = x / 100;
		d.centimeters = (x - ((d.meters) * 100));
		res1=add(d1, d);
		display(res1);
	}
			break;
	case 2: {
		int i, j, x;
		distance2 d;
		i = d1.meters;
		j = d1.centimeters;
		x = (i * 40) + (j*0.4);
		d.feet = x / 2.54;
		d.inch = (x - ((d.feet) * 100));
		res2=add(d2, d);
		display(res2);
	}
			break;
	default:break;
	}
}
