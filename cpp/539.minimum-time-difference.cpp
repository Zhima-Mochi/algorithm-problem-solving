/*
 * @lc app=leetcode id=539 lang=cpp
 *
 * [539] Minimum Time Difference
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findMinDifference(vector<string> &timePoints)
    {
        vector<bool> time_seen(60 * 24);
        for (auto &time : timePoints)
        {
            int h = stoi(time.substr(0, 2));
            int m = stoi(time.substr(3, 2));
            if (time_seen[60 * h + m])
            {
                return 0;
            }
            else
            {
                time_seen[60 * h + m] = true;
            }
        }
        int pos_first = 0;
        while (!time_seen[pos_first])
        {
            ++pos_first;
        }
        int pos_last = 60 * 24 - 1;
        while (!time_seen[pos_last])
        {
            --pos_last;
        }
        int res = pos_first - pos_last + 60 * 24;
        if (res == 1)
        {
            return 1;
        }
        int count = 1;
        for (int i = pos_first + 1; i != pos_last + 1; ++i)
        {
            if (time_seen[i])
            {
                res = min(count, res);
                if (res == 1)
                {
                    return 1;
                }
                count = 1;
            }
            else
            {
                ++count;
            }
        }
        return res;
    }
};
// @lc code=end
