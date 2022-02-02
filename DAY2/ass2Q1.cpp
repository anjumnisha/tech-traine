/*Day 2 Assignment
(i)Write a program to remove duplicate values from an array and returns an array of unique values. int[] removeDuplicates(int[]values)*/
#include<iostream>
using namespace std;

int removeduplicate(int a[], int n)
{
    int i, j, c;
    for(i=0;i<n;i++)
     for(j=i+1;j<n;j++)
     {  if(a[i]==a[j])
        {   c=j;
            while(c<n)
            { a[c]=a[c+1];
               c++;
                } n--; j--;
            }
    }
     for(i=0;i<n;i++)
     {  cout<<a[i]<<" ";     }
}
int main()
{
    int n;
    cout<<"Enter size :";
    cin>>n;
    int ar[n];
    cout<<"\nEnter "<<n<<" elements :";
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    cout<<"\nArray after removing duplicates :";
    removeduplicate(ar,n);
    cout<<"\n";
    return 0;
}
