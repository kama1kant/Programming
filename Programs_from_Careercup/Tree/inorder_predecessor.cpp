#include<iostream>
#include<stdio.h>
#include<malloc.h>

using namespace std;

struct node* insert(struct node *node, int data);   //Working
struct node* Newnode(int value);    //Working
void inorder(struct node* n);   //Working
struct node* inorder_successor(struct node *root, struct node *n);
struct node* minvalue(struct node *root);

struct node
{
    int data;
    struct node* left;
    struct node* right;
};
int main()
{
    struct node* root2;
    struct node* root = Newnode(6);
    struct node* lChild = Newnode(-13);
    struct node* rChild = Newnode(14);
    root->left = lChild;
    root->right= rChild;
    root = insert(root, 15);
    root = insert(root, -8);
    root = insert(root, 13);
    root = insert(root, 7);
    cout<<"Inorder = ";
    inorder(root);
    cout<<endl;
    struct node *temp = root->right;
    struct node *t = inorder_successor(root, temp);
    if(t != NULL)
        cout<<t->data;
    return 0;
}

struct node* inorder_successor(struct node *root, struct node *n)
{
	if(n == NULL)
		return NULL;
	if(n->right)
		return(minvalue(n->right));
	else
	{
		struct node *result = NULL;
		while(root != n)
		{
			if(root->data < n->data)
			{
				root = root->right;
			}
			else
			{
				result = root;
				root = root->left;
			}
		}
		return result;
	}
}

struct node* minvalue(struct node *root)
{
	while(root != NULL && root->left != NULL)
	{
		root = root->left;
	}
	return root;
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
