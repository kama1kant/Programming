#include<iostream>

using namespace std;

int check_string(char a[], int len);

int main()
{
    char a[] = "aabbbca";
    check_string(a, 6);
    return 0;
}

int check_string(char a[], int len)
{
    char init1 = a[0], init2 = '\0';
    int loc1 = -1, loc2 = -1;
    for(int i=0;i<len;i++)
    {
        if(a[i-1] != init1 && a[i] == init1)
        {
            loc1 = i;
        }
        else if (a[i-1] != init2 && a[i] == init2)
        {
            loc2 = i;
        }
        if(a[i] != init1)
        {
            if(init2 == '\0')
            {
                init2 = a[i];
            }
            else if(init1 == a[i-1])
                {
                    init2 = a[i];
                }
            else if(init2 == a[i-1])
            {
                init1 = a[i];
            }
        }
    }
    cout<<init1<<" "<<init2;
}
