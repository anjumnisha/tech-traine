/*v) Write a program to find the smallest number divisible by all the numbers between 1 to 9*/
#include<iostream>
using namespace std;

bool diviblebyall(int pro, int s, int e)
{
    for(int i=s;i<=e;i++)
    {
        if(pro%i!=0)
            return false;
    }
    return true;
}

int main()
{
    int start=1, end=9;
    int product=1;
    for(int i=start;i<=end;i++)
    {
        product=product*i;
    }
    int divisiblenum;
    for(int i=product;i>1;i--)
    {
        int num=diviblebyall(i,start,end);
        if(num==true)
            {
                divisiblenum=i;
            }
    }
    cout<<"\ndivisible number is :"<<divisiblenum;
    return 0;
}
