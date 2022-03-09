/*
 * @lc app=leetcode id=233 lang=cpp
 *
 * [233] Number of Digit One
 */
#include <vector>
#include <string>
#include <cmath>
using namespace std;
// @lc code=start
// t:O(log(n)), s:O(1)
class Solution
{
public:
    int countDigitOne(int n)
    {
        int base_num = 1;
        int digit_len = 0;
        vector<int> records = {0};
        while (base_num <= n / 10)
        {
            base_num *= 10;
            ++digit_len;
            records.push_back(digit_len * (base_num / 10));
        }
        int res = 0;
        while (n)
        {
            if (n / base_num)
            {
                res += n / base_num * records[digit_len];
                if (n / base_num == 1)
                {
                    res += n % base_num + 1;
                }
                else
                {
                    res += base_num;
                }
            }
            n = n % base_num;
            base_num /= 10;
            --digit_len;
        }
        return res;
    }
};
// @lc code=end
