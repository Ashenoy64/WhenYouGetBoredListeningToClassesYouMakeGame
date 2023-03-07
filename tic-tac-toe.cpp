#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<bits/stdc++.h>


using namespace std;


class Game{
    private:
    int arr[3][3];

    public:
    Game()
    {
        for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        arr[i][j]=0;
        bool gameOver=false;
        bool gameWon=false;
        int who=-1;
        printBoard();
        while(!gameOver)
        {
            
            player1Input();
            if(checkWin(1))
            {
                gameOver=true;
                gameWon=true;
                who=1;
                continue;
            }
            player2Input();
            if(checkWin(2))
            {
                gameOver=true;
                gameWon=true;
                who=2;
                continue;
            }
            if(filled())
            gameOver=true;
        }
        if(gameWon)
        cout<<"Player "<<who<<" Won"<<" Congragulations!"<<endl;
        else
        cout<<"Game Tied"<<endl;

    }

    bool valid(int row ,int col)
    {
        return arr[row][col]==0;
    }

    void printBoard()
    {
        for(int i=0;i<3;i++){
            cout<<"|";
        for(int j=0;j<3;j++)
        {
            if(arr[i][j]==0)
            {
                cout<<"___|";
            }
            else if(arr[i][j]=='O')
            {
                cout<<" O |";
            }
            else{
                cout<<" X |";
            }
        }
        cout<<endl<<endl;
        }
    }
    bool filled()
    {
        for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        {
            if(arr[i][j]==0)
            return false;
        }
        return true;
    }
    void player1Input()
    {
        int row,col;
        player1Back:cout<<"\n Player 1 Moves"<<endl;
        cout<<"\n Enter Your Move\n"<<"ROW:";
        cin>>row;
        cout<<"\nCOLUMN:";
        cin>>col;

        if((row<=3 && row>=1 ) && (col>=1 && col<=3) && valid(row-1,col-1))
        {
            arr[row-1][col-1]='O';
            printBoard();
        }
        else{
            cout<<"Invalid Input\n";
            goto player1Back;
        }
    }

    bool checkWin(int player)
    {
        int which;
        if(player==1)
        which='O';
        else
        which='X';
        return (
            (arr[0][0]==arr[1][1] and arr[1][1]==arr[2][2] and arr[1][1]==which)||
            (arr[1][1]==arr[0][3] and arr[1][1]==arr[2][0] and arr[1][1]==which)||

            (arr[0][0]==arr[0][1] and arr[0][1]==arr[0][2] and arr[0][1]==which)||
            (arr[1][0]==arr[1][1] and arr[1][1]==arr[0][2] and arr[1][1]==which)||
            (arr[2][0]==arr[2][1] and arr[2][1]==arr[2][2] and arr[2][1]==which)||

            (arr[0][0]==arr[1][0] and arr[1][0]==arr[2][0] and arr[0][0]==which)||
            (arr[0][1]==arr[1][1] and arr[1][1]==arr[2][1] and arr[2][1]==which)||
            (arr[0][2]==arr[1][2] and arr[1][2]==arr[2][2] and arr[1][2]==which));
    }

    void player2Input()
    {
        int row,col;
        player2Back:cout<<"\n Player 2 Moves"<<endl;
        cout<<"\n Enter Your Move\n"<<"ROW:";
        cin>>row;
        cout<<"\nCOLUMN:";
        cin>>col;

        if((row<=3 && row>=1 ) && (col>=1 && col<=3) && valid(row-1,col-1))
        {
            arr[row-1][col-1]='X';
            printBoard();
        }
        else{
            cout<<"Invalid Input\n";
            goto player2Back;
        }
    }
};

int main()
{
    Game obj;
    return 0;
}