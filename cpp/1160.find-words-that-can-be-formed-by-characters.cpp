/*
 * @lc app=leetcode id=1160 lang=cpp
 *
 * [1160] Find Words That Can Be Formed by Characters
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    int countCharacters(vector<string> &words, string chars)
    {
        int res = 0;
        vector<int> charCount(26);
        for (auto c : chars)
        {
            ++charCount[c - 'a'];
        }
        for (auto &w : words)
        {
            auto copy = charCount;
            bool contain = true;
            for (auto c : w)
            {
                --copy[c - 'a'];
                if (copy[c - 'a'] < 0)
                {
                    contain = false;
                    break;
                }
            }
            if (contain)
            {
                res += w.size();
            }
        }
        return res;
    }
};
// @lc code=end
