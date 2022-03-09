/*
 * @lc app=leetcode id=1550 lang=cpp
 *
 * [1550] Three Consecutive Odds
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool threeConsecutiveOdds(vector<int> &arr)
    {
        int count = 0;
        for (auto n : arr)
        {
            if (n % 2)
            {
                if (++count == 3)
                {
                    return true;
                }
            }
            else
            {
                count = 0;
            }
        }
        return false;
    }
};
// @lc code=end
