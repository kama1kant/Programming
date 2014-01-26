#include<iostream>
#include<stdio.h>
#include<malloc.h>

using namespace std;

struct node* insert(struct node *node, int data);   //Working
struct node* Newnode(int value);    //Working
void inorder(struct node* n);   //Working
int check_sum(struct node *head, struct node *tail, int sum);
void bst_to_dll(struct node *root, struct node **head, struct node **tail);
int fun(struct node *root, int k);

struct node
{
    int data;
    struct node* left;
    struct node* right;
};
int main()
{
    struct node* root2;
    struct node* root = Newnode(3);
    struct node* lChild = Newnode(2);
    struct node* rChild = Newnode(4);
    root->left = lChild;
    root->right= rChild;
    root = insert(root, 5);
    root = insert(root, 7);
    cout<<"Inorder = ";
    inorder(root);
    cout<<fun(root, 7);
    return 0;
}


int fun(struct node *root, int k)
{
	struct node *head = NULL, *tail = NULL;
	bst_to_dll(root, &head, &tail);
	int sum = check_sum(head, tail, k);
	return sum;
}

void bst_to_dll(struct node *root, struct node **head, struct node **tail)
{
	if(root = NULL)
		return;
	bst_to_dll(root->left, head, tail);
	if((*head) == NULL)
	{
		(*head) = root;
		(*tail) = root;
	}
	else
	{
		(*tail)->right = root;
		root->left = (*tail);
		(*tail) = root;
	}
	bst_to_dll(root->right, head, tail);

}


int check_sum(struct node *head, struct node *tail, int sum)
{
	struct node *h = head, *t = tail;
	int count = 0;
	while(h->left != t && h != t)
	{
		if(h->data + t->data == sum)
		{
			count++;
			h = h->right;
			t = t->left;
		}
		if(h->data + t->data > sum)
		{
			t = t->left;
		}
		else if(h->data + t->data < sum)
		{
			h = h->right;
		}
	}
	return count;
}


struct node* Newnode(int value)
{
    struct node* e = (struct node*)malloc(sizeof(struct node));
    e->data = value;
    e->left = NULL;
    e->right = NULL;
    return e;
}
struct node* insert(struct node *n, int value)
{
    if(n == NULL)
    return(Newnode(value));
    else
    {
        if(value <= n->data)
        n->left = insert(n->left, value);
        else
        n->right = insert(n->right, value);
        return(n);
    }
}

void inorder(struct node* n)
{
    if(n==NULL)
    return;
    else
    {
        inorder(n->left);
       cout<<n->data<<" ";
        inorder(n->right);
    }
}
