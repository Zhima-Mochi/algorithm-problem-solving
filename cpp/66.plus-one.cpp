/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        auto len = digits.size();
        for (auto i = len - 1; i != -1; i--)
        {
            if (digits[i] == 9)
            {
                digits[i] = 0;
            }
            else
            {
                digits[i] += 1;
                return digits;
            }
        }
        auto res = vector<int>(len + 1, 0);
        res[0] = 1;
        return res;
    }
};
// @lc code=end
