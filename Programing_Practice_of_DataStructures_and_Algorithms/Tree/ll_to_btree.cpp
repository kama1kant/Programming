#include<iostream>
#include<stdio.h>
#include<malloc.h>
#include<queue>

using namespace std;

struct nodet
{
    int data;
    struct nodet* left;
    struct nodet* right;
};

struct node
{
	int value;
	struct node *next;
};

void add(struct node **head, struct node **tail, int value);        //Working
void print_list(struct node **head);        //Working
void length(struct node **head);        //Working
struct nodet* create_node(int value);
void inorder(struct nodet* n);
struct nodet*  create_tree_fom_ll(struct node *head);

int main()
{
	struct node *head, *tail,*sortdata=NULL ,*sort=NULL;
	head = NULL;
	tail = NULL;

	struct node *head2, *tail2 ;
	head2 = NULL;
	tail2 = NULL;

	struct node *a1, *a2 ,*a3, *a4;
	a1 = NULL;
	a2 = NULL;
	a3 = NULL;
	a4 = NULL;
	add(&head, &tail, 2);
	add(&head, &tail, 4);
	add(&head, &tail, 5);
	add(&head, &tail, 7);
	add(&head, &tail, 55);
	length(&head);
	print_list(&head);
    struct nodet *root = create_tree_fom_ll(head);
	cout<<"print tree \n";
	inorder(root);
	return 0;
}

struct nodet*  create_tree_fom_ll(struct node *head)
{
	queue<struct nodet*> myq;
    if(head == NULL)
        return NULL;
	struct nodet *root = create_node(head->value);
	struct nodet *r = root;
	myq.push(root);
	head = head->next;
	while(head != NULL)
	{
		struct nodet *root = myq.front();
		myq.pop();
		if(head != NULL)
		{
			root->left = create_node(head->value);
			myq.push(root->left);
		}
		head = head->next;
		if(head != NULL)
		{
			root->right = create_node(head->value);
			myq.push(root->right);
		}
		head = head->next;
	}
	return r;
}

void inorder(struct nodet* n)
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


struct nodet* create_node(int value)
{
    struct nodet* e = (struct nodet*)malloc(sizeof(struct nodet));
    e->data = value;
    e->left = NULL;
    e->right = NULL;
    return e;
}


void length(struct node **head)
{
	struct node*c;
	c = *head;
	int count=0;
	while(c!=NULL)
	{
		c = c->next;
		count++;
	}
	printf("length = %d", count);
}

void add(struct node **head, struct node **tail, int value)
{
	struct node *temp, *ttail, *thead;
	ttail = *tail;
	temp = (struct node *) malloc(sizeof(struct node));
	temp->next=NULL;
	temp->value=value;
	if(*head==NULL)
	{
		*head=temp;
		*tail=temp;
	}
	else
	{
		(*tail)->next=temp;
		*tail=temp;
	}
}

void print_list(struct node **head)
{
	struct node *temp;
	printf("\n\n");
	for(temp=*head; temp!=NULL; temp=temp->next)
	{
		printf("%d->",(temp->value));
	}
	printf("[NULL]\n\n");
}
