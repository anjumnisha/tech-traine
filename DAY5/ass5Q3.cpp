/*3. Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
Input: matrix = 1 3 5 7 10 11 16 20 23 30 34 60, target = 3
Output: true*/
#include<iostream>
using namespace std;
bool issorted(int arr[],int n)
{
    int coun=0;
    for(int i=1;i<=n;i++)
    {
        if(arr[i]>arr[i-1])
            coun++;
    }
    if(coun+1!=n)
        return false;
    else
        return true;
}
int main()
{
    int m , n;
    cout<<"Enter m and n ";
    cin>>m>>n;
    int mat[m][n];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
    {
        cin>>mat[i][j];
    }
    int target;
    cout<<"Enter target value ";
    cin>>target;
    //check target value
    int flag=0;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(mat[i][j]==target)
    {
            flag=1;
    }

    int arr[n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            arr[j]=mat[i][j];
        }
        //check if sorted
        if(issorted(arr,n)==false)
            {
                cout<<"\nfalse\n";
                return 0;
            }
    }

    //check first with last element
    for(int i=1;i<m;i++)
    {
        if(mat[i][0]<mat[i-1][n-1])
        {
            cout<<"\nfalse\n";
            return 0;
        }
    }
    if(flag=1)
    cout<<"\ntrue\n";

    return 0;
}
