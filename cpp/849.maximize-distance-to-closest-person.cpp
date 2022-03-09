/*
 * @lc app=leetcode id=849 lang=cpp
 *
 * [849] Maximize Distance to Closest Person
 */
#include <vector>
#include <climits>
using namespace std;
// @lc code=start
// t:O(n), s:O(1)
class Solution
{
public:
    int maxDistToClosest(vector<int> &seats)
    {
        int w = seats.size();
        int prev_ind = -1;
        int res = 0;
        for (int i = 0; i != w; ++i)
        {
            if (seats[i] == 1)
            {
                if (prev_ind == -1)
                {
                    res = i;
                }
                else
                {
                    res = max(res, (i - prev_ind) / 2);
                }
                prev_ind = i;
            }
        }
        return max(res, w - prev_ind - 1);
    }
};
// @lc code=end
