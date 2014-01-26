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
void delete_kth_node(struct node **head, int k);

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
	print_list(&head);
    cout<<endl;
    //printf("First linked list is been made succefully");
    delete_kth_node(&head, 0);
    print_list(&head);
	return 0;
}


void delete_kth_node(struct node **head, int k)
{
    struct node *h = *head;
    if((*head) == NULL)
        return;
	if(k == 0)
		return;
	else if(k == 1)
	{
		struct node *temp = (*head);
		(*head) = (*head)->next;
		free(temp);
		return;
	}
	int i=1;
	while(i < k-1)
	{
		(*head) = (*head)->next;
		i++;
		if(((*head) == NULL) || (*head)->next == NULL)
		{
		    (*head) = h;
		    return;
		}

	}
	struct node *temp = (*head)->next;
	(*head)->next = (*head)->next->next;
	free(temp);
	(*head) = h;
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
