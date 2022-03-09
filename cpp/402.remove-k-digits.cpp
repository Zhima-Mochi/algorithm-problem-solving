/*
 * @lc app=leetcode id=402 lang=cpp
 *
 * [402] Remove K Digits
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        int len = num.size();
        int last_len = len - k;
        string res;
        for (int pos = 0; pos != len && last_len; ++pos)
        {
            while (!res.empty() && num[pos] < res.back() && len - pos + res.size() > last_len)
            {
                res.pop_back();
            }
            if (res.size() < last_len)
            {
                if (num[pos] == '0' && res.empty())
                {
                    --last_len;
                }
                else
                {
                    res.push_back(num[pos]);
                }
            }
        }
        return res != "" ? res : "0";
    }
};
// @lc code=end
