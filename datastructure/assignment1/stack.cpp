#include<iostream>
using namespace std;
struct __stack__
{
	int top;
	int *s;
	int size;
};
class _stack_
{
	struct __stack__ sta;
public:
	_stack_();
	void push(int);
	int pop();
	int peek();
	bool isempty();
	bool isfull();
	void display();
	void getsize(int);
	~_stack_();
};
_stack_::_stack_()
{
	sta.top = -1;
	sta.s = NULL;
	sta.size = 0;
}
void _stack_::getsize(int n)
{
	sta.size = n;
	sta.s = new int[n];
}
bool _stack_::isfull()
{
	return(sta.top == (sta.size - 1));
}
bool _stack_::isempty()
{
	return(sta.top == -1);
}

void _stack_::push(int ele)
{
	if (!isfull())
	{
		sta.s[++sta.top] = ele;
	}
	else
		cout << "stack is full" << endl;
}
int _stack_::pop()
{
	int x = -999;
	if (!isempty())
	{
		x = sta.s[sta.top--];
	}
	else
		cout << "stack is empty"<<endl;
	return x;
}
int _stack_::peek()
{
	int x = -999;
	if (!isempty())
	{
		x = sta.s[sta.top];
	}
	else
		cout << "stack is empty";
	return x;
}
void _stack_::display()
{
	for (int i = 0; i <= sta.top; i++)
		cout << sta.s[i]<<" ";
}
_stack_::~_stack_()
{
	delete sta.s;
}
void main()
{
	int n;
	cout << "enter the size of stack";
	cin >> n;
	cout << endl;
	_stack_ a;
	a.getsize(n);
	for (int i = 0; i < n; i++)
	{
		int ch;
		cout << "enter element" << i + 1;
		cin >> ch;
		a.push(ch);
		cout << endl;
	}
	int k=a.pop();
	cout << "poped element is" << k<<endl;
	int k1=a.peek();
	cout << "peek element is" << k1 << endl;
	a.display();
}