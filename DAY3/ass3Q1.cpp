/*i) Write a method Boolean isValidSudoku(int[][]Sudoku)
Returns true if the given Sudoku is correctly arranged otherwise false

Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Input : board =
 5 3 . . 7 . . . .
 6 . . 1 9 5 . . .
 . 9 8 . . . . 6 .
 8 . . . 6 . . . 3
 4 . . 8 . 3 . . 1
 7 . . . 2 . . . 6
 . 6 . . . . 2 8 .
 . . . 4 1 9 . . 5
 . . . . 8 . . 7 9
Output: true
Input: board =
 8 3 . . 7 . . . .
 6 . . 1 9 5 . . .
 . 9 8 . . . . 6 .
 8 . . . 6 . . . 3
 4 . . 8 . 3 . . 1
 7 . . . 2 . . . 6
 . 6 . . . . 2 8 .
 . . . 4 1 9 . . 5
 . . . . 8 . . 7 9
Output: false
*/
#include<iostream>
using namespace std;
bool isValidSudoku(string sudoku[][9])
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            int col=0 , row=0;
            while(col<9)
            {
                if(sudoku[i][j]==sudoku[i][col] && col!=j && sudoku[i][j]!=".")
                    return false;
                col++;
            }
            while(row<9)
            {
                if(sudoku[i][j]==sudoku[row][j] && row!=i && sudoku[i][j]!=".")
                    return false;
                row++;
            }
        }
    }
    return true;
}

int main()
{
    string sudoku[9][9];
    cout<<"Enter Sudoku[9][9] board\n ";
    for(int i=0;i<9;i++)
        {for(int j=0;j<9;j++)
            cin>>sudoku[i][j];
        cout<<"\n";
        }
        if(isValidSudoku(sudoku))
            cout<<"true\n";
        else
            cout<<"false\n";
    return 0;
}
