/*
 * @lc app=leetcode id=477 lang=cpp
 *
 * [477] Total Hamming Distance
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int totalHammingDistance(vector<int> &nums)
    {
        int res = 0;
        int len = nums.size();
        for (int i = 0; i != 31; ++i)
        {
            int count = 0;
            for (auto n : nums)
            {
                count += (n >> i) & 1;
            }
            res += count * (len - count);
        }
        return res;
    }
};
// @lc code=end
