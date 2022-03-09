/*
 * @lc app=leetcode id=1601 lang=cpp
 *
 * [1601] Maximum Number of Achievable Transfer Requests
 */
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <functional>
using namespace std;
// @lc code=start
// t:O(2^len(requests)), s:O(n+len(requests))
class Solution
{
public:
    int maximumRequests(int n, vector<vector<int>> &requests)
    {
        int w = requests.size();
        vector<unordered_map<string, int>> records(w + 1, unordered_map<string, int>());
        string status(n, 0);
        string balance(n, 0);
        function<int(int, string &)> dp = [&](int m, string &status)
        {
            if (m == 0)
            {
                if (status == balance)
                {
                    return 0;
                }
                else
                {
                    return -30;
                }
            }
            if (records[m].count(status))
            {
                return records[m][status];
            }
            int res = dp(m - 1, status);
            --status[requests[m - 1][0]];
            ++status[requests[m - 1][1]];
            res = max(res, 1 + dp(m - 1, status));
            ++status[requests[m - 1][0]];
            --status[requests[m - 1][1]];
            records[m][status] = res;
            return res;
        };
        return max(0, dp(w, status));
    }
};
// @lc code=end
