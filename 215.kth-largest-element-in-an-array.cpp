/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int left = 0, right = nums.size() - 1;
        auto pivot = quickSort(nums, left, right);
        while (pivot != k - 1)
        {
            if (pivot < k - 1)
            {
                left = pivot + 1;
            }
            else
            {
                right = pivot - 1;
            }
            pivot = quickSort(nums, left, right);
        }
        return nums[pivot];
    }
    int quickSort(vector<int> &nums, int left, int right)
    {
        int pivot = left + (right - left) / 2;
        while (left != pivot)
        {
            if (nums[left] <= nums[pivot])
            {
                --pivot;
                swap(nums[pivot], nums[pivot + 1]);
                if (pivot == left)
                {
                    break;
                }
                swap(nums[left], nums[right]);
                right--;
            }
            else
            {
                ++left;
            }
        }
        while (right != pivot)
        {
            if (nums[right] > nums[pivot])
            {
                ++pivot;
                swap(nums[pivot - 1], nums[pivot]);
                if (pivot == right)
                {
                    break;
                }
                swap(nums[left], nums[right]);
                ++left;
            }
            else
            {
                --right;
            }
        }
        return pivot;
    }
};
// @lc code=end

//heap O(n log n)
// class Solution
// {
// public:
//     int findKthLargest(vector<int> &nums, int k)
//     {
//         make_heap(nums.begin(), nums.end());
//         pop_heap(nums.begin(), nums.end());
//         while (--k)
//         {
//             nums.pop_back();
//             pop_heap(nums.begin(), nums.end());
//         }
//         return nums.back();
//     }
// };