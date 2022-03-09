/*
 * @lc app=leetcode id=1015 lang=cpp
 *
 * [1015] Smallest Integer Divisible by K
 */
#include <vector>
using namespace std;
// @lc code=start
// s:O(1)
class Solution
{
public:
    int smallestRepunitDivByK(int k)
    {
        if (k % 2 == 0 || k % 5 == 0)
        {
            return -1;
        }
        return helpler(k);
    }
    int helpler(int k)
    {
        int n = 1;
        int len = 1;
        while (n < k)
        {
            ++len;
            n *= 10;
            n += 1;
        }
        // vector<bool> seen(k + 1);
        while (n = n % k)
        {
            // if (seen[n])
            // {
            //     return -1;
            // }
            // else
            // {
            //     seen[n] = true;
            // }
            ++len;
            n *= 10;
            n += 1;
        }
        return len;
    }
};
// @lc code=end
