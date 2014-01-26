#include<iostream>
#include<stdio.h>
#include<malloc.h>
#include<stack>

using namespace std;

struct node* insert(struct node *node, int data);   //Working
struct node* Newnode(int value);    //Working
void inorder(struct node* n);   //Working
void zigzag_traversal(struct node *root);


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
    zigzag_traversal(root);
    return 0;
}

void zigzag_traversal(struct node *root)
{
	int flag = 0;
	struct node *temp = NULL;
	stack<struct node *>mystack1;
	stack<struct node *>mystack2;
	mystack1.push(root);
	while(1)
	{
	    if(mystack1.empty() && mystack2.empty())
            break;
	    if(flag == 0)
		{
			while(!mystack1.empty())
			{
				temp = mystack1.top();
				mystack1.pop();
				cout<<temp->data;
				if(temp->right != NULL)
					mystack2.push(temp->right);
				if(temp->left != NULL)
					mystack2.push(temp->left);
			}
			flag = 1;
		}
		else if(flag == 1)
		{
			while(!mystack2.empty())
			{
				temp = mystack2.top();
				mystack2.pop();
				cout<<temp->data;
				if(temp->left != NULL)
					mystack1.push(temp->left);
				if(temp->right != NULL)
					mystack1.push(temp->right);
			}
			flag = 0;
		}
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

