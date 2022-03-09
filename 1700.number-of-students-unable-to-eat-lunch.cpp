/*
 * @lc app=leetcode id=1700 lang=cpp
 *
 * [1700] Number of Students Unable to Eat Lunch
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        int one_count = 0, zero_count = 0;
        for (auto n : students)
        {
            if (n == 1)
            {
                ++one_count;
            }
            else
            {
                ++zero_count;
            }
        }
        for (auto n : sandwiches)
        {
            if (n == 1 && one_count > 0)
            {
                --one_count;
            }
            else if (n == 0 && zero_count > 0)
            {
                --zero_count;
            }
            else
            {
                return one_count + zero_count;
            }
        }
        return one_count + zero_count;
    }
};
// @lc code=end
