/*
 * @lc app=leetcode id=1370 lang=cpp
 *
 * [1370] Increasing Decreasing String
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    string sortString(string s)
    {
        vector<int> count(26);
        for (auto c : s)
        {
            ++count[c - 'a'];
        }
        string res;
        while (count != vector<int>(26))
        {
            for (int i = 0; i != 26; ++i)
            {
                if (count[i])
                {
                    --count[i];
                    res.push_back('a' + i);
                }
            }
            for (int i = 25; i != -1; --i)
            {
                if (count[i])
                {
                    --count[i];
                    res.push_back('a' + i);
                }
            }
        }
        return res;
    }
};
// @lc code=end
