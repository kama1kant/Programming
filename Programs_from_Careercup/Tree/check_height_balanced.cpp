#include<iostream>
#include<stdio.h>
#include<malloc.h>
#include<math.h>

using namespace std;

struct node* insert(struct node *node, int data);   //Working
struct node* Newnode(int value);    //Working
void inorder(struct node* n);   //Working
int check_height_balanced(struct node *root);
int height(struct node *root);
int max (int a, int b);
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
    struct node* rChild = Newnode(3);
    root->left = lChild;
    root->right= rChild;
    root = insert(root, 8);
    cout<<"Inorder = ";
    inorder(root);
    cout<<"\n";
    cout<<check_height_balanced(root);
    return 0;
}

int check_height_balanced(struct node *root)
{
    if(root == NULL)
        return 1;
    int ldepth = height(root->left);
    int rdepth = height(root->right);
    if( abs(ldepth-rdepth)<1 && check_height_balanced(root->left) && check_height_balanced(root->right) )
    {
        return 1;
    }
    else
        return 0;
}

int height(struct node *root)
{
    if(root == NULL)
        return 0;
    int ld = height(root->left);
    int rd = height(root->right);
    return max(ld, rd)+1;
}

int max (int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
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
       cout<<n->data;
        inorder(n->right);
    }
}

