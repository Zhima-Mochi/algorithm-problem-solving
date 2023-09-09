/*
 * @lc app=leetcode id=1968 lang=cpp
 *
 * [1968] Array With Elements Not Equal to Average of Neighbors
 */
#include <vector>
using namespace std;
// @lc code=start
// t:O(nlogn), s:O(n)
class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int w = nums.size();
        vector<int> res(w);
        int cur = 0;
        for (int i = 0; i < w; i += 2)
        {
            res[i] = nums[cur++];
        }
        for (int i = 1; i < w; i += 2)
        {
            res[i] = nums[cur++];
        }
        return res;
    }
};
// @lc code=end
