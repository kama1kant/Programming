#include<iostream>
#include<stdio.h>
#include<malloc.h>

using namespace std;

struct node* insert(struct node *node, int data);   //Working
struct node* Newnode(int value);    //Working
void inorder(struct node* n);   //Working
void print(struct node *root);
void btree_to_dll_util(struct node *root, struct node **prev, struct node **head);
struct node *btree_to_dll(struct node *root);
struct node
{
    int data;
    struct node* left;
    struct node* right;
    struct node* fp;
    struct node* bp;

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
    struct node *head = btree_to_dll(root);
    print(head);
    return 0;
}

struct node *btree_to_dll(struct node *root)
{
    struct node *prev = NULL;
    struct node *head = NULL;
    btree_to_dll_util(root, &prev, &head);
    return head;

}

void btree_to_dll_util(struct node *root, struct node **prev, struct node **head)
 {
     if(root == NULL)
     {
         return;
     }
     btree_to_dll_util(root->left, prev, head);
     if((*prev) == NULL)
        (*head) = root;
     if((*prev) != NULL)
     {
        (*prev)->fp = root;
        root->bp = (*prev);
     }
     (*prev) = root;
     btree_to_dll_util(root->right, prev, head);
 }


void print(struct node *root)
{
    while(root != NULL)
    {
        cout<<root->data<<" ";
        root = root->fp;
    }
}

struct node* Newnode(int value)
{
    struct node* e = (struct node*)malloc(sizeof(struct node));
    e->data = value;
    e->left = NULL;
    e->right = NULL;
    e->fp = NULL;
    e->bp = NULL;

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

