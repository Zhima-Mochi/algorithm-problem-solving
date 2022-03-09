/*
 * @lc app=leetcode id=798 lang=cpp
 *
 * [798] Smallest Rotation with Highest Score
 */
#include <vector>
using namespace std;
// @lc code=start
// t:O(N), s:O(N)
class Solution
{
public:
    int bestRotation(vector<int> &nums)
    {
        int w = nums.size();
        int high_points = 0;
        vector<int> diff_count(w);
        int res = 0;
        for (int i = 0; i != w; ++i)
        {
            if (nums[i] <= i)
            {
                ++high_points;
            }
            else if (nums[i] - i < w)
            {
                ++diff_count[nums[i] - i];
            }
        }
        int points = high_points;
        for (int i = w - 1; i != 0; --i)
        {
            if (nums[i] <= w - 1)
            {
                --points;
            }
            int index = w - 1 - i + 1 + nums[i];
            if (index < w)
            {
                ++diff_count[index];
            }
            points += diff_count[w - 1 - i + 1];
            if (points == high_points)
            {
                if (res != 0)
                {
                    res = i;
                }
            }
            else if (points > high_points)
            {
                high_points = points;
                res = i;
            }
        }
        return res;
    }
};
// @lc code=end
