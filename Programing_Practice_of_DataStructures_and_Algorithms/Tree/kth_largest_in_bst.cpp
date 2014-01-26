#include<iostream>
#include<stdio.h>
#include<malloc.h>

using namespace std;

struct node* insert(struct node *node, int data);   //Working
struct node* Newnode(int value);    //Working
void inorder(struct node* n);   //Working
void kth_l_elem(struct node *root, int k);

int count = 0;

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
    cout<<endl;
    kth_l_elem(root, 5);
    return 0;
}

void kth_l_elem(struct node *root, int k)
{
    if(root == NULL)
        return;
    kth_l_elem(root->right, k);
    count++;
    if(count == k)
    {
        cout<<root->data;
    }
    kth_l_elem(root->left, k);
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

