/*
 * @lc app=leetcode id=289 lang=cpp
 *
 * [289] Game of Life
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        int height = board.size(), width = board[0].size();
        for (auto &row_elem : board)
        {
            if (width >= 2)
            {
                row_elem[0] += (row_elem[1] + row_elem[0]) << 2;
                row_elem[width - 1] += (row_elem[width - 2] & 1) + row_elem[width - 1] << 2;
            }
            for (int i = 1; i < width - 1; ++i)
            {
                row_elem[i] += (row_elem[i]) + (row_elem[i - 1] & 1) + (row_elem[i + 1] & 1) << 2;
            }
        }

        for (int i = 0; i != height; ++i)
        {
            for (int j = 0; j != width; ++j)
            {
                int sum_val = board[i][j];
                if (i > 0)
                {
                    sum_val += board[i - 1][j];
                }
                if (i < height - 1)
                {
                    sum_val += board[i + 1][j];
                }
                sum_val >>= 2;
                sum_val -= board[i][j] & 1;
                if (board[i][j] & 1)
                {
                    if (sum_val < 2 || sum_val > 3)
                    {
                        board[i][j] -= 1;
                    }
                }
                else
                {
                    if (sum_val == 3)
                    {
                        board[i][j] += 1;
                    }
                }
            }
        }
        for (int i = 0; i != height; ++i)
        {
            for (int j = 0; j != width; ++j)
            {
                board[i][j] &= 1;
            }
        }
    }
};
// @lc code=end
