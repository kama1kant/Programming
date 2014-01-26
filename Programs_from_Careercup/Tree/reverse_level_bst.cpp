#include<iostream>
#include<stdio.h>
#include<malloc.h>
#include<stack>
#include<queue>

using namespace std;

struct node* insert(struct node *node, int data);   //Working
struct node* Newnode(int value);    //Working
void inorder(struct node* n);   //Working
void reverse_level_traversal(struct node *root, queue<struct node*> myqueue, stack<struct node*> mystack);
void fun(struct node *root);

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
    fun(root);
    return 0;
}

void fun(struct node *root)
{
	queue<struct node*> myqueue;
	stack<struct node*> mystack;
	reverse_level_traversal(root, myqueue, mystack);
}


void reverse_level_traversal(struct node *root, queue<struct node*> myqueue, stack<struct node*> mystack)
{
	if(root == NULL)
		return;
	myqueue.push(root);
	while(!myqueue.empty())
	{
		struct node *temp = myqueue.front();
		myqueue.pop();
		if(temp->right != NULL)
			myqueue.push(temp->right);
		if(temp->left != NULL)
			myqueue.push(temp->left);
		mystack.push(temp);
	}
	while(!mystack.empty())
	{
		cout<<mystack.top()->data;
		mystack.pop();
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
       cout<<n->data<<" ";
        inorder(n->right);
    }
}

