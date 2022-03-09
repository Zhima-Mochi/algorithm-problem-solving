/*
 * @lc app=leetcode id=397 lang=cpp
 *
 * [397] Integer Replacement
 */
#include <algorithm>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    int integerReplacement(int n)
    {
        int count = 0;
        while (n > 1)
        {
            ++count;
            if (n % 2 == 0)
            {
                n /= 2;
            }
            else
            {
                if (n % 4 == 3 && n > 3)
                {
                    n /= 2;
                    ++count;
                    ++n;
                }
                else
                {
                    --n;
                }
            }
        }
        return count;
    }
};
// @lc code=end

// class Solution
// {
//     unordered_map<int, short> count_map;

// public:
//     int integerReplacement(int n)
//     {
//         if (n == 1)
//         {
//             return 0;
//         }
//         else if (count_map.count(n))
//         {
//             return count_map[n];
//         }
//         else if (n % 2 == 0)
//         {
//             count_map[n] = 1 + integerReplacement(n / 2);
//             return count_map[n];
//         }
//         else
//         {
//             count_map[n] = 2 + min(integerReplacement(n / 2 + 1), integerReplacement(n / 2));
//             return count_map[n];
//         }
//     }
// };