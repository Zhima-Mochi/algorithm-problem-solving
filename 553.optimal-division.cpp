/*
 * @lc app=leetcode id=553 lang=cpp
 *
 * [553] Optimal Division
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    string optimalDivision(vector<int> &nums)
    {
        int width = nums.size();
        string res;
        res.append(to_string(nums[0]));
        if (width == 1)
        {
            return res;
        }
        else if (width == 2)
        {
            res.push_back('/');
            res.append(to_string(nums[1]));
            return res;
        }
        else
        {
            res.append("/(");
        }
        for (int i = 1; i != width - 1; ++i)
        {
            res.append(to_string(nums[i]));
            res.push_back('/');
        }
        res.append(to_string(nums[width - 1]));
        res.push_back(')');
        return res;
    }
};
// @lc code=end
