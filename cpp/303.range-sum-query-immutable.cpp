/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 */
#include <vector>
#include <numeric>
using namespace std;
// @lc code=start
class NumArray
{
public:
    NumArray(vector<int> &nums)
    {
        int len = nums.size();
        for (int i = 0; i != len; ++i)
        {
            n.push_back(nums[i] + n[i]);
        }
    }

    int sumRange(int left, int right)
    {
        return n[right + 1] - n[left];
    }
    vector<int> n = {0};
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end
