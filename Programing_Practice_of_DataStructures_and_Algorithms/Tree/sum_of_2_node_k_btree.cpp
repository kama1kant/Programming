#include<iostream>
#include<stdio.h>
#include<malloc.h>

using namespace std;

struct node* insert(struct node *node, int data);   //Working
struct node* Newnode(int value);    //Working
void inorder(struct node* n);   //Working
void find(struct node *root, int sum);
void tree_to_array(struct node *root, int a[], int *index);
int size(struct node *root);

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
    root = insert(root, -1);
    root = insert(root, 13);
    root = insert(root, 7);
    cout<<"Inorder = ";
    inorder(root);
    cout<<endl;
    find(root, 13);
    return 0;
}

void find(struct node *root, int sum)
{
    int l = size(root);
    int *a = new int [l];
    int x=0, i=0, j=l-1;
    tree_to_array(root, a, &x);
    while(i<j)
    {
        if(a[i] + a[j] == sum)
        {
            cout<<a[i]<<","<<a[j]<<endl;
            i++;
            j--;
        }
        else if(a[i]+a[j] < sum)
            i++;
        else
            j--;
    }
}


void tree_to_array(struct node *root, int a[], int *index)
{
    if(root == NULL)
        return;
    tree_to_array(root->left, a, index);
    a[(*index)] = root->data;
    *index = *index+1;
    tree_to_array(root->right, a, index);
}

int size(struct node *root)
{
    if(root == NULL)
        return 0;
    return size(root->left)+1+size(root->right);
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

