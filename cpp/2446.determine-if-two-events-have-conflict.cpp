/*
 * @lc app=leetcode id=2446 lang=cpp
 *
 * [2446] Determine if Two Events Have Conflict
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool haveConflict(vector<string> &event1, vector<string> &event2)
    {
        int e1 = 0, e2 = 0, e3 = 0, e4 = 0;
        for (auto c : event1[0])
        {
            if (c == ':')
            {
                continue;
            }
            e1 += (c - '0');
            e1 *= 10;
        }
        for (auto c : event1[1])
        {
            if (c == ':')
            {
                continue;
            }
            e2 += (c - '0');
            e2 *= 10;
        }
        for (auto c : event2[0])
        {
            if (c == ':')
            {
                continue;
            }
            e3 += (c - '0');
            e3 *= 10;
        }
        for (auto c : event2[1])
        {
            if (c == ':')
            {
                continue;
            }
            e4 += (c - '0');
            e4 *= 10;
        }
        return e2 >= e3 && e1 <= e3 || e4 >= e1 && e3 <= e1;
    }
};
// @lc code=end
