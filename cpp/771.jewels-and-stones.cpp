/*
 * @lc app=leetcode id=771 lang=cpp
 *
 * [771] Jewels and Stones
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int numJewelsInStones(string jewels, string stones)
    {
        vector<int> alphaCount(58);
        for (auto c : stones)
        {
            ++alphaCount[c - 'A'];
        }
        int res = 0;
        for (auto c : jewels)
        {
            res += alphaCount[c - 'A'];
        }
        return res;
    }
};
// @lc code=end
