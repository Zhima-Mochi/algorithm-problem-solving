/*
 * @lc app=leetcode id=2409 lang=cpp
 *
 * [2409] Count Days Spent Together
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob)
    {
        int accum_days[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
        int a1 = accum_days[stoi(arriveAlice.substr(0, 2)) - 1] + stoi(arriveAlice.substr(3, 2));
        int a2 = accum_days[stoi(leaveAlice.substr(0, 2)) - 1] + stoi(leaveAlice.substr(3, 2));
        int b1 = accum_days[stoi(arriveBob.substr(0, 2)) - 1] + stoi(arriveBob.substr(3, 2));
        int b2 = accum_days[stoi(leaveBob.substr(0, 2)) - 1] + stoi(leaveBob.substr(3, 2));
        int arrive = max(a1, b1);
        int leave = min(a2, b2);
        return max(leave - arrive + 1, 0);
    }
};
// @lc code=end
