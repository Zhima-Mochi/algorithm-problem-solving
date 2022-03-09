/*
 * @lc app=leetcode id=1185 lang=cpp
 *
 * [1185] Day of the Week
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
    static vector<string> dayString;
    static vector<int> accum_days;

public:
    string dayOfTheWeek(int day, int month, int year)
    {
        int count_days = 0;
        count_days += (year - 1971) * 365;
        count_days += (year - 1) / 4 - 1970 / 4;
        count_days += (year % 4 == 0 && year % 100 != 0 || year % 400 == 0 && year % 4000 != 0) && (month > 2) ? accum_days[month - 1] + 1 : accum_days[month - 1];
        count_days += day;
        return dayString[(count_days + 4) % 7];
    }
};
vector<string> Solution::dayString = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
vector<int> Solution::accum_days = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

// @lc code=end
