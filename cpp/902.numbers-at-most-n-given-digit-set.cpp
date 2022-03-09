/*
 * @lc app=leetcode id=902 lang=cpp
 *
 * [902] Numbers At Most N Given Digit Set
 */

#include <vector>
#include <string>
#include <cmath>
using namespace std;
// @lc code=start
class Solution
{
public:
    int atMostNGivenDigitSet(vector<string> &digits, int n)
    {
        int res = 0;
        int d_num = digits.size();
        vector<int> num_digits;
        for (auto &&d : digits)
        {
            num_digits.push_back(stoi(d));
        }
        string n_str = to_string(n);
        
        bool next = true;
        for (int i = 0, w = n_str.size(); i != w; ++i)
        {
            int base = pow(d_num, w - i - 1);
            if (i != w - 1)
            {
                res += base;
            }
            else
            {
                base = 1;
            }
            if (next)
            {
                next = false;
                for (auto d : num_digits)
                {
                    if (d < n_str[i] - '0')
                    {
                        res += base;
                    }
                    else
                    {
                        if (d == n_str[i] - '0')
                        {
                            next = true;
                            if (i == w - 1)
                            {
                                ++res;
                            }
                        }
                        break;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
