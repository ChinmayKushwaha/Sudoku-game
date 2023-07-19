#include <bits/stdc++.h>

using namespace std;

class sudoku
{
    public:
    vector<vector<int>> mat;

    int sizeOfMatrix;
    
    // No of missing digits.
    int k;

    //Constructor
    sudoku(int sizeOfMatrix,int k)
    {
        this->sizeOfMatrix = sizeOfMatrix;
        this->k = k;
        for(int i = 0;i<sizeOfMatrix;i++)
        {
            vector<int> temp;
            for(int j = 0;j<sizeOfMatrix;j++)
            {
                temp.push_back(0);
            }
            mat.push_back(temp);
        }
    }

    int randomGenerator(int num)
    {
        return rand() % num + 1;
    }

    bool unUsedInBox(int rowStart, int colStart, int num)
    {
        for (int i = 0; i < sqrt(sizeOfMatrix); i++)
        {
            for (int j = 0; j < sqrt(sizeOfMatrix); j++) 
            {
                if (mat[rowStart + i][colStart + j] == num) 
                {
                    return false;
                }
            }
        }
        return true;
    }

    void fillDiagonal()
    {
        for (int i = 0; i < sizeOfMatrix; i = i + sqrt(sizeOfMatrix))
        {
            fillBox(i, i);
        }
    }

    void fillBox(int row, int col)
    {
        int num;
        for (int i = 0; i < sqrt(sizeOfMatrix); i++) 
        {
            for (int j = 0; j < sqrt(sizeOfMatrix); j++) 
            {
                do 
                {
                    num = randomGenerator(sizeOfMatrix);
                } 
                while (!unUsedInBox(row, col, num));
                mat[row + i][col + j] = num;
            }
        }
    }

    bool unUsedInRow(int i, int num)
    {
        for (int j = 0; j < sizeOfMatrix; j++) 
        {
            if (mat[i][j] == num) 
            {
                return false;
            }
        }
        return true;
    }

    bool unUsedInCol(int j, int num)
    {
        for (int i = 0; i < sizeOfMatrix; i++) {
            if (mat[i][j] == num) 
            {
                return false;
            }
        }
        return true;
    }

    bool CheckIfSafe(int i, int j, int num)
    {
        return (unUsedInRow(i, num) && unUsedInCol(j, num) && unUsedInBox(i - i % (int)sqrt(sizeOfMatrix), j - j % (int)sqrt(sizeOfMatrix), num));
    }

    bool fillRemaining(int i, int j)
    {
        int N = sizeOfMatrix;
        int SRN = sqrt(sizeOfMatrix);
        if (j >= N && i < N - 1) {
            i = i + 1;
            j = 0;
        }
        if (i >= N && j >= N) {
            return true;
        }

        if (i < SRN) {
            if (j < SRN) {
                j = SRN;
            }
        }
        else if (i < N - SRN) {
            if (j == (int)(i / SRN) * SRN) {
                j = j + SRN;
            }
        }
        else {
            if (j == N - SRN) {
                i = i + 1;
                j = 0;
                if (i >= N) {
                    return true;
                }
            }
        }
        for (int num = 1; num <= N; num++) {
            if (CheckIfSafe(i, j, num)) {
                mat[i][j] = num;
                if (fillRemaining(i, j + 1)) 
                {
                    return true;
                }
                mat[i][j] = 0;
            }
        }
        return false;
    }

    void removeKDigits()
    {
        int count = k;
        while (count != 0) {
            int cellId = randomGenerator(sizeOfMatrix * sizeOfMatrix) - 1;
            // extract coordinates i and j
            int i = (cellId / sizeOfMatrix);
            int j = cellId % 9;
            if (j != 0) {
                j = j - 1;
            }

            if (mat[i][j] != 0) {
                count--;
                mat[i][j] = 0;
            }
        }
    }

    void fillValues()
    {
       
        // Fill the diagonal of SRN x SRN matrices
        fillDiagonal();
       
        // Fill remaining blocks
        fillRemaining(0, sqrt(sizeOfMatrix));
       
        // Remove Randomly K digits to make game
        removeKDigits();
    }

    void Print(vector<vector<int>> &board)
    {
        int N = board[0].size();

        for(int i = 0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                cout << board[i][j] << " ";
                if(j==2 || j==5)
                {
                    cout << "| ";
                }
            }
            cout << endl;
            if(i == 2 || i == 5)
            {
                cout << "- - - - - - - - - - -" << endl;
            }
        }
    }
};