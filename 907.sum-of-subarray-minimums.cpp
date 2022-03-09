/*
 * @lc app=leetcode id=907 lang=cpp
 *
 * [907] Sum of Subarray Minimums
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
// t:O(len(arr)), s:O(len(arr))
class Solution
{
    int mod = 1000000007;

public:
    int sumSubarrayMins(vector<int> &arr)
    {
        vector<long long> min_arr;
        vector<int> weights;
        long long accum_sum = 0;
        long long res = 0;
        int w = arr.size();
        for (int i = 0; i != w; ++i)
        {
            int current_weight = 1;
            while (!min_arr.empty() && min_arr.back() >= arr[i])
            {
                current_weight += weights.back();
                accum_sum -= min_arr.back() * weights.back();
                min_arr.pop_back();
                weights.pop_back();
            }
            min_arr.push_back(arr[i]);
            weights.push_back(current_weight);
            accum_sum += min_arr.back() * weights.back();
            res += accum_sum;
            res %= mod;
        }
        return res;
    }
};
// @lc code=end
