/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int len = nums.size();
        if (len == 0)
        {
            return 0;
        }
        int tail_cur = len - 1;
        while (nums[tail_cur] == val)
        {
            --tail_cur;
            if (tail_cur == -1)
            {
                return 0;
            }
        }

        for (int read_cur = 0; read_cur < tail_cur; read_cur++)
        {
            if (nums[read_cur] == val)
            {
                swap(nums[read_cur], nums[tail_cur]);
                tail_cur--;
            }
            while (nums[tail_cur] == val)
            {
                --tail_cur;
            }
        }
        return tail_cur + 1;
    }
};
// @lc code=end
