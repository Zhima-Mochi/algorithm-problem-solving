/*
 * @lc app=leetcode id=806 lang=cpp
 *
 * [806] Number of Lines To Write String
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> numberOfLines(vector<int> &widths, string s)
    {
        int line_count = 1;
        int word_count = 0;
        for (auto c : s)
        {
            if (word_count + widths[c - 'a'] <= 100)
            {
                word_count += widths[c - 'a'];
            }
            else
            {
                ++line_count;
                word_count = widths[c - 'a'];
            }
        }
        return {line_count, word_count};
    }
};
// @lc code=end
