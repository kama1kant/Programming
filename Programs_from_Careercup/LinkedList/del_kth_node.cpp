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
void length(struct node **head);        //Working
void del_kth_node(struct node **head, int k);
void print_list2(struct node *head);

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
	add(&head, &tail, 7);
	add(&head, &tail, 55);
	length(&head);
	tail->next = head;
	print_list2(head);
    cout<<endl;
    del_kth_node(&head, 3);
    print_list2(head);
	return 0;
}

void print_list2(struct node *head)
{
	struct node *temp1 = head;
	struct node *temp2 = head;

	printf("\n\n");
    do
    {
        cout<<temp1->value<<" -> ";
        temp1 = temp1->next;
    }while(temp1 != temp2);

	printf("[NULL]\n\n");
}

void del_kth_node(struct node **head, int k)
{
	struct node *cur = *head;
	struct node *temp = NULL;
	while(cur != cur->next)
	{
		for(int i=1;i<k-1;i++)
		{
			cur = cur->next;
		}
		temp = cur->next;
		cur->next = cur->next->next;
		free(temp);
	}
	*head = cur;
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
