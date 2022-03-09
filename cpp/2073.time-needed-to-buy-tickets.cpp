/*
 * @lc app=leetcode id=2073 lang=cpp
 *
 * [2073] Time Needed to Buy Tickets
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        int res = tickets[k];
        if (res == 1)
        {
            return k + 1;
        }
        for (int i = 0; i != k; ++i)
        {
            res += min(tickets[i], tickets[k]);
        }
        for (int i = k + 1, w = tickets.size(); i != w; ++i)
        {
            res += min(tickets[i], tickets[k] - 1);
        }
        return res;
    }
};
// @lc code=end
