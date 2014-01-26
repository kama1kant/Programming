#include<iostream>

using namespace std;

struct node
{
    int n;
    int count;
    string s;
    struct node *left;
    struct node *right;
};

int main()
{
    int num = 1123;
    num = reverse(num);
    struct node *root = create(num);
    return 0;
}

struct node* create(int n, int flag)
{
    if(n <= 1)
        return NULL;
    if(n > 0)
        root->left = create(n/10, 0);
    if(n > 0)
        root->left = create(n/100, 1);
    if(flag == 0)
    {
        struct node *root = newnode();
        x = n%10;
        s.push_back(convert(x));
        return root;
    }
    if(flag == 1)
    {
        x = n%10;
        n /= 10;
        if(n <= 0)
            return NULL;
        x = x*10 + (n%10);
        if(x > 26)
            return NULL;
        s.push_back(convert());
    }
}

struct node *newnode()
{
    struct node *root = (struct node *)malloc(sizeof(struct node));
    root->left = NULL;
    root->right = NULL;
    root->s = "";
    root->n = 0;
    root->count = 0;
    return root;
}

int reverse(int n)
{
    int s = 0;
    while(n>0)
    {
        s = s*10 + (n%10);
        n /= 10;
    }
    return s;
}
