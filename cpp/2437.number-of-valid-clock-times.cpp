/*
 * @lc app=leetcode id=2437 lang=cpp
 *
 * [2437] Number of Valid Clock Times
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    int countTime(string time)
    {
        int count = 0;
        int min_count = 1;
        int w = time.size();
        string hour = time.substr(0, 2);
        string minute = time.substr(3, 2);
        if (minute[0] == '?' && minute[1] == '?')
        {
            min_count = 60;
        }
        else if (minute[0] == '?')
        {
            min_count = 6;
        }
        else if (minute[1] == '?')
        {
            min_count = 10;
        }
        if (hour[0] == '?' && hour[1] == '?')
        {
            count = 24 * min_count;
        }
        else if (hour[0] == '?')
        {
            if (hour[1] < '4')
            {
                count = 3 * min_count;
            }
            else
            {
                count = 2 * min_count;
            }
        }
        else if (hour[1] == '?')
        {
            if (hour[0] == '2')
            {
                count = 4 * min_count;
            }
            else
            {
                count = 10 * min_count;
            }
        }else{
            count = min_count;
        }

        return count;
    }
};
// @lc code=end
