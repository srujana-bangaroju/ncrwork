#include<iostream>
using namespace std;
struct node1
{
	int data;
	struct node1 *next;
	struct node1 *prev;
};
class doublelinkedlist
{
public:
	struct node1 *start;

	doublelinkedlist()
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
	~doublelinkedlist();
};
void doublelinkedlist::insertfirst(int ele)
{
	struct node1 *temp;
	temp = new node1;
	temp->data = ele;
	temp->next = start;
	temp->prev = NULL;
	if (start != NULL)
		start->prev = temp;
	start = temp;
}
void doublelinkedlist::insertlast(int ele)
{
	struct node1 *temp, *curr;
	temp = new node1;
	temp->data = ele;
	temp->next = NULL;

	if (start == NULL)
	{
		temp->prev = NULL;
		start = temp;
	}
	else
	{
		curr = start;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		temp->prev = curr;
		curr->next = temp;

	}
}
void doublelinkedlist::insertafter(int sele, int ele)
{
	if (start != NULL)
	{
		struct node1 *curr;
		curr = start;
		while (curr != NULL && curr->data != sele)
		{
			curr = curr->next;
		}
		if (curr != NULL)
		{
			struct node1 *temp;
			temp = new node1;
			temp->prev = curr;
			temp->data = ele;
			temp->next = curr->next;
			if (curr->next != NULL)
				curr->next->prev = temp;
			curr->next = temp;
		}
		else
			cout << "element not found";
	}
	else
	{
		cout << "list is empty";
	}
}
void doublelinkedlist::insertbefore(int sele, int ele)
{
	if (start != NULL)
	{
		struct node1 *curr;
		curr = start;
		while (curr != NULL && curr->data != sele)
		{
			curr = curr->next;
		}
		if (curr != NULL)
		{
			struct node1 *temp;
			temp = new node1;
			temp->prev = curr->prev;
			temp->data = ele;
			temp->next = curr;
			if (curr->prev != NULL)
				curr->prev->next = temp;
			else
				start = temp;
			curr->prev = temp;
		}
		else
			cout << "element not found";
	}
	else
	{
		cout << "list is empty";
	}
}
int doublelinkedlist::deletefirst()
{
	int x = -999;
	if (start != NULL)
	{
		struct node1 *temp;
		temp = start;
		if (temp->next != NULL)
			temp->next->prev = NULL;
		start = temp->next;
		x = temp->data;
		delete temp;
	}
	else
		cout << "list is empty";
	return x;
}
int doublelinkedlist::deletelast()
{
	int x = -999;
	if (start != NULL)
	{
		struct node1 *curr;
		curr = start;
		while (curr->next != NULL)
			curr = curr->next;
		x = curr->data;
		if (curr->prev != NULL)
			curr->prev->next = NULL;
		else
			start = NULL;
		delete curr;
	}
	else
		cout << "list empty";
	return x;
}
void doublelinkedlist::deleteele(int ele)
{
	struct node1 *curr;
	if (start != NULL)
	{
		
			curr = start;
			while (curr != NULL&&curr->data != ele)
			{
				curr = curr->next;
			}
			if (curr != NULL)
			{
				if (curr->prev != NULL)
					curr->prev->next = curr->next;
				else
					start = curr->next;
				if (curr->next != NULL)
					curr->next->prev = curr->prev;
				delete curr;
			}
			else
				cout << "element not found";
	}
	else
		cout << "list is empty";
}
void doublelinkedlist::traverse_forward()
{
	struct node1 *curr;
	curr = start;
	while (curr != NULL)
	{
		cout << curr->data;
		curr = curr->next;
	}
}
void doublelinkedlist::traverse_backward()
{
	struct node1 *curr;
	if (start != NULL)
		curr = start;
	while (curr->next != NULL)
		curr = curr->next;
	while (curr != NULL)
	{
		cout << curr->data;
		curr = curr->prev;
	}
}

doublelinkedlist::~doublelinkedlist()
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
	doublelinkedlist a;
	cout << "Enter an operation to perform. \n1.Insert_first\n2.Insert_last\n3.Insert_after\n4.Insert_before\n";
	cout << "5.Delete_first\n 6.Delete_last\n7.Delete_ele\n8.Travel_forward\n9.Travel_backward\n";
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
			a.insertafter(3, ele);
			break;
		case 4: cout << "Enter an element";
			cin >> ele;
			a.insertbefore(3, ele);
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
		
		}
		cout << "\nEnter an operation to perform:";
		cin >> ch;
	}
	return 0;

}