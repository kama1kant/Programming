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
struct node* sum3(struct node *l1, struct node *l2, struct node *l3);
struct node* sum2(struct node *l1, struct node *l2);
struct node* sum_same(struct node *l1, struct node *l2, int *carry);
struct node *add_carry(struct node *l, int *carry);

int main()
{
	struct node *head, *tail,*sortdata=NULL ,*sort=NULL;
	head = NULL;
	tail = NULL;

	add(&head, &tail, 2);
	add(&head, &tail, 4);
	add(&head, &tail, 7);
	add(&head, &tail, 8);
	add(&head, &tail, 5);
	print_list(&head);
cout<<endl;
struct node *head2, *tail2 ;
	head2 = NULL;
	tail2 = NULL;
	add(&head2, &tail2, 2);
	add(&head2, &tail2, 4);
	add(&head2, &tail2, 7);
	add(&head2, &tail2, 8);
	print_list(&head2);
cout<<endl;

struct node *head3, *tail3 ;
	head3 = NULL;
	tail3 = NULL;
	add(&head3, &tail3, 2);
	add(&head3, &tail3, 4);
	add(&head3, &tail3, 7);
	print_list(&head3);
cout<<endl;

    printf("First linked list is been made succefully");
    struct node *head4 = sum3(head, head2, head3);
    print_list(&head4);
	return 0;
}

struct node* sum3(struct node *l1, struct node *l2, struct node *l3)
{
    struct node *temp = sum2(l1, l2);
    struct node *res = sum2(temp, l3);
    return res;
}

struct node* sum2(struct node *l1, struct node *l2)
{
    int len1 = length(&l1);
    int len2 = length(&l2);
    if(len2 > len1)
    {
        struct node *t = l1;
        l1 = l2;
        l2 = t;
    }
    struct node *tl1 = NULL;
    if(len1 != len2)
    {
           for(int i=1;i<abs(len1-len2);i++)
        {
            l1 = l1->next;
        }
        tl1 = l1->next;
        l1->next = NULL;
        int carry = 0;

        struct node *rl = sum_same(tl1, l2, &carry);
        if(carry)
        {
            add_carry(l1, &carry);
        }
        tl1 = l1;
        while(l1->next != NULL)
        {
            l1 = l1->next;
        }
        l1->next = rl;
        return tl1;

    }
    if(len1 == len2)
    {
        int carry = 0;
        struct node *rl = sum_same(l1, l2, &carry);
        if(carry)
        {
            struct node *n = (struct node *)malloc(sizeof(struct node));
            n->value = carry;
            n->next = rl;
            rl = n;
        }
        return rl;
    }
}

struct node* sum_same(struct node *l1, struct node *l2, int *carry)
{
    if(l1 == NULL)
        return NULL;
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->next = sum_same(l1->next, l2->next, carry);
    n->value = (l1->value+l2->value+(*carry))%10;
    (*carry) = (l1->value+l2->value+(*carry))/10;
    return n;
}

struct node *add_carry(struct node *l, int *carry)
{
    if(l == NULL)
        return NULL;
    l->next = add_carry(l->next, carry);
    l->value = (l->value+*carry)%10;
    (*carry) = (l->value+*carry)/10;
    return l;
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
