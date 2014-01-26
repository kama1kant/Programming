#include<iostream>

using namespace std;
void rotate_matrix_cw_90(int m[3][3], int n);

int main()
{
    int a[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    rotate_matrix_cw_90(a, 9);


    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}


void rotate_matrix_cw_90(int m[3][3], int n)
{
    int i, j;

    // first mirror the matrix along the diagnal line.
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            int tmp = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = tmp;
        }
    }

    // mirror the matrix horizontally.
    for (i = 0; i < n / 2; i++)
    {
        for (j = 0; j < n; j++)
        {
            int tmp = m[j][i];
            m[j][i] = m[j][n - i - 1];
            m[j][n - i - 1] = tmp;
        }
    }
}
