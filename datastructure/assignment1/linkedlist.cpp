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
	void insertfirst(int);
	void insertlast(int);
	void insertbefore(int, int);
	void insertafter(int, int);
	int deletefirst();
	int deletelast();
	void deleteele(int);
	void traverse_forward();
	void traverse_backward();
	friend void print(struct node1 *);
	void reverse();
	~linkedlist();
};
void linkedlist::insertfirst(int ele)
{
	struct node1 *temp;
	temp = new node1;
	temp->data = ele;
	temp->next = start;
	start = temp;
}
void linkedlist::insertlast(int ele)
{
	struct node1 *temp, *curr;
	temp = new node1;
	temp->data = ele;
	temp->next = NULL;
	if (start== NULL)
	{
		start = temp;
	}
	else
	{
		curr = start;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = temp;

	}
}
void linkedlist::insertafter(int sele, int ele)
{
	if (start != NULL)
	{
		struct node1 *curr;
		curr = start;
		while (curr != NULL && curr->data != sele)
		{
			curr = curr->next;
		}
		if(curr!=NULL)
		{
			struct node1 *temp;
			temp = new node1;
			temp->data = ele;
			temp->next = curr->next;
			curr->next = temp;
		}
	}
	else
	{
		cout << "list is empty";
	}
}
void linkedlist::insertbefore(int sele, int ele)
{
	struct node1 *curr;
	curr = start;
	if (start->data == sele)
	{
		struct node1 *temp;
		temp = new node1;
		temp->data = ele;
		temp->next = start;
		start = temp;
	}
	else
	{
		while (curr->next != NULL&&curr->next->data != sele)
			curr = curr->next;
		if (curr->next != NULL)
		{
			struct node1 *temp;
			temp = new node1;
			temp->data = ele;
			temp->next = curr->next;
			curr->next = temp;
		}
		else
			cout << "element not found";
	}
}
int linkedlist::deletefirst()
{
	int x = -999;
	if (start != NULL)
	{
		struct node1 *temp;
		temp = start;
		start = start->next;
		x = temp->data;
		delete temp;
	}
	else
		cout << "list is empty";
	return x;
}
int linkedlist::deletelast()
{
	int x = -999;
	if (start != NULL)
	{
		if (start->next == NULL)
		{
			x = start->data;
			delete start;
			start = NULL;
		}
		else
		{
			struct node1 *curr;
			curr = start;
			while (curr->next->next != NULL)
				curr = curr->next;
			x = curr->next->data;
			delete curr->next;
			curr->next = NULL;
		}
	}
	else
		cout << "list empty";
	return x;
}
void linkedlist::deleteele(int ele)
{
	struct node1 *temp, *curr;
	if (start != NULL)
	{
		if (start->data == ele)
		{
			temp = start;
			start = temp->next;
			delete temp;
		}
		else
		{
			curr = start;
			while (curr->next != NULL&&curr->next->data != ele)
			{
				curr = curr->next;
			}
			if (curr->next != NULL)
			{
				temp = curr->next;
				curr->next = temp->next;
				delete temp;
			}
			else
				cout << "element not found";
		}
	}
	else
		cout << "list is empty";
}
void linkedlist::traverse_forward()
{
	struct node1 *curr;
	curr = start;
	while (curr != NULL)
	{
		cout << curr->data;
		curr = curr->next;
	}
}
void linkedlist::traverse_backward()
{
	if (start != NULL)
		print(start);
}
void print(struct node1 *curr)
{
	if (curr != NULL)
	{
		print(curr->next);
		cout << curr->data;
	}
}
void linkedlist::reverse()
{
	struct node1 *rev,*temp;
	rev = NULL;
	if (start != NULL || start->next != NULL)
	{
		while (start != NULL)
		{
			temp = start;
			start = temp->next;
			temp->next = rev;
			rev = temp;
		}
		start = rev;
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
int main()
{
	linkedlist a;
	cout << "Enter an operation to perform. \n1.Insert_first\n2.Insert_last\n3.Insert_after\n4.Insert_before\n";
	cout << "5.Delete_first\n 6.Delete_last\n7.Delete_ele\n8.Travel_forward\n9.Travel_backward\n10.reverse\n";
	int ch;
	int ele, e1;
	cin >> ch;
	while (ch <= 10)
	{
		switch (ch)
		{
		case 1:cout << "\nEnter an element";
			cin >> ele;
			a.insertfirst(ele);
			break;
		case 2: cout << "\nEnter an element";
			cin >> ele;
			a.insertlast(ele);
			break;
		case 3: cout << "Enter an element";
			cin >> ele;
			a.insertafter(3,ele);
			break;
		case 4: cout << "Enter an element";
			cin >> ele;
			a.insertbefore(3,ele);
			break;
		case 5: e1 = a.deletefirst();
			cout << "\nDeleted element is:" << e1;
			break;
		case 6: e1 = a.deletelast();
			cout << "\nDeleted element is:" << e1;
			break;
		case 7: a.deleteele(7);
			break;


		case 8: a.traverse_forward();
			break;
		case 9: a.traverse_backward();
			break;
		case 10:cout << "After reversing\n";
			a.reverse();
			a.traverse_forward();
			break;
		}
		cout << "\nEnter an operation to perform:";
		cin >> ch;
	}
	return 0;

}