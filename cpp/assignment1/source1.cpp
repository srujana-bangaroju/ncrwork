//display of time program
#include<iostream>
using namespace std;
class time
{
	int hour;
	int minute;
	int seconds;
public:
	time()//zero initialisation
	{
		hour = minute = seconds = 0;
	}
	time(int h, int m, int s)
	{
		hour = h;
		minute = m;
		seconds = s;
	}
	void display()
	{
		cout << hour << ":" << minute << ":" << seconds << endl;
	}
	void add(time t1, time t2)
	{
		time temp;
		temp.hour = t1.hour + t2.hour;
		temp.minute = t1.minute + t2.minute;
		temp.seconds = t1.seconds + t2.seconds;
		if (temp.seconds > 60)//to convert secs into minutes
		{
			temp.minute++;
			temp.seconds = temp.seconds - 60;
		}
		if (temp.minute > 60)//to convert minutes into hours
		{
			temp.hour++;
			temp.minute = temp.minute - 60;
		}

		if (temp.hour > 24)//to indicate that new day has begun
		{
			temp.hour = temp.hour = -24;
		}
		temp.display();
	}
};
int main()
{
	time t1(1, 30, 30);
	time t2(2, 40, 40);
	time t3;
	t1.display();
	t2.display();
	t3.add(t1, t2);
	return 0;
}
