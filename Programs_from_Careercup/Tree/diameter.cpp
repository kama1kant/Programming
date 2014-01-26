#include<iostream>
#include<stdio.h>
#include<malloc.h>

using namespace std;

struct node* insert(struct node *node, int data);   //Working
struct node* Newnode(int value);    //Working
void inorder(struct node* n);   //Working
int diameter_util(struct node *root, int *height);


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
    root = insert(root, -8);
    root = insert(root, -7);
    root = insert(root, -17);
    root = insert(root, -6);
    root = insert(root, -18);
    root = insert(root, -19);
    root = insert(root, -20);

    cout<<"Inorder = ";
    inorder(root);
    cout<<endl;
    int h=0;
    cout<<diameter_util(root, &h);
    return 0;
}

int diameter_util(struct node *root, int *height)
{
	if(root == NULL)
	{
		*height = 0;
		return 0;
	}
	int lh = 0, rh = 0;
	int ld = diameter_util(root->left, &lh);
	int rd = diameter_util(root->right, &rh);
	if(lh > rh)
		*height = lh+1;
	else
		*height = rh+1;
	return max(lh+rh+1, max(ld, rd));
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

