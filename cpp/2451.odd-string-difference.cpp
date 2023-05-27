/*
 * @lc app=leetcode id=2451 lang=cpp
 *
 * [2451] Odd String Difference
 */
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
// @lc code=start
// t:O(l) s:O(n)
class Solution
{
public:
    string oddString(vector<string> &words)
    {
        unordered_map<string, int> m;
        for (auto s : words)
        {
            string val = "";
            int w = s.size();
            for (int i = 1; i < w; i++)
            {
                val += s[i] - s[i - 1];
            }
            m[val]++;
        }
        for (auto s : words)
        {
            string val = "";
            int w = s.size();
            for (int i = 1; i < w; i++)
            {
                val += s[i] - s[i - 1];
            }
            if (m[val] == 1)
            {
                return s;
            }
        }
        return "";
    }
};
// @lc code=end
