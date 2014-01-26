#include<iostream>
#define ROW 5
#define COL 4
using namespace std;

void print_matrix_diagonally(int a[ROW][COL], int n);

int main()
{
    int a[ROW][COL] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    for(int i=0;i<ROW;i++)
    {
        for(int j=0;j<COL;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    print_matrix_diagonally(a, 20);
    return 0;
}

void print_matrix_diagonally(int a[ROW][COL], int n)
{
	int start_col, count;
	for(int i=1;i<ROW+COL-1;i++)
	{
		start_col = max(0, i-ROW);
		count = min(i, COL-start_col);
		for(int j=0;j<count;j++)
		{
                int row = min(i, ROW)-j-1;
			cout<<a[row][start_col+j]<<" ";
		}
		cout<<endl;
	}
}
