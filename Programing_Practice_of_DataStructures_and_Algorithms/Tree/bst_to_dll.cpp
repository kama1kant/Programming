#include<iostream>
#include<stdio.h>
#include<malloc.h>

using namespace std;

struct node* insert(struct node *node, int data);   //Working
struct node* Newnode(int value);    //Working
void inorder(struct node* n);   //Working
void bst_to_dll(struct node *root, struct node **head, struct node **tail);
void fun(struct node *root);


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
    fun(root);
    return 0;
}

void fun(struct node *root)
{
	struct node *head = NULL, *tail = NULL;
	bst_to_dll(root, &head, &tail);
	while(head != NULL)
	{
		cout<<head->data;
		head = head->right;
	}
}


void bst_to_dll(struct node *root, struct node **head, struct node **tail)
{
	if(root == NULL)
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


