#include<iostream>

using namespace std;
void rotate(int matrix[3][3], int n);


int main()
{
    int a[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            //cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
    rotate(a, 3);
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            //cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}



void rotate(int matrix[3][3], int n)
{
    for (int layer = 0; layer < n / 2; ++layer) {
	int first = layer;
	int last = n - 1 - layer;
	cout<<"first = "<<first<<" last = "<<last<<endl;
	for (int i = first; i < last; ++i) {
	    int offset = i - first;
	    int top = matrix[first][i];	// save top
	    // left -> top
	    matrix[first][i] = matrix[last - offset][first];
        cout<<"a["<<first<<"]["<<i<<"] = a["<<last-offset<<"]["<<first<<"]"<<endl;
	    // bottom -> left
	    matrix[last - offset][first] = matrix[last][last - offset];
        cout<<"a["<<last-offset<<"]["<<first<<"] = a["<<last<<"]["<<last-offset<<"]"<<endl;

	    // right -> bottom
	    matrix[last][last - offset] = matrix[i][last];
        cout<<"a["<<last<<"]["<<last-offset<<"] = a["<<i<<"]["<<last<<"]"<<endl;
	    // top -> right
	    matrix[i][last] = top;	// right <- saved top
        cout<<"a["<<i<<"]["<<last<<"] = "<<top<<endl;
	}
    }
}

