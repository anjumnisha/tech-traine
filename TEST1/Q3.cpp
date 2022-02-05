/*Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.
Example 1:
Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:
Input: num1 = "123", num2 = "456"
Output: "56088"
note: 1<= num1.length, num2.length <= 200
num1 and num2 consist of digits only.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.*/
#include<iostream>
#include<sstream>
#include<string>
using namespace std;
int main()
{
    string num1, num2;
    cout<<"Enter number string num1 and num2 :";
    cin>>num1>>num2;

    int no1, no2;
    stringstream n1(num1);
    n1>>no1;
    stringstream n2(num2);
    n2>>no2;

    int pro=no1*no2;

    ostringstream str1;
    str1<<pro;
    string product = str1.str();
    cout<<"product string : "<<product;
    return 0;
}
