/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    string addBinary(string a, string b)
    {
        auto a_len = a.size();
        auto b_len = b.size();
        string res;
        auto i = a_len - 1, j = b_len - 1;
        bool add_one = false;
        for (; i != -1 && j != -1; i--, j--)
        {
            short a_n = a[i] - '0';
            short b_n = b[j] - '0';
            if (a_n ^ b_n)
            {
                if (add_one)
                {
                    res.push_back('0');
                }
                else
                {
                    res.push_back('1');
                }
            }
            else
            {
                if (add_one)
                {
                    res.push_back('1');
                }
                else
                {
                    res.push_back('0');
                }
                if (a_n)
                {
                    add_one = true;
                }
                else
                {
                    add_one = false;
                }
            }
        }
        for (; i != -1; i--)
        {
            short n = a[i] - '0';
            if (add_one & n)
            {
                res.push_back('0');
            }
            else
            {
                if (add_one | n)
                {
                    res.push_back('1');
                }
                else
                {
                    res.push_back('0');
                }
                add_one = false;
            }
        }
        for (; j != -1; j--)
        {
            short n = b[j] - '0';
            if (add_one & n)
            {
                res.push_back('0');
            }
            else
            {
                if (add_one | n)
                {
                    res.push_back('1');
                }
                else
                {
                    res.push_back('0');
                }
                add_one = false;
            }
        }
        if (add_one)
        {
            res.push_back('1');
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
