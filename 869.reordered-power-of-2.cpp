/*
 * @lc app=leetcode id=869 lang=cpp
 *
 * [869] Reordered Power of 2
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool reorderedPowerOf2(int n)
    {
        string n_str = to_string(n);
        int width = n_str.size();
        sort(n_str.begin(), n_str.end());
        long power2 = 1;
        string power2_str;
        while ((power2_str = to_string(power2)).size() <= width)
        {
            power2 <<= 1;
            if (power2_str.size() < width)
            {
                continue;
            }
            sort(power2_str.begin(), power2_str.end());
            if (power2_str == n_str)
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
