#include<iostream>
#include<stdio.h>
#include<malloc.h>

using namespace std;

struct node* insert(struct node *node, int data);   //Working
struct node* Newnode(int value);    //Working
void inorder(struct node* n);   //Working
int check_isomorphic(struct node *root1, struct node *root2);
int isswap(struct node *a, struct node *b, struct node *x, struct node *y);
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
int main()
{
    struct node* root = Newnode(2);
    struct node* root2 = Newnode(2);

    struct node* lChild = Newnode(1);
    struct node* rChild = Newnode(3);
    root->left = lChild;
    root->right= rChild;

    struct node* lChild2 = Newnode(1);
    struct node* rChild2 = Newnode(3);
    root2->left = lChild2;
    root2->right= rChild2;


    root = insert(root, 8);
    root2 = insert(root2, 8);
    cout<<"Inorder = ";
    inorder(root);
    cout<<"\n";
    inorder(root2);
    cout<<check_isomorphic(root, root2);
    return 0;
}

int isswap(struct node *a, struct node *b, struct node *x, struct node *y)
{
    int aa, bb, xx, yy;
    if(a->data == NULL)
        aa = 0;
    else
        aa = a->data;

    if(b->data == NULL)
        bb = 0;
    else
        bb = b->data;

    if(x->data == NULL)
        xx = 0;
       else
        xx = x->data;

    if(y->data == NULL)
        yy = 0;
    else
        yy = y->data;
cout<<"\n"<<xx<<" "<<yy<<"\n";
    if((aa==xx && bb==yy) || (aa==yy && bb==xx))
    {

        return 1;
    }

    else
    {
        cout<<"Here";
        return 0;
    }

}

int check_isomorphic(struct node *root1, struct node *root2)
{
    if(root1 == NULL && root2 == NULL)
        return 1;
    else if(root1 == NULL || root2 == NULL)
        return 0;
    else if(isswap(root1->left, root1->right, root2->left, root2->right) && check_isomorphic(root1->left, root2->left) && check_isomorphic(root1->right, root2->right))
    {
        cout<<"ow";
        return 1;
    }
    else
        return 0;
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

