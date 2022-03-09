/*
 * @lc app=leetcode id=551 lang=cpp
 *
 * [551] Student Attendance Record I
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool checkRecord(string s)
    {
        if (s.find("LLL") != -1)
        {
            return false;
        }
        auto f = s.find_first_of('A'), l = s.find_last_of('A');
        if (f != -1 && l != -1 && f != l)
        {
            return false;
        }
        return true;
    }
};
// @lc code=end
