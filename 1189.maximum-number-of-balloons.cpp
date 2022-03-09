/*
 * @lc app=leetcode id=1189 lang=cpp
 *
 * [1189] Maximum Number of Balloons
 */
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        vector<int> count(26);
        for (auto c : text)
        {
            ++count[c - 'a'];
        }
        return min({count['b' - 'a'], count['a' - 'a'], count['l' - 'a'] / 2, count['o' - 'a'] / 2, count['n' - 'a']});
    }
};
// @lc code=end
