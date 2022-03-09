/*
 * @lc app=leetcode id=767 lang=cpp
 *
 * [767] Reorganize String
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    string reorganizeString(string s)
    {
        int count[26] = {};
        int width = s.size();
        for (auto c : s)
        {
            ++count[c - 'a'];
        }
        int max_count = 0;
        int max_ind;
        for (int i = 0; i != 26; ++i)
        {
            if (count[i] + (count[i] - 1) > width)
            {
                return "";
            }
            if (count[i] > max_count)
            {
                max_count = count[i];
                max_ind = i;
            }
        }
        string res(width, 0);
        int ind = 0;
        while (count[max_ind]-- > 0)
        {
            res[ind] = 'a' + max_ind;
            ind += 2;
        }
        for (int i = 0; i != 26; ++i)
        {
            while (count[i]-- > 0)
            {
                if (ind >= width)
                {
                    ind = 1;
                }
                res[ind] = 'a' + i;
                ind += 2;
            }
        }
        return res;
    }
};
// @lc code=end
