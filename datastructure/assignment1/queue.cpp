#include<iostream>
using namespace std;
struct _queue_
{
	int rear;
	int size;
	int front;
	int *q;
};
class queue
{
	struct _queue_ que;
public:
	queue();
	void enqueue(int);
	void getsize(int);
	int dequeue();
	bool overflow();
	bool underflow();
	void display();
	~queue()
	{
		delete que.q;
	}
};
queue::queue()
{
	que.rear = -1;
	que.front = -1;
	que.size = 0;
}
void queue::getsize(int n)
{
	que.size = n;
	que.q = new int[n];
}
bool queue::overflow()
{
	return(que.rear == (que.size - 1));
}
bool queue::underflow()
{
	return(que.front == -1||que.rear==-1 || (que.front > que.rear));
}
void queue::enqueue(int n)
{
	if (!overflow())
	{
		que.q[++que.rear] = n;
		if (que.front == -1)
			que.front = 0;
	}
	else
		cout << "queue is full";
}
int queue::dequeue()
{
	int n = -99;
	if (!underflow())
	{
		 n = que.q[que.front];
		que.front++;
		
	}
	else
		cout << "queue is empty";
	return n;
}
void queue::display()
{
	for (int i = que.front; i <= que.rear; i++)
	{
		cout << que.q[i] << endl;
	}
}
int main()
{
	queue a;
	int ch,k,n;
	cout << "enter no of elements";
	cin >> n;
	a.getsize(n);
	cout << endl;
	cout << "enter \n1.enqueue \n2.dequeue \n 3.display";
	cin >> ch;
	cout << endl;
	while (ch <= 3 && ch != 0)
	{
		switch (ch)
		{
		case 1:
			cout << "enter a number";
			cin >> k;
			a.enqueue(k);
			cout << endl;
			break;
		case 2:
			cout << "deleted element is "<<a.dequeue();
			break;
		case 3:
			a.display();
			break;
		}
		cin >> ch;
	}
}