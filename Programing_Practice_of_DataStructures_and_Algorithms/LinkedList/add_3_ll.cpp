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
struct node* sum(struct node *head1, struct node *head2, struct node *head3);
struct node* sum_ll(struct node *head1, struct node *head2, int n1, int n2, int *carry);

int main()
{
	struct node *head1, *tail,*sortvalue=NULL ,*sort=NULL;
	head1 = NULL;
	tail = NULL;

	struct node *head2, *tail2 ;
	head2 = NULL;
	tail2 = NULL;

	struct node *head3, *tail3;
	head3 = NULL;
	tail3 = NULL;

	add(&head1, &tail, 1);
	add(&head1, &tail, 2);
	add(&head1, &tail, 3);
	add(&head1, &tail, 4);

	add(&head2, &tail2, 5);
	add(&head2, &tail2, 6);
	add(&head2, &tail2, 7);

	add(&head3, &tail3, 5);
	add(&head3, &tail3, 4);
	add(&head3, &tail3, 5);

	//length(&head);
	print_list(&head1);
	cout<<endl;
    print_list(&head2);
    cout<<endl;
    print_list(&head3);
    cout<<endl;
    cout<<endl;
    struct node* head = sum(head1, head2, head3);
    print_list(&head);
	return 0;
}

struct node* sum_ll(struct node *head1, struct node *head2, int n1, int n2, int *carry)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	if(n1 == 0 && n2 == 0)
		return NULL;
	if(n1>n2)
	{
		temp->next = sum_ll(head1->next, head2, --n1, n2, carry);
		temp->value = (head1->value+(*carry))%10;
		(*carry) = (head1->value+(*carry))/10;
	}
	else if(n2>n1)
	{
		temp->next = sum_ll(head1, head2->next, n1, --n2, carry);
		temp->value = (head2->value+(*carry))%10;
		(*carry) = (head2->value+(*carry))/10;
	}
	else
	{
		temp->next = sum_ll(head1->next, head2->next, --n1, --n2, carry);
		temp->value = (head1->value+head2->value+(*carry))%10;
		    cout<<" -- "<<head1->value<<" + "<<head2->value<<" + "<<(*carry)<<" = "<<temp->value<<endl;
		(*carry) = (head1->value+head2->value+(*carry))/10;

	}
	return temp;
}

struct node* sum(struct node *head1, struct node *head2, struct node *head3)
{
	int count1 = length(&head1);
	int count2 = length(&head2);
	int count3 = length(&head3);
	int carry = 0;
	struct node *output = sum_ll(head1, head2, count1, count2, &carry);
	if(carry != 0)
	{
		struct node *temp = (struct node*)malloc(sizeof(struct node));
		temp->value = carry;
		temp->next = output;
		output = temp;
	}
	count1 = length(&output);
	carry = 0;

	struct node *head = sum_ll(output, head3, count1, count3, &carry);
	if(carry != 0)
	{
		struct node *temp = (struct node*)malloc(sizeof(struct node));
		temp->value = carry;
		temp->next = head;
		head = temp;
	}
	return head;
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

