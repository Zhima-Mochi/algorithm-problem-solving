/*
 * @lc app=leetcode id=2141 lang=cpp
 *
 * [2141] Maximum Running Time of N Computers
 */
#include <vector>
#include <queue>
#include <numeric>
using namespace std;
// @lc code=start
// t:O(m*log(sum)), s:O(1)
class Solution
{
public:
    long long maxRunTime(int n, vector<int> &batteries)
    {
        int w = batteries.size();
        if (n > w)
        {
            return 0;
        }
        long long left = 0, right = accumulate(batteries.begin(), batteries.end(), 0LL) / n;
        long long res = 0;
        while (left <= right)
        {
            long long mid = left + (right - left) / 2;
            long long total = 0;
            for (auto b : batteries)
            {
                total += min(static_cast<long long>(b), mid);
            }
            if (total >= n * mid)
            {
                res = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return res;
    }
};
// @lc code=end
