/*
 * @lc app=leetcode id=953 lang=cpp
 *
 * [953] Verifying an Alien Dictionary
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        string order_val(26, ' ');
        for (auto iter = order.begin(), iterBegin = iter, iterEnd = order.end(); iter != iterEnd; ++iter)
        {
            order_val[*iter - 'a'] = iter - iterBegin;
        }
        for (auto iter = next(words.begin()), iterEnd = words.end(); iter != iterEnd; ++iter)
        {
            if (!comp(*prev(iter), *iter, order_val))
            {
                return false;
            }
        }
        return true;
    }
    bool comp(const string &l, const string &r, const string &order_val)
    {
        int l_len = l.size();
        int r_len = r.size();
        int pos = 0;
        while (pos < l_len && pos < r_len)
        {
            if (l[pos] == r[pos])
            {
                ++pos;
            }
            else
            {
                return order_val[l[pos]-'a'] < order_val[r[pos]-'a'];
            }
        }
        return l_len <= r_len ? true : false;
    }
};
// @lc code=end
