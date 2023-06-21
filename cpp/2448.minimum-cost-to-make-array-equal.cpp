/*
 * @lc app=leetcode id=2448 lang=cpp
 *
 * [2448] Minimum Cost to Make Array Equal
 */
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <functional>
using namespace std;
// @lc code=start
class Solution
{
public:
    long long minCost(vector<int> &nums, vector<int> &cost)
    {
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());
        int w = nums.size();
        unordered_map<int, long long> records;
        function<long long(int)> caculate_cost = [&](int val) -> long long
        {
            if (records.count(val))
            {
                return records[val];
            }
            long long res = 0;
            for (int i = 0; i != w; ++i)
            {
                res += static_cast<long long>(abs(nums[i] - val)) * cost[i];
            }
            records[val] = res;
            return res;
        };
        while (left < right)
        {
            auto mid = left + (right - left) / 2;
            if (caculate_cost(mid + 1) >= caculate_cost(mid))
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return caculate_cost(left);
    }
};
// @lc code=end
