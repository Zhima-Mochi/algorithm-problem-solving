/*
 * @lc app=leetcode id=821 lang=cpp
 *
 * [821] Shortest Distance to a Character
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> shortestToChar(string s, char c)
    {
        int len = s.size();
        auto cur = 0;
        vector<int> res;
        res.reserve(len);
        for (int i = 0; i != len; ++i)
        {
            if (s[i] == c)
            {
                while (cur <= i)
                {
                    res.push_back(i - cur);
                    ++cur;
                }
                break;
            }
        }
        for (int i = cur; i != len; ++i)
        {
            if (s[i] == c)
            {
                int shift = (i - cur) / 2;

                for (int d = 1; d <= shift; ++d, ++cur)
                {
                    res.push_back(d);
                }
                while (cur <= i)
                {
                    res.push_back(i - cur);
                    ++cur;
                }
            }
        }
        int distance = 0;
        while (cur++ != len)
        {
            res.push_back(++distance);
        }
        return res;
    }
};
// @lc code=end
