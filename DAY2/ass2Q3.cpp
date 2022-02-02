/*iii) Write a program to print the below pattern:
N should be an odd number and the value of N should be more than 4
Output:
//        \*****/
//        *\***/*
//        **\*/**
//        ***/***
//        **/*\**
//        */***\*
//        /*****\
*/
#include<iostream>
using namespace std;
int main()
{
    int N;
    cout<<"Enter : ";
    cin>>N;
    int left=0, right=N+1;        //left=\    right=/
    if(N%2!=0 && N>4)
    {
        for(int i=0;i<N+2;i++)
        {
            for(int j=0;j<N+2;j++)
            {
                if(left==right &&j==right)
                    cout<<"/";
                else if(j==left)
                    cout<<"\\";
                else if(j==right)
                    cout<<"/";
                else
                    cout<<"*";

            }
                right--;
                left++;
                cout<<"\n";
        }
    }
    return 0;
}
