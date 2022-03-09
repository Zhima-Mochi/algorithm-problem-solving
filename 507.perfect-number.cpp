/*
 * @lc app=leetcode id=507 lang=cpp
 *
 * [507] Perfect Number
 */
#include <cmath>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool checkPerfectNumber(int num)
    {
        // int arr[] = {2, 3, 5, 7, 13};
        // for (auto &v : arr)
        // {
        //     if (num == (1 << (v - 1)) * ((1 << v) - 1))
        //     {
        //         return true;
        //     }
        // }
        // return false;
        if (num % 2 == 1)
        {
            return false;
        }

        auto sum_val = 1;
        int end_val = sqrt(num) + 1;
        for (int i = 2; i != end_val; ++i)
        {
            if (num % i == 0)
            {
                sum_val += (i + num / i);
            }
            if (sum_val > num)
            {
                return false;
            }
        }
        return sum_val == num;
    }
};
// @lc code=end
