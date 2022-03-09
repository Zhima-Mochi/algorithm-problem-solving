/*
 * @lc app=leetcode id=799 lang=cpp
 *
 * [799] Champagne Tower
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    double champagneTower(int poured, int query_row, int query_glass)
    {
        double tower[101][101] = {};
        tower[0][0] = poured;
        for (int i = 0; i != query_row + 1; ++i)
        {
            for (int j = 0; j <= i; ++j)
            {
                if (tower[i][j] >= 1)
                {
                    tower[i + 1][j] += (tower[i][j] - 1) / 2;
                    tower[i + 1][j + 1] += (tower[i][j] - 1) / 2;
                    tower[i][j] = 1;
                }
            }
        }
        return tower[query_row][query_glass];
    };
};
// @lc code=end
