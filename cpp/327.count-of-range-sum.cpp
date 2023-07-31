/*
 * @lc app=leetcode id=327 lang=cpp
 *
 * [327] Count of Range Sum
 */
#include <vector>
#include <functional>
using namespace std;
// @lc code=start
// t:O(nlogn), s:O(n)
class Solution
{
public:
    int countRangeSum(vector<int> &nums, int lower, int upper)
    {
        int w = nums.size();
        vector<long long> sums(w + 1);
        for (int i = 1; i <= w; ++i)
        {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        function<int(int, int)> helper = [&](int left, int right) -> int
        {
            if (right - left == 0)
            {
                return 0;
            }
            int mid = left + (right - left) / 2;
            int res = helper(left, mid) + helper(mid + 1, right);

            int cur = left;
            int l = mid + 1, r = mid + 1;
            while (cur <= mid)
            {
                while (l <= right && sums[l] - sums[cur] < lower)
                {
                    l++;
                }
                while (r <= right && sums[r] - sums[cur] <= upper)
                {
                    r++;
                }
                res += r - l;
                cur++;
            }

            vector<long long> sorted_sums(right - left + 1);
            int s1 = left, s2 = mid + 1;
            int s0 = 0;
            while (s1 <= mid || s2 <= right)
            {
                if (s2 > right)
                {
                    sorted_sums[s0++] = sums[s1++];
                }
                else if (s1 > mid)
                {
                    sorted_sums[s0++] = sums[s2++];
                }
                else
                {
                    if (sums[s1] < sums[s2])
                    {
                        sorted_sums[s0++] = sums[s1++];
                    }
                    else
                    {
                        sorted_sums[s0++] = sums[s2++];
                    }
                }
            }
            for (int i = 0; i != right - left + 1; i++)
            {
                sums[left + i] = sorted_sums[i];
            }
            return res;
        };
        return helper(0, w);
    }
};
// @lc code=end
