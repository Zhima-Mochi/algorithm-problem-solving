/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        auto len = nums.size();
        if (len == 0)
        {
            return 0;
        }
        int removeDup_cur = 0;
        for (size_t read_cur = 1;
             read_cur != len; read_cur++)
        {
            if (nums[read_cur] != nums[removeDup_cur])
            {
                removeDup_cur++;
                swap(nums[read_cur], nums[removeDup_cur]);
            }
        }
        return removeDup_cur + 1;
    }
};
// @lc code=end
