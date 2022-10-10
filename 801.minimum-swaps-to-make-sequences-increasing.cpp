/*
 * @lc app=leetcode id=801 lang=cpp
 *
 * [801] Minimum Swaps To Make Sequences Increasing
 */
#include <vector>
#include <array>
using namespace std;
// @lc code=start
// t:O(n), s:O(1)
class Solution
{
public:
    int minSwap(vector<int> &nums1, vector<int> &nums2)
    {
        int w = nums1.size();
        vector<array<int, 2>> records(w);
        records[0] = {0, 1};
        for (int i = 1; i != w; ++i)
        {
            records[i] = {w, w};
            if (records[i - 1][0] != w)
            {
                if (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1])
                {
                    records[i][0] = min(records[i][0], records[i - 1][0]);
                }
                if (nums2[i] > nums1[i - 1] && nums1[i] > nums2[i - 1])
                {
                    records[i][1] = min(records[i][1], records[i - 1][0] + 1);
                }
            }
            if (records[i - 1][1] != w)
            {
                if (nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1])
                {
                    records[i][0] = min(records[i][0], records[i - 1][1]);
                }
                if (nums2[i] > nums2[i - 1] && nums1[i] > nums1[i - 1])
                {
                    records[i][1] = min(records[i][1], records[i - 1][1] + 1);
                }
            }
        }
        return min(records.back()[0], records.back()[1]);
    }
};
// @lc code=end
