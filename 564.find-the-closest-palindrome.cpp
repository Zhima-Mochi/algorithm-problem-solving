/*
 * @lc app=leetcode id=564 lang=cpp
 *
 * [564] Find the Closest Palindrome
 */
#include <string>
#include <cmath>
using namespace std;
// @lc code=start
// t:O(log(len(n))), s:O(1)
class Solution
{
public:
    string nearestPalindromic(string n)
    {
        int w = n.size();
        long long n_num = stol(n);
        if (w == 1)
        {
            return to_string(n_num - 1);
        }
        long long smaller_res = static_cast<long long>(round(pow(10, w - 1))) - 1;
        long long num = stol(n.substr(0, w / 2));
        if (w % 2)
        {
            num *= 10;
            num += stoi(n.substr(w / 2, 1));
        }
        for (int i = num; i != 0; --i)
        {
            long long left_num = i;
            long long right_num = w % 2 ? left_num / 10 : left_num;
            while (right_num)
            {
                left_num *= 10;
                left_num += right_num % 10;
                right_num /= 10;
            }
            if (left_num < n_num)
            {
                smaller_res = max(left_num, smaller_res);
                break;
            }
        }
        long long greater_res = static_cast<long long>(round(pow(10, w))) + 1;
        for (int i = num; i != 1000000000; ++i)
        {
            long long left_num = i;
            long long right_num = w % 2 ? left_num / 10 : left_num;
            while (right_num)
            {
                left_num *= 10;
                left_num += right_num % 10;
                right_num /= 10;
            }
            if (left_num > n_num)
            {
                greater_res = min(left_num, greater_res);
                break;
            }
        }
        long long res = n_num - smaller_res > greater_res - n_num ? greater_res : smaller_res;
        return to_string(res);
    }
};
// @lc code=end
