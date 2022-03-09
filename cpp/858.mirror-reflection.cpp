/*
 * @lc app=leetcode id=858 lang=cpp
 *
 * [858] Mirror Reflection
 */
#include <numeric>
using namespace std;
// @lc code=start
// t:O(log(p)), s:O(1)
class Solution
{
public:
    int mirrorReflection(int p, int q)
    {
        auto lcm_val = lcm(p, q);
        if (lcm_val / p % 2 == 0)
        {
            return 0;
        }
        return lcm_val / q % 2 == 0 ? 2 : 1;
    }
};
// @lc code=end
// t:O(log(p)), s:O(1)
// class Solution
// {
// public:
//     int mirrorReflection(int p, int q)
//     {
//         bool to_top = true;
//         int l = p;
//         while (true)
//         {
//             if (l % q == 0)
//             {
//                 if (!to_top)
//                 {
//                     return 0;
//                 }
//                 else
//                 {
//                     return l / q % 2 ? 1 : 2;
//                 }
//             }
//             else
//             {
//                 to_top = !to_top;
//                 if (l / q % 2 == 0)
//                 {
//                     l = p + (l % q);
//                 }
//                 else
//                 {
//                     l = p + (l % q - q);
//                 }
//             }
//         }
//     }
// };