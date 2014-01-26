#include<iostream>
#include<stdio.h>
#include<malloc.h>

using namespace std;

struct node* insert(struct node *node, int data);   //Working
struct node* Newnode(int value);    //Working
void inorder(struct node* n);   //Working
int diff_odd_even_height(struct node *root);


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
    struct node* lChild = Newnode(3);
    struct node* rChild = Newnode(9);
    root->left = lChild;
    root->right= rChild;
    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 8);
    root = insert(root, 10);
    cout<<"Inorder = ";
    inorder(root);
    cout<<endl;
    cout<<diff_odd_even_height(root);
    return 0;
}

int diff_odd_even_height(struct node *root)
{
	if(root == NULL)
		return 0;
	return -(root->data + diff_odd_even_height(root->left) + diff_odd_even_height(root->right));
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
