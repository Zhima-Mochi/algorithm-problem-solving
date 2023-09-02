/*
 * @lc app=leetcode id=1537 lang=cpp
 *
 * [1537] Get the Maximum Score
 */
#include <vector>
#include <unordered_map>
#include <functional>
using namespace std;
// @lc code=start
// t:O(n1+n2), s:O(1)
class Solution
{
    int MOD = 1000000007;

public:
    int maxSum(vector<int> &nums1, vector<int> &nums2)
    {
        int w1 = nums1.size(), w2 = nums2.size();
        int cur1 = 0, cur2 = 0;
        long long accum1 = 0, accum2 = 0;
        while (cur1 != w1 || cur2 != w2)
        {
            if (cur1 == w1)
            {
                accum2 += nums2[cur2];
                cur2++;
                continue;
            }
            if (cur2 == w2)
            {
                accum1 += nums1[cur1];
                cur1++;
                continue;
            }
            if (nums1[cur1] < nums2[cur2])
            {
                accum1 += nums1[cur1++];
            }
            else if (nums1[cur1] > nums2[cur2])
            {
                accum2 += nums2[cur2++];
            }
            else
            {
                accum1 = accum2 = max(accum1, accum2) + nums1[cur1];
                cur1++;
                cur2++;
            }
        }
        return max(accum1, accum2) % MOD;
    }
};
// @lc code=end
