#include<iostream>
#include<stdio.h>
#include<malloc.h>

using namespace std;

struct node* insert(struct node *node, int data);   //Working
struct node* Newnode(int value);    //Working
void inorder(struct node* n);   //Working
int compare(struct node *root, int sum);
void bst_to_dll(struct node *root, struct node **head, struct node **tail);


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
    cout<<compare(root, 27);
    return 0;
}

void bst_to_dll(struct node *root, struct node **head, struct node **tail)
{
	if(root == NULL)
		return;
	bst_to_dll(root->left, head, tail);
	if((*tail) == NULL && (*head) == NULL)
	{
		(*head) = root;
		(*tail) = root;
	}
	else
	{
		(*tail)->right = root;
		root->left = (*tail);
		(*tail) = root;
	}
	bst_to_dll(root->right, head, tail);
}

int compare(struct node *root, int sum)
{
	int count = 0;
	struct node *head = NULL;
	struct node *tail = NULL;
	struct node *head2 = NULL;
	struct node *tail2 = NULL;
	bst_to_dll(root, &head, &tail);
	head2 = head;
	tail2 = tail;
	while(head2 != tail2 && tail2->left != head2)
	{
		if(head2->data + tail2->data == sum)
		{
			count++;
			head2 = head2->right;
			tail2 = tail2->left;
		}
		else if(head2->data + tail2->data < sum)
		{
			head2 = head2->right;
		}
		else
		{
			tail2 = tail2->left;
		}
	}
	return count;
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

