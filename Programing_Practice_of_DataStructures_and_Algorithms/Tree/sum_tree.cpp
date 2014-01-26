#include<iostream>
#include<stdio.h>
#include<malloc.h>

using namespace std;

struct node* insert(struct node *node, int data);   //Working
struct node* Newnode(int value);    //Working
void print(struct node *n);     //Working
int size(struct node* node);            //Working
int sum_tree_util(struct node *root);

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
    printf("\nHere is Original Tree:\n");
    print(root);
    sum_tree_util(root);
    cout<<endl;
    print(root);

      return 0;
}


int sum_tree_util(struct node *root)
{
	if(root == NULL)
		return 0;
	int l = sum_tree_util(root->left);
	int r = sum_tree_util(root->right);
	int old = root->data;
	root->data = l+r;
	return (root->data + old);
}


int size(struct node* node) {
if (node==NULL) {
return(0);
} else {
return(size(node->left) + 1 + size(node->right));
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

void print(struct node *n)
{
    if(n==NULL)
    return;
    else
    {
        print(n->left);
        printf("%d", n->data);
        print(n->right);
    }
}

