/*
 * @lc app=leetcode id=1668 lang=cpp
 *
 * [1668] Maximum Repeating Substring
 */
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxRepeating(string sequence, string word)
    {
        int res = 0;
        int count = 0;
        int w_width = word.size();
        int pos = sequence.find(word);
        if (pos == -1)
        {
            return 0;
        }
        else
        {
            count = 1;
        }

        while (pos != -1)
        {
            int next_pos = sequence.find(word, pos + w_width);
            if (next_pos - pos == w_width)
            {
                ++count;
                pos = next_pos;
            }
            else
            {
                res = max(res, count);
                count = 1;
                pos = sequence.find(word, pos + 1);
            }
        }
        return res;
    }
};
// @lc code=end
