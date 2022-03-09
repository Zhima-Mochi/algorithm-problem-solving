/*
 * @lc app=leetcode id=274 lang=cpp
 *
 * [274] H-Index
 */
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int len = citations.size();
        map<short, short, greater<short>> omap;
        for (auto &c : citations)
        {
            if (c > len)
            {
                ++omap[len];
            }
            else
            {
                ++omap[c];
            }
        }
        short count = 0;
        for (auto &pair : omap)
        {
            if (pair.first <= count + pair.second)
            {
                return max(count, pair.first);
            }
            count += pair.second;
        }
        return count;
    }
};
// @lc code=end
