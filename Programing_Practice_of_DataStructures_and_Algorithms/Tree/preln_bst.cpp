#include<iostream>
#include<stdio.h>
#include<malloc.h>

using namespace std;

struct node* insert(struct node *node, int data);   //Working
struct node* Newnode(int value);    //Working
void inorder(struct node* n);   //Working
struct node* preorder_construct(int pre[], char preln[], int *i);

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
    int pre[] = {1, 2, 3, 4, 6, 7, 5};
    char preln[] = "NLNNLLL";
    int i=0;
    struct node *myroot = preorder_construct(pre, preln, &i);
    inorder(myroot);
    return 0;
}

struct node* preorder_construct(int pre[], char preln[], int *i)
{
	struct node *root = (struct node *)malloc(sizeof(struct node));
	root->data = pre[(*i)];
	root->left = NULL;
	root->right == NULL;
	if(preln[(*i)] == 'N')
	{
		(*i) = (*i)+1;
		root->left = preorder_construct(pre, preln, i);
		root->right = preorder_construct(pre, preln, i);

	}
	else
        (*i) = (*i)+1;
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
