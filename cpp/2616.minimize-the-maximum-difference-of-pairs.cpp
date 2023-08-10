/*
 * @lc app=leetcode id=2616 lang=cpp
 *
 * [2616] Minimize the Maximum Difference of Pairs
 */
#include <vector>
#include <queue>
using namespace std;
// @lc code=start
// t:O(nlog(n)+log(m)), s:O(log(n))
class Solution
{
public:
    int minimizeMax(vector<int> &nums, int p)
    {
        int w = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.back() - nums.front();
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            int cnt = 0;
            for (int i = 0; i < w - 1; ++i)
            {
                if (nums[i + 1] - nums[i] <= mid)
                {
                    cnt++;
                    i += 1;
                }
            }
            if (cnt >= p)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};
// @lc code=end
