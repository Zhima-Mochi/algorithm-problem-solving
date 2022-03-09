/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 */
#include <vector>
using namespace std;
// @lc code=start
// t:O(nlog(n)), s:O(number of stacks)
class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        // quick_sort(nums, 0, nums.size() - 1);
        heap_sort(nums);
        return nums;
    }
    void quick_sort(vector<int> &nums, int left, int right)
    {
        if (left >= right)
        {
            return;
        }
        nth_element(nums.begin() + left, nums.begin() + left + (right - left) / 2, nums.begin() + right + 1);
        swap(nums[left], nums[left + (right - left) / 2]);
        int pivot = left;
        int end = right;
        ++right;
        while (true)
        {
            while (--right >= 0 && nums[right] > nums[pivot])
            {
            }
            while (++left <= end && nums[left] <= nums[pivot])
            {
            }
            if (left >= right)
            {
                break;
            }
            swap(nums[left], nums[right]);
        }
        swap(nums[pivot], nums[right]);
        quick_sort(nums, pivot, right - 1);
        quick_sort(nums, right + 1, end);
    }
    void max_heapify(vector<int> &nums, int i, int len)
    {
        while ((i << 1) + 1 <= len)
        {
            int l_child = (i << 1) + 1;
            int r_child = (i << 1) + 2;
            int large_idx = i;
            if (nums[l_child] > nums[large_idx])
            {
                large_idx = l_child;
            }
            if (r_child <= len && nums[r_child] > nums[large_idx])
            {
                large_idx = r_child;
            }
            if (large_idx != i)
            {
                swap(nums[i], nums[large_idx]);
                i = large_idx;
            }
            else
            {
                break;
            }
        }
    }
    void build_max_heap(vector<int> &nums, int len)
    {
        for (int i = len / 2; i != -1; --i)
        {
            max_heapify(nums, i, len);
        }
    }
    void heap_sort(vector<int> &nums)
    {
        int len = nums.size() - 1;
        build_max_heap(nums, len);
        for (int i = len; i != 0; --i)
        {
            swap(nums[i], nums[0]);
            --len;
            max_heapify(nums, 0, len);
        }
    }
};
// @lc code=end
