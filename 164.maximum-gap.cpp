/*
 * @lc app=leetcode id=164 lang=cpp
 *
 * [164] Maximum Gap
 */
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
// @lc code=start
// t:O(N), s:O(N)
class Solution
{
public:
    int maximumGap(vector<int> &nums)
    {
        int w = nums.size();
        if (w == 1)
        {
            return 0;
        }
        int max_val = *max_element(nums.begin(), nums.end());
        int min_val = *min_element(nums.begin(), nums.end());
        int cap = (max_val - min_val) / (w - 1) + 1;
        vector<vector<int>> buckets(max_val / cap + 1 - min_val / cap);
        for (auto n : nums)
        {
            buckets[n / cap - min_val / cap].push_back(n);
        }
        int res = 0;
        int prev_num = -1;
        for (auto &bucket : buckets)
        {
            if (bucket.empty())
            {
                continue;
            }
            sort(bucket.begin(), bucket.end());
            for (auto n : bucket)
            {
                if (prev_num != -1)
                {
                    res = max(res, n - prev_num);
                }
                prev_num = n;
            }
        }
        return res;
    }
};
// @lc code=end
