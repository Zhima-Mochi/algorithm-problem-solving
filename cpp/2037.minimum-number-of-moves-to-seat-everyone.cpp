/*
 * @lc app=leetcode id=2037 lang=cpp
 *
 * [2037] Minimum Number of Moves to Seat Everyone
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minMovesToSeat(vector<int> &seats, vector<int> &students)
    {
        vector<int> record(101);
        for (auto n : seats)
        {
            --record[n];
        }
        for (auto n : students)
        {
            ++record[n];
        }
        int res = 0;
        int status = 0;
        for (auto n : record)
        {
            status += n;
            if (status != 0)
            {
                res += abs(status);
            }
        }
        return res;
    }
};
// @lc code=end
