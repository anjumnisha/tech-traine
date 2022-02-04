/*iii) Find the largest number less than N whose each digit is prime number*/
#include<iostream>
using namespace std;

bool isprime(int num)
{   int flag=0;
    if(num==1 || num==0)
        flag=1;
    for(int i=2;i<num/2;i++)
    {
        if(num%i==0)
            flag=1;
    }
    if(flag==0)
        return true;
    else
        return false;
}

int main()
{
    int num;
    cout<<"Enter: ";
    cin>>num;
    int i;
    for(i=num-1;i>0;i--)
    {
        int prime1=i;
        int prime2;
        int f=0;
        while(prime1>0)
        {
            prime2=isprime(prime1%10);
            if(prime2==false)
                f=1;
            prime1=prime1/10;
        }
        if(f==0)
            break;
    }
    cout<<"\nNumber :="<<i;
    return 0;
}
