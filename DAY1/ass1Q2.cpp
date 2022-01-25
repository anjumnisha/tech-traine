/*ii) Write a program (without using inbuilt functions and not using Strings or array) to swap first and last digits of any number*/
#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter Number: ";
    cin>>n;

    int num=n;
    //take out the first and last digit from number
    int first, last;
    last=n%10;
    while(n>0)
    {
        first=n%10;
        n/=10;
    }
    n=num/10;
    while(n>10)
    {
        if(n%10==0)
            first=first*100;
        else
            first=first*10+n%10;
    n=n/10;
    }
    first=first*10+last;

    //reverse
    int rem, rev=0;
    n=first;
    while (n != 0)
    {
        rem = n % 10;
        rev = rev * 10 + rem;
        n /= 10;
    }

    cout<<"\nnumber after swaping digits: "<<rev<<"\n";
    return 0;
}
