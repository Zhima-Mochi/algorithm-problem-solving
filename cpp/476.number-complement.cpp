/*
 * @lc app=leetcode id=476 lang=cpp
 *
 * [476] Number Complement
 */

// @lc code=start
class Solution
{
public:
    int findComplement(int num)
    {
        unsigned m = ~0;
        while (m & num)
        {
            m <<= 1;
        }
        return ~m ^ num;
        // int m=1;
        // int n=num;
        // while(n/=2){
        //     m<<=1;
        //     ++m;
        // }
        // return m^num;
    }
};
// @lc code=end
