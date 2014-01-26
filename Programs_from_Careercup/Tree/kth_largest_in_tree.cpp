#include<iostream>
#include<stdio.h>
#include<malloc.h>

using namespace std;

struct node* insert(struct node *node, int data);   //Working
struct node* Newnode(int value);    //Working
void inorder(struct node* n);   //Working
void kth_largest_util(struct node *root, int *k, int i, struct node **n);
struct node* kth_largest(struct node *root, int i);

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
    root = insert(root, 12);
    root = insert(root, 7);
    cout<<"Inorder = ";
    inorder(root);
    cout<<endl;
    struct node *temp = kth_largest(root, 4);
    cout<<temp->data;
    return 0;
}

struct node* kth_largest(struct node *root, int i)
{
	int k = 0;
	struct node *n = NULL;
	kth_largest_util(root, &k, i, &n);
	return n;
}

void kth_largest_util(struct node *root, int *k, int i, struct node **n)
{
	if(root == NULL)
		return;
	kth_largest_util(root->right, k, i, n);
	*k = *k+1;
	if(*k == i)
		*n = root;
	kth_largest_util(root->left, k, i, n);

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
