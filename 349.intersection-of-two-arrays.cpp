/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int len1 = nums1.size(), len2 = nums2.size();
        int i = 0, j = 0;
        vector<int> res;
        while (i < len1 && j < len2)
        {
            while (i < len1 - 1 && nums1[i] == nums1[i + 1])
            {
                ++i;
            }
            while (j < len2 - 1 && nums2[j] == nums2[j + 1])
            {
                ++j;
            }
            if (nums1[i] < nums2[j])
            {
                ++i;
            }
            else if (nums1[i] > nums2[j])
            {
                ++j;
            }
            else
            {
                res.push_back(nums1[i]);
                ++i;
                ++j;
            }
        }
        return res;
    }
};
// @lc code=end
