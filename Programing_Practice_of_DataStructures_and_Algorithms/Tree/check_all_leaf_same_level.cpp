#include<iostream>
#include<stdio.h>
#include<malloc.h>

using namespace std;

struct node* insert(struct node *node, int data);   //Working
struct node* Newnode(int value);    //Working
void inorder(struct node* n);   //Working
int check_util(struct node *root, int *ll, int level);
int check(struct node *root);

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
    cout<<check(root);
    return 0;
}

int check(struct node *root)
{
    int leaf_level = 0;
    return check_util(root, &leaf_level, 0);
}

int check_util(struct node *root, int *ll, int level)
{
    if(root == NULL)
        return 1;
    if(root->left == NULL && root->right == NULL)
    {
        if(*ll != 0)
        {
            if(level == *ll)
                return 1;
            else
                return 0;

        }
        else
        {
            *ll = level;
        }
    }
    return check_util(root->left, ll, level+1) && check_util(root->right, ll, level+1);
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

