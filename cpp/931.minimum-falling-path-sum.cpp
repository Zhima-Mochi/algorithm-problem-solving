/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 *
 */
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
// @lc code=start
// t:O(R*C), s:O(1)
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int w = matrix[0].size();
        int h = w;
        if (w == 1)
        {
            return matrix[0][0];
        }
        for (int i = 1; i != h; ++i)
        {
            matrix[i][0] += min(matrix[i - 1][0], matrix[i - 1][1]);
            matrix[i][w - 1] += min(matrix[i - 1][w - 1], matrix[i - 1][w - 2]);
            for (int j = 1; j < w - 1; ++j)
            {
                matrix[i][j] += min({matrix[i - 1][j - 1], matrix[i - 1][j], matrix[i - 1][j + 1]});
            }
        }
        return *min_element(matrix.back().begin(), matrix.back().end());
    }
};
// @lc code=end
