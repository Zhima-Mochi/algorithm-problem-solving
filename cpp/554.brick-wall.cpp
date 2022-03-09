/*
 * @lc app=leetcode id=554 lang=cpp
 *
 * [554] Brick Wall
 */
#include <vector>
#include <unordered_map>
#include <numeric>
using namespace std;
// @lc code=start
class Solution
{
public:
    int leastBricks(vector<vector<int>> &wall)
    {
        unordered_map<int, int> border_count;
        for (auto &row_elem : wall)
        {
            int sum_val = 0;
            for (auto &elem : row_elem)
            {
                sum_val += elem;
                ++border_count[sum_val];
            }
        }
        int height = wall.size();
        int width = accumulate(wall[0].begin(), wall[0].end(), 0);
        border_count.erase(width);
        int res = height;
        for (auto &pr : border_count)
        {
            res = min(res, height - pr.second);
        }
        return res;
    }
};
// @lc code=end
