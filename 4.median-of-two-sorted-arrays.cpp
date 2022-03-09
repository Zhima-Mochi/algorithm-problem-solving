/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

#include <vector>
#include <algorithm>
#include <climits>
#include <functional>
using namespace std;
// @lc code=start
// t:O(log(M+N)), s:O(log(1))
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int w1 = nums1.size();
        int w2 = nums2.size();
        function<double(int)> get_k = [&](int k)
        {
            int start1 = 0;
            int start2 = 0;
            while (true)
            {
                if (start1 == w1)
                {
                    return nums2[start2 + k - 1];
                }
                if (start2 == w2)
                {
                    return nums1[start1 + k - 1];
                }
                if (k == 1)
                {
                    return min(nums1[start1], nums2[start2]);
                }
                int next_start1 = min(start1 + k / 2 - 1, w1 - 1);
                int next_start2 = min(start2 + k / 2 - 1, w2 - 1);
                if (nums1[next_start1] < nums2[next_start2])
                {
                    k -= next_start1 - start1 + 1;
                    start1 = next_start1 + 1;
                }
                else
                {
                    k -= next_start2 - start2 + 1;
                    start2 = next_start2 + 1;
                }
            };
            return 0;
        };
        if ((w1 + w2) % 2)
        {
            return get_k((w1 + w2) / 2+1);
        }
        else
        {
            return (get_k((w1 + w2) / 2) + get_k((w1 + w2) / 2 + 1)) / 2;
        }
    }
};
// @lc code=end
