/*
 * @lc app=leetcode id=2455 lang=cpp
 *
 * [2455] Average Value of Even Numbers That Are Divisible by Three
 */
#include <vector>
#include <cmath>
using namespace std;
// @lc code=start
class Solution
{
public:
    int averageValue(vector<int> &nums)
    {
        long long res = 0;
        int count = 0;
        for (auto n : nums)
        {
            if (n % 6 == 0)
            {
                res += n;
                count++;
            }
        }
        if (count == 0)
        {
            return 0;
        }
        return round(res / count);
    }
};
// @lc code=end
