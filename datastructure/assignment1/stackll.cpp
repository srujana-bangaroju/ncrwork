#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
class StackLL
{
	struct node *top;
public:
	StackLL();
	void push(int);
	int pop();
	void display();
	~StackLL();
};
StackLL::StackLL()
{
	top = NULL;
}
void StackLL::push(int ele)
{
	struct node *temp;
	temp = new node;
	temp->data = ele;
	temp->next = top;
	top = temp;
}
int StackLL::pop()
{
	int x = -999;
	if (top != NULL)
	{
		struct node *temp;
		temp = top;
		top = top->next;
		x = temp->data;
		delete temp;
	}
	else
		cout << "List is empty";
	return x;

}
StackLL::~StackLL()
{
	struct node *temp;
	while (top != NULL)
	{
		temp = top;
		top = temp->next;
		delete temp;
	}
}
void StackLL::display()
{
	struct node *curr;
	curr = top;
	while (curr != NULL)
	{
		cout << curr->data;
		curr = curr->next;
	}
}
int main()
{
	StackLL a;
	int ele, ch, k;
	cout << "Enter an operation to perform:\n1.Push\n2.Pop\n3.Display\n";
	cin >> ch;
	while (ch <= 3 && ch != 0)
	{
		switch (ch)
		{
		case 1:cout << "Enter an element:";
			cin >> ele;
			a.push(ele);
			break;
		case 2: k = a.pop();
			cout << "Deleted element is:" << k;
			break;
		case 3: a.display();
			break;
		}
		cout << "Enter an operation:";
		cin >> ch;
	}
	return 0;
}