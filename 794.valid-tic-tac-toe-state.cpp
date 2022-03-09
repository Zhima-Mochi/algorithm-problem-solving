/*
 * @lc app=leetcode id=794 lang=cpp
 *
 * [794] Valid Tic-Tac-Toe State
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool validTicTacToe(vector<string> &board)
    {
        vector<int> row_records(3);
        vector<int> col_records(3);
        vector<int> cross_records(2);
        int count_O = 0, count_X = 0;
        int row_X_win = 0;
        int col_X_win = 0;
        int row_O_win = 0;
        int col_O_win = 0;
        for (int i = 0; i != 3; ++i)
        {
            for (int j = 0; j != 3; ++j)
            {
                if (board[i][j] != ' ')
                {
                    if (board[i][j] == 'O')
                    {
                        ++count_O;
                    }
                    else
                    {
                        ++count_X;
                    }

                    row_records[i] |= 1 << (board[i][j] == 'O' ? 3 : 0) + j;
                    col_records[j] |= 1 << (board[i][j] == 'O' ? 3 : 0) + i;
                    if (i == j)
                    {
                        cross_records[0] |= 1 << (board[i][j] == 'O' ? 3 : 0) + i;
                    }
                    if (j + i == 2)
                    {
                        cross_records[1] |= 1 << (board[i][j] == 'O' ? 3 : 0) + i;
                    }
                }
            }
        }
        if (count_O > count_X || count_X > count_O + 1)
        {
            return false;
        }
        for (auto &&n : cross_records)
        {
            if (n == 7)
            {
                if (count_X - count_O != 1)
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
            else if (n == 56)
            {
                if (count_X - count_O != 0)
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
        }
        for (auto &&n : row_records)
        {
            if (n == 7)
            {
                if (row_O_win > 0 || count_X - count_O != 1)
                {
                    return false;
                }
                else
                {
                    row_X_win += 1;
                }
            }
            else if (n == 56)
            {
                if (row_O_win > 0 || count_X - count_O != 0)
                {
                    return false;
                }
                else
                {
                    row_O_win += 1;
                }
            }
        }
        for (auto &&n : col_records)
        {
            if (n == 7)
            {
                if (col_O_win > 0 || count_X - count_O != 1)
                {
                    return false;
                }
                else
                {
                    col_X_win += 1;
                }
            }
            else if (n == 56)
            {
                if (col_O_win > 0 || count_X - count_O != 0)
                {
                    return false;
                }
                else
                {
                    col_O_win += 1;
                }
            }
        }
        return true;
    }
};
// @lc code=end
