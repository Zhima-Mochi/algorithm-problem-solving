/*
 * @lc app=leetcode id=822 lang=cpp
 *
 * [822] Card Flipping Game
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int flipgame(vector<int> &fronts, vector<int> &backs)
    {
        vector<bool> record(2001, true);
        int res = 2001;
        for (int i = 0, w = fronts.size(); i != w; ++i)
        {
            if (backs[i] == fronts[i])
            {
                record[fronts[i]] = false;
            }
        }
        for (int i = 0, w = fronts.size(); i != w; ++i)
        {
            if (record[fronts[i]])
            {
                res = min(res, fronts[i]);
            }
            if (record[backs[i]])
            {
                res = min(res, backs[i]);
            }
        }
        return res % 2001;
    }
};
// @lc code=end
