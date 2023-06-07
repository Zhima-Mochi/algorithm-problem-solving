/*
 * @lc app=leetcode id=2352 lang=cpp
 *
 * [2352] Equal Row and Column Pairs
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
// t:O(n^2) s:O(n^2)
class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        unordered_map<string, int> rm, cm;
        int l = grid[0].size();
        for (int i = 0; i != l; ++i)
        {
            string r_str, c_str;
            for (int j = 0; j != l; ++j)
            {
                r_str += ',' + to_string(grid[i][j]);
                c_str += ',' + to_string(grid[j][i]);
            }
            ++rm[r_str];
            ++cm[c_str];
        }
        int res = 0;
        for (auto &[k, v] : rm)
        {
            res += v * cm[k];
        }
        return res;
    }
};
// @lc code=end
