#include<iostream>
using namespace std;
struct node1
{
	int data;
	struct node1 *next;
};
class linkedlist
{
public:
	struct node1 *start;

	linkedlist()
	{
		start = NULL;
	}
	
	void insert(int);
	void traverseforward();
	friend void merge(node1 *, node1 *);
	~linkedlist();
};
void linkedlist::insert(int ele)
{
	struct node1 *temp, *curr;
	
	temp = new node1;
	temp->next = NULL;
	temp->data = ele;
	if (start == NULL)
	{
		start = temp;
	}
	else
	{
		curr = start;
		while (curr->next != NULL&&curr->next->data < ele)
		{
			curr = curr->next;
		}
		if (curr->data>ele)
		{
			temp->next = curr;
			start = temp;
		}
		else
		{
			temp->next = curr->next;
			curr->next = temp;
		}
	}
}
void linkedlist::traverseforward()
{
	struct node1 *curr;
	curr = start;
	while (curr != NULL)
	{
		cout << curr->data<<"  ";
		curr = curr->next;
	}
}
void merge(node1 *start1, node1 *start2)
{
	struct node1 *curr1, *curr2,*curr,*temp;
	curr1 = start1;
	curr2 = start2;
	struct node1 *mergelist;
	mergelist = NULL;
	curr = mergelist;
	while (curr1!= NULL && curr2 != NULL)
	{
		temp = new node1();
		temp->next = NULL;
		
		if (curr1->data >= curr2->data)
		{
		
			temp->data = curr2->data;
			if (mergelist == NULL)
			{
			
				mergelist = temp;
				curr = mergelist;
				curr->next = NULL;
			}
			else
			{
				curr->next = temp;
				curr = curr->next;
			}
			curr2 = curr2->next;
		}
		else
		{
			temp->data = curr1->data;
			if (mergelist == NULL)
			{
				mergelist = temp;
				curr = mergelist;
			}
			else
			{
				curr->next = temp;
				curr = curr->next;
			}
			curr1 = curr1->next;
		}
	}
	while (curr1 != NULL)
	{
		temp = new node1();
		temp->data = curr1->data;
		curr1 = curr1->next;
		curr->next = temp;
		curr = curr->next;
	}
	while (curr2 != NULL)
	{
		temp = new node1();
		temp->data = curr2->data;
		curr2 = curr2->next;
		curr->next = temp;
		curr = curr->next;
	}
	curr = mergelist;
	while (curr != NULL)
	{
		cout << curr->data<<" ";
		curr = curr->next;
	}

	
}
linkedlist::~linkedlist()
{
	struct node1 *temp;
	while (start != NULL)
	{
		temp = start;
		start = temp->next;
		delete temp;
	}
}
void main()
{
	linkedlist l1,l2;
	int n,ele;	
		cout << "enter the size of first linked list";
		cin >> n;
		while (n != 0)
		{
			cout << "enter element ";
			cin >> ele;
			l1.insert(ele);
			n--;
			cout << endl;
		}
		l1.traverseforward();
		cout << endl;

		cout << "enter the size of second linked list";
		cin >> n;
		while (n != 0)
		{
			cout << "enter element ";
			cin >> ele;
			l2.insert(ele);
			n--;
			cout << endl;
		}
		l2.traverseforward();

		merge(l1.start, l2.start);

		
	
}