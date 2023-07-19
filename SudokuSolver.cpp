#include <bits/stdc++.h>

using namespace std;
bool isSafe(int row, int col, int num,vector<vector<int>> &board)
{
    int N = board[0].size();
    for(int i=0; i<N; i++)
    {
        if(board[row][i] == num)
        return false;
    
    
        if(board[i][col] == num)
        return false;
    
        if(board[3*(row/3) + i/3][3*(col/3) + i%3] == num)
        return false;
    }
    return true;
}

bool solver(vector<vector<int>> &board)
{
    int N = board[0].size();

    for(int i = 0; i<N ; i++)
    {
        for(int j = 0; j<N ; j++)
        {
            if(board[i][j] == 0)
            {
                for(int num = 1; num<=9;num++)
                {
                    if(isSafe(i,j,num,board))
                    {
                        board[i][j] = num;
                        bool possible = solver(board);

                        if(possible)
                        {
                            return true;
                        }
                        else
                        {
                            board[i][j] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}