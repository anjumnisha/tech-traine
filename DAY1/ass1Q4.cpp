/*iv) Write a function Boolean isValidURL(String url).*/
#include<iostream>
#include <regex>
using namespace std;

bool isValidURL(string u)
{
    const regex pattern("((http|https)://)(www.)?[a-zA-Z0-9@:%._\\+~#?&//=]{2,256}\\.[a-z]{2,6}\\b([-a-zA-Z0-9@:%._\\+~#?&//=]*)");
    if(regex_match(u,pattern))
        return true;
    else
        return false;
}

int main()
{
    string url;
    cout<<"Enter :";
    cin>>url;
    if(isValidURL(url))
        cout<<"\nyes valid\n";
    else
        cout<<"\nnot valid\n";

    return 0;
}
