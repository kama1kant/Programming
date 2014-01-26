#include<iostream>
#include<stdio.h>
#include<malloc.h>

using namespace std;

struct node* insert(struct node *node, int data);   //Working
struct node* Newnode(int value);    //Working
void inorder(struct node* n);   //Working
void fun(struct node *root);
void replace_greater(struct node *root, int *sum);

struct node
{
    int data;
    struct node* left;
    struct node* right;
};
int main()
{
    struct node* root2;
    struct node* root = Newnode(2);
    struct node* lChild = Newnode(1);
    struct node* rChild = Newnode(5);
    root->left = lChild;
    root->right= rChild;
    root = insert(root, 4);

    cout<<"Inorder = ";
    inorder(root);
    fun(root);
    cout<<endl;
    inorder(root);
    return 0;
}

void fun(struct node *root)
{
    int sum = 0;
    replace_greater(root, &sum);
}

void replace_greater(struct node *root, int *sum)
{
	if(root == NULL)
		return;
	replace_greater(root->right, sum);
	int temp = root->data;
	root->data = (*sum);
	(*sum) += temp;
	replace_greater(root->left, sum);
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
