/*
 * @lc app=leetcode id=1013 lang=cpp
 *
 * [1013] Partition Array Into Three Parts With Equal Sum
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool canThreePartsEqualSum(vector<int> &arr)
    {
        int sum_val = 0;
        for (auto n : arr)
        {
            sum_val += n;
        }
        if (sum_val % 3)
        {
            return false;
        }
        else
        {
            sum_val /= 3;
        }
        int left = 1;
        int width=arr.size();
        int left_sum = arr[0];
        while (left_sum != sum_val && left!=width)
        {
            left_sum += arr[left++];
        }
        if (left == width)
        {
            return false;
        }
        left_sum = arr[left++];
        while (left_sum != sum_val && left!=width)
        {
            left_sum += arr[left++];
        }
        if (left == width)
        {
            return false;
        }
        return true;
    }
};
// @lc code=end
