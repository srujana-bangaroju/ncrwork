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
		cout << "stack is empty" << endl;
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
		cout << sta.s[i] << " ";
}
_stack_::~_stack_()
{
	delete sta.s;
}
int number(char a)
{
	switch (a)
	{
	case '+':
	case '-':
		return 2;
	case '*':
	case '/':
		return 3;
	case '(':
		return 1;
	case ')':
		return 4;
	}
}


void main()
{
	char *in, op[10],*in1;
	int len;
	cout << "enter length";
	cin >> len;
	in = new char[len];
	for (int i1 = 0; i1 < len; i1++)
	{
		cin >> in[i1];
	}
	in1 = new char[len];
	for (int p1 = 0, p = len - 1; p >= 0; p1++, p--)
	{
		in1[p1] = in[p];
		
	}
	

	int j = 0, val, count = 0;
	_stack_ a;
	a.getsize(len);
	for (int o = 0; o < len; o++) {

		if (in1[o] == '(') {
			in1[o] = ')';
			o++;
		}
		else if (in1[o] == ')') {
			in1[o] = '(';
			o++;
		}
	}

	for (int i = 0; i < len; i++)
	{
		char ch = in1[i];
		if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'B'))
		{
			op[j] = ch;
			j++;
		}
		else
		{
			if (a.isempty())
			{
				a.push(ch);

			}
			else

			{


				if (number(ch) > number(a.peek()))
				{
					if (number(ch) == 4)
					{
						while (a.peek() != '(')
						{
							op[j] = a.peek();
							j++;
							a.pop();
						}
						a.pop();

					}
					else
						a.push(ch);
				}

				else
				{
					if (number(ch) == 1)
					{
						a.push(ch);
					}
					else
					{
						while (!a.isempty())
						{
							op[j] = a.peek();
							j++;
							a.pop();
						}
						a.push(ch);
					}
				}
			}
		}
	}
	while (!a.isempty())
	{
		op[j] = a.peek();
		j++;
		a.pop();
	}
	for (int k = j-1; k >=0; k--)
		cout << op[k];
	delete(in);
	delete(in1);
}