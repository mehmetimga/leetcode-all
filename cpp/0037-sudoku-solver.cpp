#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<int>> &arr)
{
    for (int i = 0; i < arr[0].size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

class Solution
{
public:
    bool isValid(vector<vector<int>> &board, int col, int row, int val)
    {
        if (val == 0)
        {
            return true;
        }

        for (int i = 0; i < board[col].size(); i++)
        {
            if (board[col][i] == val && i != row)
                return false;
        }

        for (int i = 0; i < board[col].size(); i++)
        {
            if (board[i][row] == val && i != col)
                return false;
        }
        int rowstart = row - row % 3;
        int colstart = col - col % 3;

        for (int i = colstart; i < colstart + 3; i++)
        {
            for (int j = rowstart; j < rowstart + 3; j++)
            {
                if (board[i][j] == val & i != col && j != row)
                {
                    return false;
                }
            }
        }

        return true;
    }
    bool solve(vector<vector<int>> &board)
    {
        for (int i = 0; i < board[0].size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
                if (board[i][j] == 0)
                {
                    for (int k = 1; k <= 9; k++)
                    {

                        if (isValid(board, i, j, k))
                        {
                            board[i][j] = k;
                            if (solve(board))
                                return true;
                            else
                                board[i][j] = 0;
                        }
                    }
                    return false;
                }
        }
        return true;
    }
    void solveSudoku(vector<vector<int>> &board)
    {
        solve(board);
    }
};

int main()
{
    vector<vector<int>> grid = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                                {5, 2, 0, 0, 0, 0, 0, 0, 0},
                                {0, 8, 7, 0, 0, 0, 0, 3, 1},
                                {0, 0, 3, 0, 1, 0, 0, 8, 0},
                                {9, 0, 0, 8, 6, 3, 0, 0, 5},
                                {0, 5, 0, 0, 9, 0, 6, 0, 0},
                                {1, 3, 0, 0, 0, 0, 2, 5, 0},
                                {0, 0, 0, 0, 0, 0, 0, 7, 4},
                                {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    Solution().solveSudoku(grid);
    print(grid);

    cout << "Solution:" << endl;
    cout << "3 1 6 5 7 8 4 9 2" << endl;
    cout << "5 2 9 1 3 4 7 6 8" << endl;
    cout << "4 8 7 6 2 9 5 3 1" << endl;
    cout << "2 6 3 4 1 5 9 8 7" << endl;
    cout << "9 7 4 8 6 3 1 2 5" << endl;
    cout << "8 5 1 7 9 2 6 4 3" << endl;
    cout << "1 3 8 9 4 7 2 5 6" << endl;
    cout << "6 9 2 3 5 1 8 7 4" << endl;
    cout << "7 4 5 2 8 6 3 1 9" << endl;

    return 0;
}
