/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 */

#include <algorithm>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{

public:
    int integerBreak(int n)
    {
        if (n == 2)
        {
            return 1;
        }
        else if (n == 3)
        {
            return 2;
        }
        int res = 1;
        while (n > 4)
        {
            res *= 3;
            n -= 3;
        }
        res *= n;
        return res;
    }
};
// @lc code=end

// class Solution
// {
//     unordered_map<int, int> umap;

// public:
//     int integerBreak(int n)
//     {
//         if (umap.count(n))
//         {
//             return umap[n];
//         }
//         if (n == 1)
//         {
//             umap[1] = 1;
//             return 1;
//         }
//         int res = 1;
//         for (int i = 1; 2 * i <= n; ++i)
//         {
//             res = max(res, max(integerBreak(i), i) * max(integerBreak(n - i), n - i));
//         }
//         umap[n] = res;
//         return res;
//     }
// };