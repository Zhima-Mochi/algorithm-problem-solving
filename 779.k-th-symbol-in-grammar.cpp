/*
 * @lc app=leetcode id=779 lang=cpp
 *
 * [779] K-th Symbol in Grammar
 */
#include <cmath>
using namespace std;
// @lc code=start
class Solution
{
public:
    int kthGrammar(int n, int k)
    {
        bool is_zero = true;
        int val = 1;
        while (--n)
        {
            if ((val * 2 - 1) * pow(2, n - 1) < k)
            {
                val *= 2;
                is_zero = !is_zero;
            }
            else
            {
                val *= 2;
                val -= 1;
            }
        }
        return is_zero ? 0 : 1;
    }
};
// @lc code=end