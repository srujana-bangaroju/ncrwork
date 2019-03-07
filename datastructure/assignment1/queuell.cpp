#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
class QueueLL
{
	struct node *rear;
public:
	QueueLL();
	void Enqueue(int);
	int Dequeue();
	void display();
	~QueueLL();
};
QueueLL::QueueLL()
{
	rear = NULL;
}
void QueueLL::Enqueue(int ele)
{
	struct node *temp, *curr;
	temp = new node;
	temp->data = ele;
	temp->next = NULL;
	if (rear == NULL)
	{
		rear = temp;
	}
	else
	{
		curr = rear;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = temp;
	}
}
int QueueLL::Dequeue()
{
	int x = -999;
	if (rear != NULL)
	{
		struct node *temp;
		temp = rear;
		rear = rear->next;
		x = temp->data;
		delete temp;
	}
	else
		cout << "List is empty";
	return x;
}
void QueueLL::display()
{
	struct node *curr;
	curr = rear;
	while (curr != NULL)
	{
		cout << curr->data;
		curr = curr->next;
	}
}

QueueLL::~QueueLL()
{
	struct node *temp;
	while (rear != NULL)
	{
		temp = rear;
		rear = temp->next;
		delete temp;
	}
}
int main()
{
	QueueLL a;
	int ele, ch, k;
	cout << "Enter an operation to perform\n1.Enqueue\n2.Dequeue\n3.Display\n";
	cin >> ch;
	while (ch <= 3 && ch != 0)
	{
		switch (ch)
		{
		case 1: cout << "Enter an element to insert:";
			cin >> ele;
			a.Enqueue(ele);
			break;
		case 2: k = a.Dequeue();
			cout << "\nDeleted element is:" << k;
			break;
		case 3:a.display();
			break;
		}
		cout << "\nEnter an operation to be performed:";
		cin >> ch;
	}
	return 0;
}
