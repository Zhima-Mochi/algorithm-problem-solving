/*
 * @lc app=leetcode id=1317 lang=cpp
 *
 * [1317] Convert Integer to the Sum of Two No-Zero Integers
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> getNoZeroIntegers(int n)
    {
        int left_num = 0;
        int num = n;
        int base_num = 1;
        while (num)
        {
            if ((num % 10) > 1)
            {
                left_num += base_num;
            }
            else if ((num % 10) == 1)
            {
                if (num != 1)
                {
                    left_num += 2 * base_num;
                    num -= 10;
                }
            }
            else
            {
                left_num += base_num;
                num -= 10;
            }
            num /= 10;
            base_num *= 10;
        }
        return {left_num, n - left_num};
    }
};
// @lc code=end
