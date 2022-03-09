/*
 * @lc app=leetcode id=861 lang=cpp
 *
 * [861] Score After Flipping Matrix
 */
#include <vector>
using namespace std;
// @lc code=start
// t:O(m*n), s:O(1)
class Solution
{
public:
    int matrixScore(vector<vector<int>> &grid)
    {
        int h = grid.size();
        int w = grid[0].size();
        int res1 = h << (w - 1); // not flip col 1
        // int res2 = h << (w - 1); // flip col 1
        for (int j = 1; j != w; ++j)
        {
            int one_num1 = 0;
            int one_num2 = 0;
            for (int i = 0; i != h; ++i)
            {
                if (grid[i][j])
                {
                    if (grid[i][0])
                    {
                        ++one_num1;
                    }
                    // else
                    // {
                    //     ++one_num2;
                    // }
                }
                else
                {
                    if (!grid[i][0])
                    {
                        ++one_num1;
                    }
                    // else
                    // {
                    //     ++one_num2;
                    // }
                }
            }
            res1 += max(one_num1, h - one_num1) << (w - 1 - j);
            // res2 += max(one_num2, h - one_num2) << (w - 1 - j);
        }
        return res1;
    }
};
// @lc code=end
