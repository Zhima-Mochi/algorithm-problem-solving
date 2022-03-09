/*
 * @lc app=leetcode id=462 lang=cpp
 *
 * [462] Minimum Moves to Equal Array Elements II
 */
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
// @lc code=start
//T:O(NlnN) S:O(1)
class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int res = 0;
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            res += nums[right--] - nums[left++];
        }
        return res;
    }
};
// @lc code=end

// T:O(N) S:O(1)
// class Solution
// {
// public:
//     int minMoves2(vector<int> &nums)
//     {
//         nth_element(nums.begin(), nums.begin() + (nums.end() - nums.begin()) / 2, nums.end());
//         int pivot = nums[nums.size() / 2];
//         int res = 0;
//         for (auto n : nums)
//         {
//             res += abs(n - pivot);
//         }
//         return res;
//     }
// };