/*
 * @lc app=leetcode id=1598 lang=cpp
 *
 * [1598] Crawler Log Folder
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minOperations(vector<string> &logs)
    {
        int d = 0;
        for (auto &log : logs)
        {
            if (log[1] == '.')
            {
                d = d > 0 ? d - 1 : 0;
            }
            else if (log[0] != '.')
            {
                ++d;
            }
        }
        return d;
    }
};
// @lc code=end
