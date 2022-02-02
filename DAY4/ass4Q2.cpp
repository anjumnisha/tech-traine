/* Given a string s, find the length of the longest substring without repeating characters.
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.*/
#include<iostream>
using namespace std;

int main()
{
    string str;
    cout<<"Enter :";
    cin>>str;
    int coun=0;
    int total=0 , out=1;
    int s=str.length();
    for(int i=0;i<s;i++)
    {   int j=i-1;
        coun++;
        while(j>=0)
        {
            if(str[i]==str[j])
               {
                   total=coun;
                   coun=0;
               }
               j--;
        }
        if(out<total)
            out=total;
    }
    cout<<out-1;
    return 0;
}
