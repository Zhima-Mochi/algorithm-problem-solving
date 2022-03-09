/*
 * @lc app=leetcode id=945 lang=cpp
 *
 * [945] Minimum Increment to Make Array Unique
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
// t:O(max(len(nums), max_val - min_val), s:O(max(len(nums), max_val - min_val))
class Solution
{
public:
    int minIncrementForUnique(vector<int> &nums)
    {
        int min_val = *min_element(nums.begin(), nums.end());
        int max_val = *max_element(nums.begin(), nums.end());
        int w = nums.size();
        vector<int> rd(max(2 * (max_val - min_val), 2 * w));
        for (auto n : nums)
        {
            ++rd[n - min_val];
        }
        int res = 0;
        int hold = 0;
        int idx = 0;
        for (auto n : rd)
        {
            if (n > 1)
            {
                hold += n - 1;
                res -= idx * (n - 1);
            }
            else if (n == 0 && hold > 0)
            {
                --hold;
                res += idx;
            }
            ++idx;
        }
        return res;
    }
};
// @lc code=end

// t:O(nlog(n)), s:O(1)
// class Solution
// {
// public:
//     int minIncrementForUnique(vector<int> &nums)
//     {
//         sort(nums.begin(), nums.end());
//         int val = 0;
//         int res = 0;
//         for (auto n : nums)
//         {
//             if (n > val)
//             {
//                 val = n;
//             }
//             else if (n < val)
//             {
//                 res += val - n;
//             }
//             ++val;
//         }
//         return res;
//     }
// };