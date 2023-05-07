/*
 * @lc app=leetcode id=2432 lang=cpp
 *
 * [2432] The Employee That Worked on the Longest Task
 */
#include <vector>
using namespace std;
// @lc code=start
// t: O(n), s: O(1)
class Solution
{
public:
    int hardestWorker(int n, vector<vector<int>> &logs)
    {
        int w = logs.size();
        int m = logs[0][1];
        int res = logs[0][0];
        for (int i = 1; i != w; ++i)
        {
            if (logs[i][1] - logs[i - 1][1] > m)
            {
                m = logs[i][1] - logs[i - 1][1];
                res = logs[i][0];
            }
            else if (logs[i][1] - logs[i - 1][1] == m)
            {
                res = min(res, logs[i][0]);
            }
        }
        return res;
    }
};
// @lc code=end
