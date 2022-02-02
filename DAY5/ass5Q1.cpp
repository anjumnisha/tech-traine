/*1. Write a method void printArray(int[][]arr)
Prints array elements clock wise and anti-clockwise alternatively.
Input :
 1 2 3
 4 5 6
 7 8 9
Output :
1 2 3 6 9 8 7 4 5
3 2 1 4 7 8 9 6 5*/
#include<iostream>
using namespace std;
int main()
{
    int row , col;
    cout<<"Enter row and column of 2d array :";
    cin>>row>>col;
    int arr[row][col];
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            cin>>arr[i][j];

    int arow=row, acol=col;

    cout<<"\n clock wise ";
    int r=0, c=0;
    int coun=0 , total=row*col;
    while(coun!=total)
    {   //first row
        for(int i=c;i<col;i++)
            {cout<<arr[r][i]<<" ";
            coun++;}

        r++;
        //last col
        for(int i=r;i<row;i++)
            {cout<<arr[i][col-1]<<" ";
            coun++;}

        col--;
        //last row
        for(int i=col-1;i>=c;i--)
            {cout<<arr[row-1][i]<<" ";
            coun++;}
        row--;

        // first col
        for(int i=row-1;i>=r;i--)
            {cout<<arr[i][c]<<" ";
            coun++;}
        c++;
    }
    cout<<"\nanti clock wise ";
    r=0;
    c=0;
    coun=0;
    while(coun!=total)
    {
        //first row
        for(int i=acol-1;i>=r;i--)
            {cout<<arr[r][i]<<" ";
             coun++;}
        r++;
        //first col
        for(int i=r;i<acol;i++)
            {cout<<arr[i][c]<<" ";
             coun++;
            }
        c++;
        //last row
        for(int i=c;i<acol;i++)
        {cout<<arr[arow-1][i]<<" ";
         coun++;
        }
        arow--;
        //last col
        for(int i=arow-1;i>=r;i--)
        {cout<<arr[i][acol-1]<<" ";
         coun++;
        }
        acol--;
    }

    return 0;
}
