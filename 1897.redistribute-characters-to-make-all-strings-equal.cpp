/*
 * @lc app=leetcode id=1897 lang=cpp
 *
 * [1897] Redistribute Characters to Make All Strings Equal
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool makeEqual(vector<string> &words)
    {
        int count[26] = {};
        for (auto &&w : words)
        {
            for (auto c : w)
            {
                ++count[c - 'a'];
            }
        }
        int width = words.size();
        for (auto n : count)
        {
            if (n % width != 0)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
