/*
 * @lc app=leetcode id=870 lang=cpp
 *
 * [870] Advantage Shuffle
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
// n=len(nums1)
// t:O(nlog(n)), s:O(n)
class Solution
{
public:
    vector<int> advantageCount(vector<int> &nums1, vector<int> &nums2)
    {
        int w = nums1.size();
        vector<int> nums2_idx(w);
        for (int i = 0; i != w; ++i)
        {
            nums2_idx[i] = i;
        }
        sort(nums2_idx.begin(), nums2_idx.end(), [&](int &l, int &r)
             {
            if(nums2[l]>nums2[r]){
                return true;
            }else{
                return false;
            } });
        sort(nums1.begin(), nums1.end(), greater<int>());
        int left = 0, right = w - 1;
        vector<int> res(w);
        for (int i = 0; i != w; ++i)
        {
            if (nums1[left] > nums2[nums2_idx[i]])
            {
                res[nums2_idx[i]] = nums1[left++];
            }
            else
            {
                res[nums2_idx[i]] = nums1[right--];
            }
        }
        return res;
    }
};
// @lc code=end
