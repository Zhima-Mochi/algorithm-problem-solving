/*
 * @lc app=leetcode id=2304 lang=cpp
 *
 * [2304] Minimum Path Cost in a Grid
 */
#include <vector>
using namespace std;
// @lc code=start
// t:O(m*n*n), s:O(n)
class Solution
{
public:
    int minPathCost(vector<vector<int>> &grid, vector<vector<int>> &moveCost)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> last = grid[0];
        for (int i = 0; i != m - 1; ++i)
        {
            vector<int> temp(n, INT_MAX);
            for (int j = 0; j != n; ++j)
            {
                for (int k = 0; k != n; ++k)
                {
                    temp[k] = min(temp[k], last[j] + moveCost[grid[i][j]][k] + grid[i + 1][k]);
                }
            }
            last = temp;
        }
        return *min_element(last.begin(), last.end());
    }
};
// @lc code=end
