/*
 * @lc app=leetcode id=893 lang=cpp
 *
 * [893] Groups of Special-Equivalent Strings
 */
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution
{
public:
    int numSpecialEquivGroups(vector<string> &words)
    {
        unordered_set<string> set;
        for (auto &word : words)
        {
            string left(26, 0);
            string right(26, 0);
            int idx = 0;
            for (auto c : word)
            {
                if (idx % 2)
                {
                    ++right[c - 'a'];
                }
                else
                {
                    ++left[c - 'a'];
                }
                ++idx;
            }
            set.insert(left + right);
        }
        return set.size();
    }
};
// @lc code=end
