#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool solve(vector<vector<char>> &board, vector<unordered_set<char>> &rows, vector<unordered_set<char>> &cols, vector<vector<unordered_set<char>>> &squares)
    {

        for (int i = 0; i < board[0].size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
                if (board[i][j] == '.')
                {
                    for (char k = '1'; k <= '9'; k++)
                    {

                        if (cols[i].find(k) == cols[i].end() && rows[j].find(k) == rows[k].end() && squares[i / 3][j / 3].find(k) == squares[i / 3][j / 3].end())
                        {
                            board[i][j] = k;
                            cols[i].insert(k);
                            rows[j].insert(k);
                            squares[i / 3][j / 3].insert(k);
                            if (solve(board, rows, cols, squares))
                                return true;
                            else
                                board[i][j] = '.';

                            cols[i].erase(k);
                            rows[j].erase(k);
                            squares[i / 3][j / 3].erase(k);
                        }
                    }
                    return false;
                }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        vector<vector<unordered_set<char>>> squares(3, vector<unordered_set<char>>(3));
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] != '.')
                {
                    cols[i].insert(board[i][j]);
                    rows[j].insert(board[i][j]);
                    squares[i / 3][j / 3].insert(board[i][j]);
                }
            }
        }
        solve(board, rows, cols, squares);
    }
};