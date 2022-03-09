/*
 * @lc app=leetcode id=522 lang=cpp
 *
 * [522] Longest Uncommon Subsequence II
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findLUSlength(vector<string> &strs)
    {
        sort(strs.begin(), strs.end(), [](string &l, string &r)
             {
                 if (l.size() < r.size())
                 {
                     return true;
                 }
                 else if (l.size() == r.size())
                 {
                     return l < r;
                 }
                 else
                 {
                     return false;
                 }
             });
        vector<string> repeat_strs;
        int len = strs.size();
        for (auto iter = strs.rbegin(), iterEnd = strs.rend(); iter < iterEnd; ++iter)
        {
            if (iter + 1 == iterEnd || *iter != *next(iter))
            {
                bool pass = true;
                for (auto &str : repeat_strs)
                {
                    if (iter->length() >= str.length())
                    {
                        break;
                    }
                    if (isSubstr(*iter, str))
                    {
                        pass = false;
                        break;
                    }
                }
                if (pass)
                {
                    return iter->size();
                }
            }
            else
            {
                repeat_strs.push_back(*iter);
                //we can also use binary search
                while (next(iter) != iterEnd && *next(iter) == *iter)
                {
                    ++iter;
                }
            }
        }
        return -1;
    }
    bool isSubstr(string &l, string &r)
    {
        int left = 0, right = 0;
        int l_len = l.size(), r_len = r.size();
        while (left != l_len && right != r_len)
        {
            if (l[left] == r[right])
            {
                ++left, ++right;
            }
            else
            {
                ++right;
            }
        }
        return left == l_len;
    }
};
// @lc code=end
