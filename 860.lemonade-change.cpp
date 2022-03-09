/*
 * @lc app=leetcode id=860 lang=cpp
 *
 * [860] Lemonade Change
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int count_5 = 0;
        int count_10 = 0;
        int len = bills.size();
        for (int i = 0; i != len; ++i)
        {
            if (bills[i] == 5)
            {
                ++count_5;
            }
            else if (bills[i] == 10)
            {
                if (count_5 == 0)
                {
                    return false;
                }
                --count_5;
                ++count_10;
            }
            else
            {
                if (count_10 && count_5)
                {
                    --count_10;
                    --count_5;
                }
                else if (count_5 >= 3)
                {
                    count_5 -= 3;
                }
                else
                {
                    return false;
                }
            }
            if (count_5 >= (len - i - 1) * 3)
            {
                break;
            }
        }
        return true;
    }
};
// @lc code=end
