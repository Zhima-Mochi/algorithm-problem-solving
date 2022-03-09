/*
 * @lc app=leetcode id=1154 lang=cpp
 *
 * [1154] Day of the Year
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
    static vector<int> accum_days;

public:
    int dayOfYear(string date)
    {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        return accum_days[month - 1] + day + (((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0) && (year % 4000 != 0)) && month > 2 ? 1 : 0);
    }
};
vector<int> Solution::accum_days = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
// @lc code=end
