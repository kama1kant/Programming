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
void det_rem_loop(struct node *head);
void remove_loop(struct node *head, struct node *loop);
void remove_loop(struct node *head, struct node *loop);

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
	add(&head, &tail, 5);
	add(&head, &tail, 9);
	tail->next = head->next->next;
	det_rem_loop(head);
	return 0;
}

struct node* detect_loop(struct node *head)
{
	int flag = 0;
	struct node *fast = head;
	struct node *slow = head;
	while(fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast)
		{
			flag = 1;
			break;
		}
	}
	if(flag == 0)
		return NULL;
	else
		return slow;
}

void remove_loop(struct node *head, struct node *loop)
{
	int count = 0;
	struct node *temp1 = loop;
	struct node *temp2 = head;
	struct node *temp3 = head;
	do
	{
		temp1 = temp1->next;
		count++;
	}while(temp1 != loop);
	for(int i=1;i<count;i++)
	{
		temp2 = temp2->next;
	}
	while(temp2->next != temp3)
	{
		temp2 = temp2->next;
		temp3 = temp3->next;
	}
	temp2->next = NULL;
}

void det_rem_loop(struct node *head)
{
	struct node *loop = detect_loop(head);
	if(loop == NULL)
	{
		cout<<"No loop";
		return;
	}
	remove_loop(head, loop);
	print_list(&head);
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
