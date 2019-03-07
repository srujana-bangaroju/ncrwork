#include<iostream>
#define max(a,b) (a>b?a:b)
using namespace std;
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
class BST
{
	struct node *start;
public:
	BST();
	node* insert(int,node *);
	void delete_ele(int);
	void inorder();
	void preorder();
	void postorder();
	int findmax(node *);
	int findmin(node *);
	int height(node *);
	int noofleafnodes(node *);
	int noofnonleafnodes(node *);
	void printinorder(node *);
	void printpreorder(node *);
	void printpostorder(node *);
	~BST();
};
BST::BST()
{
	start = NULL;
	left = NULL;
	right = NULL;
}
void BST::noofleafnodes(struct node *curr)
{
	if (curr == NULL)
		return 0;
	if (curr->left == NULL&&curr->right == NULL)
		return 1;
	return(noofleafnodes(curr->left) + noofleafnodes(curr->right));
}
int BST::findmin(struct node *curr)
{
	if (curr != NULL)
	{
		while (curr->left != NULL)
			curr = curr->left;
		return(curr->data);
	}
	else
		return -1;
}
int BST::findmax(struct node *curr)
{
	if (curr != NULL)
	{
		while (curr->right != NULL)
			curr = curr->right;
		return(curr->data);
	}
	else
		return -1;
}
int BST::height(struct node *curr)
{
	if (curr == NULL)
		return -1;
	else
		return(max(height(curr->left), height(curr->right)) + 1);
}
void BST::printinorder(struct node *curr)
{
	if (curr != NULL)
	{
		print(curr->left);
		cout << curr->data;
		print(curr->right);
	}
}
void BST::printpreorder(struct node *curr)
{
	if (curr != NULL)
	{
		cout << curr->data;
		print(curr->left);		
		print(curr->right);
	}

}
void BST::printpostorder(struct node *curr)
{
	if (curr != NULL)
	{
		print(curr->left);
		print(curr->right);
		cout << curr->data;
	}
}
void BST::inorder()
{
	if (start != NULL)
		print(start);
}
void BST::preorder()
{
	if (start != NULL)
		print(start);
}
void BST:::postorder()
{
	if (start != NULL)
		print(start);
}

