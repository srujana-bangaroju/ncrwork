#include <iostream>
#include<string>
using namespace std;
class EMPLOYEE
{
public:
	int empno;
	char name[20];
	float salary;
	void display()
	{
		cout << "The details of the employee are" << endl;
		cout << "empno=" << empno << endl;
		cout << "name=" << name << endl;
		cout << "salary=" << salary << endl;
	}
	friend istream operator&(istream& cin, EMPLOYEE& e);
};
istream& operator >> (istream& cin, EMPLOYEE& e)
{
	cin >> e.empno;
	cin >> e.name;
	cin >> e.salary;
	return cin;
}
int main()
{
	EMPLOYEE e[5];
	for (int i = 0; i < 5; i++)
	{
		cout << "enter the values of" << i << "th object" << endl;
		cin >> e[i];
	}
	for (int i = 0; i < 5; i++)
	{
		e[i].display();
	}
}
