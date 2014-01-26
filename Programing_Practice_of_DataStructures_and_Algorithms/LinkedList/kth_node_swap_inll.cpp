#include<iostream>
#include<stdio.h>
#include<malloc.h>

using namespace std;

struct node
{
	int value;
	struct node *next;
};

void add(struct node **head, struct node **tail, int value);        //Working
void print_list(struct node **head);        //Working
int length(struct node **head);        //Working
void swap_kll(struct node **head, int k);

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
	add(&head, &tail, 7);
	add(&head, &tail, 8);
	length(&head);
	print_list(&head);
    printf("First linked list is been made succefully");
    cout<<endl;
    swap_kll(&head, 2);
    print_list(&head);
	return 0;
}

void swap_kll(struct node **head, int k)
{
	int l = length(head);
	if(k == 0 || k > l || 2*k-1 == l)
		return;
	struct node *x = *head;
	struct node *x_prev = NULL;
	struct node *y = *head;
	struct node *y_prev = NULL;
	struct node *temp = NULL;

	for(int i=1;i<k;i++)
	{
		x_prev = x;
		x = x->next;
	}
	for(int i=1;i<l-k+1;i++)
	{
		y_prev = y;
		y = y->next;
	}
	if(x_prev)
		x_prev->next = y;
	if(y_prev)
		y_prev->next = x;

	temp = x->next;
	x->next = y->next;
	y->next = temp;

	if(k == 1)
		*head = y;
	if(k == l)
		*head = x;
}

int length(struct node **head)
{
	struct node*c;
	c = *head;
	int count=0;
	while(c!=NULL)
	{
		c = c->next;
		count++;
	}
	//printf("length = %d", count);
    return count;
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
