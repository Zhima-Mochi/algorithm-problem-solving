/*
 * @lc app=leetcode id=2033 lang=cpp
 *
 * [2033] Minimum Operations to Make a Uni-Value Grid
 */
#include <vector>
#include <climits>
using namespace std;
// @lc code=start
// t:O(m*n), s:O(m*n);
class Solution
{
public:
    int minOperations(vector<vector<int>> &grid, int x)
    {
        int h = grid.size(), w = grid[0].size();
        vector<int> arr;
        for (auto &r : grid)
        {
            for (auto v : r)
            {
                if ((v - grid[0][0]) % x)
                {
                    return -1;
                }
                arr.push_back(v);
            }
        }
        int mid = h * w / 2;
        nth_element(arr.begin(), arr.begin() + mid, arr.end());
        int res = 0;
        for (auto &r : grid)
        {
            for (auto v : r)
            {
                res += abs(v - arr[mid]) / x;
            }
        }
        return res;
    }
};
// @lc code=end
