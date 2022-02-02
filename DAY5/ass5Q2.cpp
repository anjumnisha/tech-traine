/*2. Write a program to print all the possible combinations according to the input values.
Example :
Given Values
'1' : ['Z', 'Y', 'A'],
'2' : ['B', 'O'],
'12' : ['L']
'3' : ['U', 'P']

Input : 123
Output : [ZBU, ZBP, ZOU, ZOP, YBU, YBP, YOU, YOP, ABU, ABP, AOU, AOP, LU, LP]*/
// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

void findCombinations(vector<char> keypad[],
					int input[], string res, int index, int n)
{

	if (index == n) {
		cout<<res<<" ";
		return;
	}

	int digit = input[index];

	int len = keypad[digit].size();

	for (int i = 0; i < len; i++) {
		findCombinations(keypad, input, res + keypad[digit][i], index + 1, n);
	}
}

int main()
{
	vector<char> keypad[] =
	{   {}, {'Z','Y', 'A'}, {'B','O'},{'U','P'}    };

	int input[] = { 1 , 2, 3 };

	int n = sizeof(input)/sizeof(input[0]);

	findCombinations(keypad, input, string(""), 0, n );

    cout<<"\n";
	return 0;
}

