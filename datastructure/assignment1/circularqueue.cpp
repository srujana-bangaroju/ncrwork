#include<iostream>
using namespace std;
struct _cqueue_
{
	int rear;
	int size;
	int front;
	int *q;
};
class cqueue
{
	struct _cqueue_ que;
public:
	cqueue();
	void encqueue(int);
	void getsize(int);
	int decqueue();
	bool overflow();
	bool underflow();
	void display();
	~cqueue()
	{
		delete que.q;
	}
};
cqueue::cqueue()
{
	que.rear = -1;
	que.front = -1;
	que.size = 0;
}
void cqueue::getsize(int n)
{
	que.size = n;
	que.q = new int[n];
}
bool cqueue::overflow()
{
	return((que.front==(que.rear+1)%que.size&&que.q[que.front] !=-1));
}
bool cqueue::underflow()
{
	return(que.front == -1||( (que.front == (que.rear + 1) % que.size)&&que.q[que.front]==-1));
}
void cqueue::encqueue(int n)
{
	if (!overflow())
	{
		que.rear = (que.rear + 1) % que.size;
		que.q[que.rear] = n;
		if (que.front == -1)
			que.front = 0;
	}
	else
		cout << "cqueue is full";
}
int cqueue::decqueue()
{
	int n = -99;
	if (!underflow())
	{
		n = que.q[que.front];
		que.q[que.front] = -1;
		que.front = (que.front + 1) % que.size;
	}
	else
		cout << "cqueue is empty";
	return n;
}
void cqueue::display()
{
	int i;
	for ( i = que.front; i != que.rear; i=(i+1)%que.size)
	{
		cout << que.q[i] << " ";
	}
	cout << que.q[i];
}
int main()
{
	cqueue a;
	int ch, k, n;
	cout << "enter no of elements";
	cin >> n;
	a.getsize(n);
	cout << endl;
	cout << "enter \n1.encqueue \n2.decqueue \n 3.display";
	cin >> ch;
	cout << endl;
	while (ch <= 3 && ch != 0)
	{
		switch (ch)
		{
		case 1:
			cout << "enter a number";
			cin >> k;
			a.encqueue(k);
			cout << endl;
			break;
		case 2:
			cout << "deleted element is " << a.decqueue();
			break;
		case 3:
			a.display();
			break;
		}
		cin >> ch;
	}
}