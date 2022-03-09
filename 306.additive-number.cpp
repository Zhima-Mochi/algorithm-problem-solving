/*
 * @lc app=leetcode id=306 lang=cpp
 *
 * [306] Additive Number
 */
#include <string>
#include <stack>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isAdditiveNumber(string num)
    {
        int len = num.size();
        for (int i = 1; i != len / 2 + 1; ++i)
        {
            for (int j = 1; j != (len - 2 * i) + 1; ++j)
            {
                if (check(num.substr(0, i), num.substr(i, j), num.substr(i + j)))
                {
                    return true;
                }
            }
        }
        return false;
    }
    string numSum(string left, string right)
    {
        string res;
        auto cur_l = left.rbegin(), cur_r = right.rbegin();
        int pass = 0;
        while (cur_l != left.rend() && cur_r != right.rend())
        {
            int sum_val = *cur_l - '0' + *cur_r - '0';
            res.push_back('0' + ((pass + sum_val) % 10));
            pass = (pass + sum_val) / 10;
            ++cur_l;
            ++cur_r;
        }
        while (cur_l != left.rend())
        {
            res.push_back('0' + ((pass + *cur_l - '0') % 10));
            pass = (pass + *cur_l - '0') / 10;
            ++cur_l;
        }
        while (cur_r != right.rend())
        {
            res.push_back('0' + ((pass + *cur_r - '0') % 10));
            pass = (pass + *cur_r - '0') / 10;
            ++cur_r;
        }
        if (pass)
        {
            res.push_back(pass + '0');
        }
        reverse(res.begin(), res.end());
        return res;
    }
    bool check(string l, string r, string d)
    {
        if (l.size() > 1 && l[0] == '0' || r.size() > 1 && r[0] == '0' || d.size() > 1 && d[0] == '0')
        {
            return false;
        }
        auto sum_str = numSum(l, r);
        if (sum_str == d)
        {
            return true;
        }
        if (sum_str.size() >= d.size())
        {
            return false;
        }
        if (sum_str != d.substr(0, sum_str.size()))
        {
            return false;
        }
        return check(r, sum_str, d.substr(sum_str.size()));
    }
};
// @lc code=end
