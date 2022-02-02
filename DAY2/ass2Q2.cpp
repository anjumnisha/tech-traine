/*ii) Write a function that takes in a non-empty array of distinct integers and
an integer representing a target sum. The function should find all triplets in the array that
sum up to the target sum and return a two-dimensional array of all these triplets.
The numbers in each triplet should be ordered in ascending order, and the triplets themselves
should be ordered in ascending order with respect to the numbers they hold.
 If no three numbers sum up to the target sum, the function should return an empty array*/
#include<iostream>
#include<vector>
using namespace std;

int findtriplets(int ar[], int n, int sum)
{
    int m = 1;
    vector<vector<int>> vec( m , vector<int> (3));
    for(int i=0;i<n-2;i++)
    {
        for(int j=i+1;j<n-1;j++)
            for(int k=j+1;k<n;k++)
            {
                if(ar[i]+ar[j]+ar[k]==sum)
                    {
                        vec[m-1][0]=ar[i];
                        vec[m-1][1]=ar[j];
                        vec[m-1][2]=ar[k];
                        m++;
                        vec.resize(m, vector<int>(3));
                    }
            }
    }
    for(int i=0;i<m;i++)
       { for(int j=0;j<3;j++)
            cout<<vec[i][j]<<" ";
         cout<<"\n";
       }

}

int main()
{
    int arr[]={1, 2, 3,4,5,6 };
    int sum=12;
    int n=sizeof(arr)/sizeof(arr[0]);

    findtriplets(arr, n, sum);
    cout<<"\n";
    return 0;
}

