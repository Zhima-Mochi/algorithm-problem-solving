/*
 * @lc app=leetcode id=639 lang=cpp
 *
 * [639] Decode Ways II
 */
#include <string>
#include <iostream>
using namespace std;
// @lc code=start
#define mod 1000000007
class Solution
{
    // int bound = 69000000;
    // int multiply(const int &n, int mul)
    // {
    //     if (n <= bound)
    //     {
    //         return n * mul;
    //     }
    //     auto res = n;
    //     --mul;
    //     while (mul)
    //     {
    //         auto count = 1;
    //         auto origin = n;
    //         while (2 * count <= mul)
    //         {
    //             origin *= 2;
    //             origin %= mod;
    //             count *= 2;
    //         }
    //         res += origin;
    //         res %= mod;
    //         mul -= count;
    //     }
    //     return res;
    // }
public:
    int numDecodings(string s)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if (s.front() == '0')
        {
            return 0;
        }
        auto len = s.size();
        long count;
        if (s.front() == '*')
            count = 9;
        else
            count = 1;
        long prev_count = 1;
        for (int i = 1; i != len; ++i)
        {
            auto next_prev_count = count;
            if (s[i - 1] == '0') [[unlikely]]
            {
                if (s[i] == '0')
                {
                    //00
                    return 0;
                }
                else if (s[i] == '*')
                {
                    //0*
                    count *= 9;
                }
            }
            else if (s[i - 1] == '*')
            {
                if (s[i] == '0')
                {
                    //*0
                    count = prev_count * 2;
                }
                else if (s[i] != '*')
                {
                    //*n
                    if (s[i] - '0' <= 6)
                    {
                        count += prev_count * 2;
                    }
                    else
                    {
                        count += prev_count;
                    }
                }
                else
                {
                    //**
                    count *= 9;
                    count += prev_count * 15;
                }
            }
            else if (s[i] != '*') [[likely]]
            {
                //nn
                if (stoi(s.substr(i - 1, 2)) <= 26)
                {
                    if (s[i] == '0')
                    {
                        count = prev_count;
                    }
                    else
                    {
                        count += prev_count;
                    }
                }
                else if (s[i] == '0')
                {
                    return 0;
                }
            }
            else
            {
                //n*
                count *= 9;
                if (s[i - 1] == '2')
                {
                    count += prev_count * 6;
                }
                else if (s[i - 1] == '1')
                {
                    count += prev_count * 9;
                }
            }
            prev_count = next_prev_count;
            count %= mod;
        }
        return count;
    }
};
// @lc code=end
// "1*"\n"*******"\n"********"\n"*********"\n"7*9*3*6*3*0*5*4*9*7*3*7*1*8*3*2*0*0*6*"\n
