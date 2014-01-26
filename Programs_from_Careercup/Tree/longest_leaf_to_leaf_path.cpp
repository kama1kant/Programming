#include<iostream>
#include<stdio.h>
#include<malloc.h>

using namespace std;

struct node* insert(struct node *node, int data);   //Working
struct node* Newnode(int value);    //Working
void inorder(struct node* n);   //Working
int longest_leaf_to_leaf_path(struct node *root);
int height(struct node *root);
int max(int a, int b, int c);
int max2(int a, int b);

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
    root = insert(root, 9);
    root = insert(root, 7);
    root = insert(root, 6);
    root = insert(root, 5);
    root = insert(root, 12);
    root = insert(root, 14);
    root = insert(root, 16);
    cout<<"Inorder = ";
    inorder(root);
    cout<<endl;
    cout<<longest_leaf_to_leaf_path(root);
    return 0;
}
int longest_leaf_to_leaf_path(struct node *root)
{
    if(root == NULL)
        return 0;

    return max(height(root->left)+height(root->right)+1, longest_leaf_to_leaf_path(root->left), longest_leaf_to_leaf_path(root->right));
}

int height(struct node *root)
{
    if(root == NULL)
        return 0;
    int ldepth = height(root->left);
    int rdepth = height(root->right);
    return max2(ldepth, rdepth)+1;
}
int max(int a, int b, int c)
{
    int max = a>b?a>c?a:c:b>c?b:c;
    return max;
}

int max2(int a, int b)
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

