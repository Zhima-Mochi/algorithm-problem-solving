/*
 * @lc app=leetcode id=1751 lang=cpp
 *
 * [1751] Maximum Number of Events That Can Be Attended II
 */
#include <vector>
#include <deque>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxValue(vector<vector<int>> &events, int k)
    {
        sort(events.begin(), events.end(), [&](vector<int> &a, vector<int> &b)
             { return a[1] < b[1]; });
        int w = events.size();
        vector<vector<int>> memo(w + 1, vector<int>(k + 1, 0));
        for (int i = 1; i != w + 1; ++i)
        {
            int cur = i - 1;
            while (cur > 0 && events[cur - 1][1] >= events[i - 1][0])
            {
                cur--;
            }
            for (int j = 1; j <= k; ++j)
            {
                memo[i][j] = max(memo[i][j], memo[i - 1][j]);
                memo[i][j] = max(memo[i][j], memo[cur][j - 1] + events[i - 1][2]);
            }
        }
        return *max_element(memo[w].begin(), memo[w].end());
    }
};
// @lc code=end
