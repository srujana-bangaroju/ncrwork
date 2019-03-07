#include<iostream>
using namespace std;
struct __stack__
{
	int top;
	char *s;
	int size;
};
class _stack_
{
	struct __stack__ sta;
public:
	_stack_();
	void push(char);
	char pop();
	char peek();
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
	sta.s = new char[n];
}
bool _stack_::isfull()
{
	return(sta.top == (sta.size - 1));
}
bool _stack_::isempty()
{
	return(sta.top == -1);
}

void _stack_::push(char ele)
{
	if (!isfull())
	{
		sta.s[++sta.top] = ele;
	}
	else
		cout << "stack is full" << endl;
}
char _stack_::pop()
{
	char x;
	if (!isempty())
	{
		x = sta.s[sta.top--];
	}
	else
		cout << "stack is empty" << endl;
	return x;
}
char _stack_::peek()
{
	char x;
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
		cout << sta.s[i] << " ";
}
_stack_::~_stack_()
{
	delete sta.s;
}
void main()
{
	char str[20];
	cin >> str;
	_stack_ a;
	int n = strlen(str);

	a.getsize(n);
	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		char ch = str[i];
		switch (ch)
		{
		case '(':a.push(ch);
				break;
		case '[' :a.push(ch);
					break;
		case '{' : a.push(ch);
					break;
		case ')':
		case ']' :
		case '}' :
			if (!a.isempty())
			{
				if ((ch == ')'&&a.peek() == '(') || (ch == ']'&&a.peek() == '[') || (ch == '}'&&a.peek() == '{'))
				{
					a.pop();
					break;
				}
				else
				{

					flag = 1;
					break;
				}
			}
			else
				flag = 1;
			
		}
			
	}
	if (!a.isempty())
		flag = 1;
	if (flag == 1)
{
	cout << "not balanced";
	return;
}

	if (flag == 0)
		cout << "balanced";
}