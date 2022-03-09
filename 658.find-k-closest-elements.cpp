/*
 * @lc app=leetcode id=658 lang=cpp
 *
 * [658] Find K Closest Elements
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
    int binary_search(vector<int> &arr, int k, int x)
    {
        size_t left = 0, right = arr.size() - k;
        while (left < right)
        {
            auto middle = left + (right - left) / 2;
            if (arr[middle + k] - x >= x - arr[middle])
            {
                right = middle;
            }
            else
            {
                left = middle + 1;
            }
        }
        return left;
    }

public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        auto back_index = arr.size() - 1;
        if (x <= arr[0])
        {
            return vector<int>(arr.begin(), arr.begin() + k);
        }
        else if (x >= arr[back_index])
        {
            return vector<int>(arr.end() - k, arr.end());
        }
        auto pos = binary_search(arr, k, x);
        return vector<int>{arr.begin() + pos, arr.begin() + pos + k};
    }
};
// @lc code=end
