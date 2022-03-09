/*
 * @lc app=leetcode id=885 lang=cpp
 *
 * [885] Spiral Matrix III
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
    {
        int total_cnt = rows * cols;
        vector<vector<int>> res = {{rStart, cStart}};
        res.reserve(total_cnt);
        int direction = 0;
        int l = 0;
        while (res.size() < total_cnt)
        {
            if (direction % 2 == 0)
            {
                ++l;
            }
            if (direction % 2 && cStart >= 0 && cStart < cols)
            {
                for (int i = 0; i != l; ++i)
                {
                    rStart = direction == 1 ? rStart + 1 : rStart - 1;
                    if (rStart >= 0 && rStart < rows)
                    {
                        res.push_back({rStart, cStart});
                    }
                }
            }
            else if (direction % 2 == 0 && rStart >= 0 && rStart < rows)
            {
                for (int i = 0; i != l; ++i)
                {
                    cStart = direction == 0 ? cStart + 1 : cStart - 1;
                    if (cStart >= 0 && cStart < cols)
                    {
                        res.push_back({rStart, cStart});
                    }
                }
            }
            else
            {
                if (direction == 0)
                {
                    cStart += l;
                }
                else if (direction == 1)
                {
                    rStart += l;
                }
                else if (direction == 2)
                {
                    cStart -= l;
                }
                else
                {
                    rStart -= l;
                }
            }
            direction = ++direction % 4;
        }
        return res;
    }
};
// @lc code=end
