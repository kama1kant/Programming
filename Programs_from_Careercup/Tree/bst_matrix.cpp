#include<iostream>
#include<stdio.h>
#include<malloc.h>

using namespace std;

struct node* insert(struct node *node, int data);   //Working
struct node* Newnode(int value);    //Working
void inorder(struct node* n);   //Working
void bst_to_dll(struct node *root);
void print_dll(struct node *head);
void merge_dll(struct node *head1, struct node *head2);
void bst_to_matrix(struct node* root, int a[][4], int p);

struct node *previous = NULL;
struct node *head = NULL;
struct node *tail = NULL;

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

int temp[7];

int main()
{
    struct node* root = Newnode(2);
    struct node* lChild = Newnode(1);
    struct node* rChild = Newnode(3);
    root->left = lChild;
    root->right= rChild;
    root = insert(root, 4);

    cout<<"Inorder = ";
    inorder(root);
    cout<<"\n";
    int a[4][4]={0};
    bst_to_matrix(root, a, 0);
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

void bst_to_matrix(struct node* root, int a[][4], int p)
{
    if(root == NULL)
        return;
    temp[p] = root->data;
    bst_to_matrix(root->left, a,p+1);
    bst_to_matrix(root->right, a,p+1);
    for(int i=0;i<p;i++)
    {
        a[temp[i]-1][temp[p]-1] = 1;
        //cout<<temp[i]<<" "<<temp[p]<<endl;
    }

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
