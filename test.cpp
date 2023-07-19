#include <bits/stdc++.h>
#include "SudokuGenerator.cpp"
#include "SudokuSolver.cpp"

using namespace std;

int main()
{
    char ch = 'Y';
    while(ch != 'N')
    {
        cout << "To play sudoku enter 'Y'" << endl;
        cout << "To end this game enter 'N'" << endl;
        cin >> ch;
        if(ch=='N')
        continue;

        else if(ch == 'Y')
        {
            cout << "Enter the size of grid " << endl;
            int n;
            cin >> n;
            cout << "Enter the no of vacant spots" << endl;
            int k;
            cin >> k;

            sudoku s(n,k);
            s.fillValues();
            s.Print(s.mat);

            cout << endl << "Solution of above matrix" << endl << endl;
            solver(s.mat);
            s.Print(s.mat);
        }

        else
        {
            cout << "Wrong character entered!!" << endl;
        }
    }
}