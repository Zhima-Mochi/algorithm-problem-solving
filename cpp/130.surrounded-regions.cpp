/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        int height = board.size(), width = board[0].size();
        for (auto i = 0; i != height; ++i)
        {
            go(board, i, 0);
            go(board, i, width - 1);
        }
        for (auto j = 0; j != width; ++j)
        {
            go(board, 0, j);
            go(board, height - 1, j);
        }
        for (auto &r : board)
        {
            for (auto &val : r)
            {
                if (val == 'X')
                {
                    continue;
                }
                else if (val == 'A')
                {
                    val = 'O';
                }
                else
                {
                    val = 'X';
                }
            }
        }
    }
    void go(vector<vector<char>> &board, int row, int col)
    {
        if (row < 0 || col < 0 || row > board.size() - 1 || col > board[0].size() - 1)
        {
            return;
        }
        if (board[row][col] == 'X' || board[row][col] == 'A')
        {
            return;
        }
        else
        {
            board[row][col] = 'A';
            go(board, row + 1, col), go(board, row - 1, col), go(board, row, col + 1), go(board, row, col - 1);
        }
    }
};
// @lc code=end
//[["O","O","O","O","X","X"],["O","O","O","O","O","O"],["O","X","O","X","O","O"],["O","X","O","O","X","O"],["O","X","O","X","O","O"],["O","X","O","O","O","O"]]