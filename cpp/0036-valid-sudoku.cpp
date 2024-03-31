class Solution
{
public:
    bool isValid(vector<vector<char>> &board, int col, int row, int val)
    {
        if (val == '.')
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
    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < board[0].size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
                if (!isValid(board, i, j, board[i][j]))
                    return false;
        }
        return true;
    }
};