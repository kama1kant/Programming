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
int ll_pallindrome(struct node **head);
int compare(struct node *head1, struct node *head2);
void reverse(struct node **head);

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
	add(&head, &tail, 7);
	add(&head, &tail, 4);
	add(&head, &tail, 2);

	length(&head);
	print_list(&head);
    printf("First linked list is been made succefully");
    cout<<endl;
    int p = ll_pallindrome(&head);
	cout<<p<<" yee"<<endl;
	return 0;
}


int ll_pallindrome(struct node **head)
{
	struct node *current = *head;
	struct node *prev = NULL;
	struct node *next = NULL;
	struct node *mid = NULL;

	int l = length(head);
	int i=1;
	while(i < (l/2))
	{
		prev = current;
		current = current->next;
		i++;
	}
	if(l%2 != 0)
	{
		mid = current->next;
		next = current->next->next;
	}
	else
		next = current->next;
	current->next = NULL;
	reverse(&next);
	int flag = compare(*head, next);
	if(flag == 1)
		return 1;
	else
		return 0;
}

int compare(struct node *head1, struct node *head2)
{
	while(head1 != NULL && head2 != NULL)
	{
		if(head1->value != head2->value)
			return 0;
		head1 = head1->next;
		head2 = head2->next;
	}
	if(head1 || head2)
		return 0;
	return 1;
}

void reverse(struct node **head)
{
	struct node *current = *head;
	struct node *prev = NULL;
	struct node *nextt = NULL;
	while(current != NULL)
	{
		nextt = current->next;
		current->next = prev;
		prev = current;
		current = nextt;

	}
	*head = prev;
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
