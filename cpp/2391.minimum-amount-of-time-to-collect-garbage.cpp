/*
 * @lc app=leetcode id=2391 lang=cpp
 *
 * [2391] Minimum Amount of Time to Collect Garbage
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    int garbageCollection(vector<string> &garbage, vector<int> &travel)
    {
        vector<int> accum_cost{0};
        for (auto t : travel)
        {
            accum_cost.push_back(accum_cost.back() + t);
        }
        int n = garbage.size();
        int seen = 0;
        int res = 0;
        for (int i = n - 1; i != -1; --i)
        {
            if (garbage[i].find('M') != string::npos)
            {
                if ((seen & 1) == 0)
                {
                    res += accum_cost[i];
                    seen |= 1;
                }
                res += count(garbage[i].begin(), garbage[i].end(), 'M');
            }
            if (garbage[i].find('P') != string::npos)
            {
                if ((seen & 2) == 0)
                {
                    res += accum_cost[i];
                    seen |= 2;
                }
                res += count(garbage[i].begin(), garbage[i].end(), 'P');
            }
            if (garbage[i].find('G') != string::npos)
            {
                if ((seen & 4) == 0)
                {
                    res += accum_cost[i];
                    seen |= 4;
                }
                res += count(garbage[i].begin(), garbage[i].end(), 'G');
            }
        }
        return res;
    }
};
// @lc code=end
