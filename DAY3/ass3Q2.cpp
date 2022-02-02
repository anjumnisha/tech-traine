/*ii) Write a method Boolean isKingSafe(int[][]chessBoard)
Returns true if king in the given chess board is safe from the given enemies otherwise false;
NOTE: Enemies are- Horse, Camel, Queen, Elephant only
Do not consider the color case of the chess board for traversal of camel and all.*/

#include<iostream>
using namespace std;

bool isKingSafe(char chessBoard[][8])
{
    int cx, cy;
    int kx , ky;
    cout<<"\nEnter king's position(x,y) :";
    cin>>kx>>ky;
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            if(i==kx && j==ky)
                chessBoard[i][j]='k';
    //for loops for conditions
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
    {
        //conditions for horse
        if(chessBoard[i][j]=='h')
        {
            if(chessBoard[i-2][j-1]=='k')
                return false;
            else if(chessBoard[i-2][j+1]=='k')
                return false;
            else if(chessBoard[i-1][j+2]=='k')
                return false;
            else if(chessBoard[i+1][j+2]=='k')
                return false;
            else if(chessBoard[i+2][j+1]=='k')
                return false;
            else if(chessBoard[i+2][j-1]=='k')
                return false;
            else if(chessBoard[i+1][j-2]=='k')
                return false;
            else if(chessBoard[i-1][j-2]=='k')
                return false;
        }
        //diagonal conditions for camel and queen
        if(chessBoard[i][j]=='c' || chessBoard[i][j]=='q')
        {
            cx=i;
            cy=j;
            int row=i, col=j;
            while(row<8 && col<8)       //both increase
            {
                row++;
                col++;
                if(chessBoard[row][col]=='k')
                    return false;
            }
            row=i;
            col=j;
            while(row>=0 && col>=0)     //both decrease
            {
                row--;
                col--;
                if(chessBoard[row][col]=='k')
                    return false;
            }
            row=i;
            col=j;
            while(row<8 && col>=0)      //i increase and j decrease
            {
                row++;
                col--;
                if(chessBoard[row][col]=='k')
                    return false;
            }
            row=i;
            col=j;
            while(row>=0 && col<8)      //i decrease and j increase
            {
                row--;
                col++;
                if(chessBoard[row][col]=='k')
                    return false;
            }
        }
        //vertical and horizontal condition for elephant and queen
        if(chessBoard[i][j]=='q' || chessBoard[i][j]=='e')
        {
            if(i==kx || j==ky)
            {
                if(i==cx || j==ky)
                 {
                     if((cx<kx && cx>i)||(cx>kx && cx<i))
                        return true;
                     if((cy<ky && cy>j)||(cy>ky && cy<j))
                        return true;       }
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int hx , hy , cx , cy , qx , qy , ex , ey;
    cout<<"Enter horse position (x,y): ";
    cin>>hx>>hy;
    cout<<"Enter camel position (x,y): ";
    cin>>cx>>cy;
    cout<<"Enter queen position (x,y): ";
    cin>>qx>>qy;
    cout<<"Enter elephant position (x,y): ";
    cin>>ex>>ey;

    char arr[8][8];
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
    {
        if(i==hx && j==hy)
            arr[i][j]='h';
        else if(i==cx && j==cy)
            arr[i][j]='c';
        else if(i==qx && j==qy)
            arr[i][j]='q';
        else if(i==ex && j==ey)
            arr[i][j]='e';
    }
    if(isKingSafe(arr))
    {
        cout<<"true\n";
    }
    else
        cout<<"false\n";
    return 0;
}
