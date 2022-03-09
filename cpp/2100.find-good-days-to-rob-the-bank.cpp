/*
 * @lc app=leetcode id=2100 lang=cpp
 *
 * [2100] Find Good Days to Rob the Bank
 */
#include <vector>
#include <numeric>
using namespace std;
// @lc code=start
// t:O(N), s:O(N)
class Solution
{
public:
    vector<int> goodDaysToRobBank(vector<int> &security, int time)
    {
        vector<int> res;
        int w = security.size();
        if (time == 0)
        {
            res = vector<int>(w);
            iota(res.begin(), res.end(), 0);
            return res;
        }
        vector<bool> records(w);
        int count = 1;
        for (int i = 1; i != w; ++i)
        {
            if (security[i] <= security[i - 1])
            {
                ++count;
            }
            else
            {
                count = 1;
            }
            if (count >= time + 1)
            {
                records[i] = true;
            }
            else
            {
                records[i] = false;
            }
        }
        count = 1;
        for (int i = w - 2; i != -1; --i)
        {
            if (security[i] <= security[i + 1])
            {
                ++count;
            }
            else
            {
                count = 1;
            }
            if (records[i] && count >= time + 1)
            {
                res.push_back(i);
            }
        }
        return res;
    }
};
// @lc code=end
