#include<iostream>
#include<stdio.h>
#include<malloc.h>

using namespace std;

struct node* insert(struct node *node, int data);   //Working
struct node* Newnode(int value);    //Working
void print(struct node *n);     //Working
int size(struct node* node);            //Working
int height(struct node *root);
int diameter(struct node *root);

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
    cout<<endl<<diameter(root);
      return 0;
}


int diameter(struct node *root)
{
	if(root == NULL)
		return 0;
	int l = height(root->left);
	int r = height(root->right);
	return max((l+r+1), max(diameter(root->left), diameter(root->right)));
}




int height(struct node *root)
{
	if(root == NULL)
		return 0;
	int l = height(root->left);
	int r = height(root->right);
	if(l>r)
		return (l+1);
	else
		return (r+1);
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

