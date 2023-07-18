/*
 * @lc app=leetcode id=1937 lang=cpp
 *
 * [1937] Maximum Number of Points with Cost
 */
#include <vector>
#include <climits>
using namespace std;
// @lc code=start
// t:O(m*n), s:O(m*n)
class Solution
{
public:
    long long maxPoints(vector<vector<int>> &points)
    {
        int h = points.size();
        int w = points[0].size();
        vector<long long> memo(w), temp(w);
        for (int i = 0; i != h; ++i)
        {
            long long val = LLONG_MIN;
            for (int j = 0; j != w; ++j)
            {
                val = max(val, memo[j] + j);
                temp[j] = max(temp[j], val + points[i][j] - j);
            }
            val = LLONG_MIN;
            for (int j = w - 1; j != -1; --j)
            {
                val = max(val, memo[j] - j);
                temp[j] = max(temp[j], val + points[i][j] + j);
            }
            swap(memo, temp);
        }
        return *max_element(memo.begin(), memo.end());
    }
};
// @lc code=end
