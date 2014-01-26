#include<iostream>
#include<stdio.h>
#include<malloc.h>

using namespace std;

struct node* insert(struct node *node, int data);   //Working
struct node* Newnode(int value);    //Working
void print(struct node *n);     //Working
int size(struct node* node);            //Working
int width_of_bst(struct node *root);
int width_util(struct node *root, int count[], int level);
int height(struct node *root);

struct node
{
    int data;
    struct node* left;
    struct node* right;
};
int main()
{
    struct node* root2;
    struct node* root = NULL;
    //root = insert(root, 8);
    printf("\nHere is Original Tree:\n");
    print(root);
    cout<<"\n\n";
    cout<<width_of_bst(root);

      return 0;
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

int width_of_bst(struct node *root)
{
	int h = height(root);
	cout<<"- "<<h<<endl;
	int max = 0;
	int *count = new int[h];
	for(int i=0;i<h;i++)
	{
		count[i] = 0;
	}

	width_util(root, count, 0);
	for(int i=0;i<h;i++)
	{
		if(count[i]>max)
			max = count[i];
	}
	return max;
}

int width_util(struct node *root, int count[], int level)
{
	if(root == NULL)
		return 0;

	count[level]++;
	width_util(root->left, count, level+1);
	width_util(root->right, count, level+1);
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
