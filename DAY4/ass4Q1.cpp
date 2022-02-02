/*1.  Make a StringUtils class which contains following methods
NOTE: You can use only String.charAt() in java, methods to code this problem.(Don't use any other inbuilt functions)

** c++ string.at(); can be used to extract characters by characters from a given string.
    Returns character at the specified position in the string. **

static int countChar(String str,char ch)
- Returns occurrence of the given character in the given String (str).

static String substring(String str,int start,int end)
- Returns a substring from the start index to end index with all validation checks.

static String[] split(String str,char ch)
- Returns an array of strings broken according to the occurrence of the given character with validation checks.

static Boolean hasPattern(String str,String pattern)
- Returns true if the give string (pattern) found in the main string (str) otherwise false.

static Boolean allWordsContainsChar(String str,char ch)
- Returns true if all words of the given string (str) contains the given character (ch)  otherwise false.

static String reverse(String str)
- Returns the reverse of the String (Without using extra String or array)

static String reverseVowels(String str)
- Reverse only all the vowels in the string and return it
( Example : Input: s = "liipcoce"
Output: "leopcici"

Input: s = "hello"
Output: "holle"
)
*/
#include<iostream>
#include<string>

using namespace std;

class StringUtils
{
public:
    int countChar(string str,char ch)
    {
        int count=0;
        int size=str.length();
        for(int i=0;i<size;i++)
        {
            if(str[i]==ch)
                count++;
        }
        return count;
    }
    string substring(string str,int start,int end)
    {
        string ans;
        ans.append(str,start,end);
        return ans;
    }
    string split(string str,char ch)
    {
        string ans = "";
        int n=str.length();
      for(int i=0; i<n; i++)
        {
         if(str[i] != ch)
            {
            ans += str[i];
            }
        else
            {
            cout<<ans<<" ";
              ans="";         }
        }
      cout <<ans;
    }
     bool hasPattern(string str,string pattern)
     {
        int s1=str.length();
        int s2=pattern.length();
        for(int i=0;i<=s1-s2;i++)
        {   int j;
            for(j=0; j<s2;j++)
                if(str[i+j]!=pattern[j])
                    break;
            if(j==s2)
                return true;
        }
        return false;
     }
     bool allWordsContainsChar(string str,char ch, int space)
     {
        int s=str.length();
        int j=0;
        int flag=0;
        while(space>0)
        {
            for(int i=j;i<str[i]!=' ';i++)
            {  if(str[i]!=ch)
                    flag=1;
                ++j;
            }
        }
        if(flag==0)
            return true;
        else
            return false;
     }
    string revers(string str)
    {
        int s=str.length();
        int j=s-1;
        for(int i=0;i<s/2;i++)
        {
            char temp;
            temp=str[i];
            str[i]=str[j];
            str[j]=temp;
            j--;
        }
        return str;
    }
    string reverseVowels(string str)
    {
        string vowel="";
        int s=str.length();
        for(int i=0;i<s;i++)
        {
            if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u')
                vowel+=str[i];
        }
        string rev=revers(vowel);
        int in=0;
        for(int i=0;i<s;i++)
        {
            if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u')
                {str[i]=rev[in];
                   in++; }
        }
        return str;
    }
};

int main()
{
    StringUtils S;
    string str;
    cout<<"Enter string : ";
    cin>>str;
    char ch;
    cout<<"\nEnter character to be count :";
    cin>>ch;
    int c=S.countChar(str,ch);
    cout<<"count : "<<c;

    int s , e;
    cout<<"\n\nEnter start and end index of a string :";
    cin>>s>>e;
    cout<<"substring : "<<S.substring(str,s,e);

    cout<<"\n\nEnter a character to split a string :";
    cin>>ch;
    string brake=S.split(str,ch);

    string patt;
    cout<<"\n\nEnter Pattern for hasPattern :";
    cin>>patt;
    if(S.hasPattern(str,patt))
        cout<<"Match";
    else cout<<"not match";

    string name;
    cout<<"\n\nEnter string and char for allWordsContainsChar :";
    cin.ignore();
	getline(cin,name);
    cin>>ch;
    int space=0;
    for(int i=0; i<name[i]; i++){
        if(str[i]==' ')
            space++;    }

    if(S.allWordsContainsChar(name, ch, space))
        cout<<"true";
    else
        cout<<"false";

    cout<<"\n\nReverse string :";
    cout<<S.revers(str);

    cout<<"\n\nVowels Reverse :";
    cout<<S.reverseVowels(str);

    cout<<"\n\n";
    return 0;
}
