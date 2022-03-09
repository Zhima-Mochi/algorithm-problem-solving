/*
 * @lc app=leetcode id=1450 lang=cpp
 *
 * [1450] Number of Students Doing Homework at a Given Time
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int busyStudent(vector<int> &startTime, vector<int> &endTime, int queryTime)
    {
        int width = startTime.size();
        int res = 0;
        for (int i = 0; i != width; ++i)
        {
            if (startTime[i] <= queryTime && queryTime <= endTime[i])
            {
                ++res;
            }
        }
        return res;
    }
};
// @lc code=end
