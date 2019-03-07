#include <iostream>
using namespace std;
class Employee
{
	int salary;
public:
	Employee()
	{
		salary = 0;
		cout << "Default constructor called" << endl;
	}
	Employee(int sal)
	{
		salary = sal;
		cout << "Parameterized constructor called" << endl;
	}
	Employee(const Employee &e)
	{
		salary = e.salary;
		cout << "Copy constructor called" << endl;
	}
	~Employee()
	{
		cout << "Destructor called" << endl;
	}
	friend void contents_val(Employee e);
	friend void contents_ref(Employee &e);
};
void contents_val(Employee e)
{
	int size1 = sizeof(e);
	cout << size1 << endl;
}
void contents_ref(Employee &e)
{
	int size2 = sizeof(e);
	cout << size2 << endl;
}
int main()
{
	Employee e1, e2(10000), e3(e2);
	cout << sizeof(e1);
	contents_val(e1);
	contents_ref(e1);
	return 0;
}