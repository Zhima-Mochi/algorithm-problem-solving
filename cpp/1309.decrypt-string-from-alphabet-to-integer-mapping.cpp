/*
 * @lc app=leetcode id=1309 lang=cpp
 *
 * [1309] Decrypt String from Alphabet to Integer Mapping
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    string freqAlphabets(string s)
    {
        string res;
        int len = s.size();
        int val = 0;
        for (int i = 0; i != len; ++i)
        {
            if (s[i] == '#')
            {
                continue;
            }
            val += s[i] - '0';
            if (i + 2 < len && s[i + 2] == '#')
            {
                val *= 10;
            }
            else
            {
                res.push_back('a' + val - 1);
                val = 0;
            }
        }
        return res;
    }
};
// @lc code=end
