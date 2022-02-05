/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true*/
#include<bits/stdc++.h>
using namespace std;

bool isvalid(char str[], int n)
{
    if (n == 0)
        return true;
    char close;
    if(str[0]=='(')
        close=')';
    else if(str[0]=='{')
        close='}';
    else if(str[0]=='[')
        close=']';

    int i, count = 0;           //count to handle case like (())
    for(i=1;i<n;i++)
    {
        if(str[i]==str[0])
            count++;
        if(str[i]==close)
        {
            if (count==0)
                break;
            count--;
        }
    }
    //not found close bracket
    if(i==n)
        return false;
    //if close bracket are next to each other
    if(i==1)
        return isvalid(str+2, n-2);
    //there are elements in between open and close bracket
    return isvalid(str+1, i-1) && isvalid(str+i+1, n-i-1);
}

int main()
{
    string str;
    cout<<"Enter string of characters :";
    cin>>str;

    int n=str.length();
    //size should be even in balanced string of paranthesis
    if(n%2!=0)
    {
        cout<<"false";
        return 0;
    }
    //string of character should start with open brackets
    if(str[0]==')' || str[0]=='}' || str[0]==']')
    {
        cout<<"false";
        return 0;
    }

    char b[n];
    for(int i=0;i<n;i++)
    {   b[i]=str[i];  }

    if(isvalid(b, n))
        cout<<"true\n";
    else
        cout<<"false\n";

    return 0;
}
