/*Day 1 Assignment
i) Write down a method boolean isNameValid(String  name).
A name is valid if following conditions are satisfied:
• It does not contain any vowel more than once.
• If the name contains two ‘S’, then there is not any ‘T’ in between them (both in capital cases).*/
#include<bits/stdc++.h>
using namespace std;

bool isNameValid(string validname)
{
    int len=validname.length();
    int coun=0;
    string name=validname;
    transform(name.begin(), name.end(), name.begin(), ::tolower);
    for(int i=0;i<len;i++)
    {
        if(name[i]=='a' || name[i]=='e' || name[i]=='i' || name[i]=='o' || name[i]=='u')
            coun++;
    }

    string L={'S','T','S'};
    int in=0;
    for(int i=0;i<len;i++)
    {
        if(validname[i]==L[in])
            in++;
    }
    if(in>2)
        return false;
    if(coun>1)
        return false;
    else
        return true;

}

int main()
{
    string name;
    cout<<"Enter name: ";
    cin>>name;
    if(isNameValid(name)==true)
        cout<<"\nValid Name";
    else
        cout<<"\nInvalid Name";
    return 0;
}
