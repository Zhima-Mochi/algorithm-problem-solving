/*
 * @lc app=leetcode id=999 lang=cpp
 *
 * [999] Available Captures for Rook
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int numRookCaptures(vector<vector<char>> &board)
    {
        int i = 0, j = 0, height = board.size(), width = board[0].size();
        ;
        for (auto &row_elem : board)
        {
            j = 0;
            for (auto &elem : row_elem)
            {
                if (elem == 'R')
                {
                    break;
                }
                ++j;
            }
            if (j != width)
            {
                break;
            }
            ++i;
        }
        int res = 0;
        for (int right = j + 1; right != width; ++right)
        {
            if (board[i][right] != '.')
            {
                if (board[i][right] == 'p')
                {
                    ++res;
                }
                break;
            }
        }
        for (int left = j - 1; left != -1; --left)
        {
            if (board[i][left] != '.')
            {
                if (board[i][left] == 'p')
                {
                    ++res;
                }
                break;
            }
        }

        for (int up = i + 1; up != height; ++up)
        {
            if (board[up][j] != '.')
            {
                if (board[up][j] == 'p')
                {
                    ++res;
                }
                break;
            }
        }

        for (int down = i - 1; down != -1; --down)
        {
            if (board[down][j] != '.')
            {
                if (board[down][j] == 'p')
                {
                    ++res;
                }
                break;
            }
        }
        return res;
    }
};
// @lc code=end
