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
void keep_m_del_n(struct node *head, int m, int n);


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
	add(&head, &tail, 5);
    add(&head, &tail, 9);
    add(&head, &tail, 10);
    add(&head, &tail, 11);


	length(&head);
	print_list(&head);
    cout<<endl;
    keep_m_del_n(head, 3, 2);
    print_list(&head);
	return 0;
}

void keep_m_del_n(struct node *head, int m, int n)
{
	struct node *mcur = head;
	if(mcur == NULL)
		return;
	while(1)
	{
		for(int i=1;i<m;i++)
		{
			if(mcur == NULL)
				break;
			mcur = mcur->next;
		}
		if(mcur == NULL)
            return;
		struct node *ncur = mcur->next;
		struct node *temp =NULL;

		for(int i=1;i<=n;i++)
		{
			if(ncur == NULL)
				break;
			temp = ncur;
			ncur = ncur->next;
			free(temp);
		}
		if(ncur == NULL)
        {
             mcur->next = NULL;
             return;
        }
        else
            mcur->next = ncur;
		mcur = mcur->next;
	}
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
