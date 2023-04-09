/*
 * @lc app=leetcode id=2399 lang=cpp
 *
 * [2399] Check Distances Between Same Letters
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool checkDistances(string s, vector<int> &distance)
    {
        string prev(26, -1);
        int w = s.size();
        for (int i = 0; i != w; ++i)
        {
            if (prev[s[i] - 'a'] == -1)
            {
                prev[s[i] - 'a'] = i;
            }
            else
            {
                if (i - prev[s[i] - 'a'] - 1 != distance[s[i] - 'a'])
                {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end
