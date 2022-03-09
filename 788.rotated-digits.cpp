/*
 * @lc app=leetcode id=788 lang=cpp
 *
 * [788] Rotated Digits
 */
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
// @lc code=start
class Solution
{
public:
    int rotatedDigits(int n)
    {
        int count = 0;
        int pre_num = 0;
        auto condition = isValidOrGood(pre_num);
        while (n >= 10000)
        {
            ++pre_num;
            n -= 10000;
            if (condition == 0)
            {
                condition = isValidOrGood(pre_num);
                continue;
            }
            if (condition == 1)
            {
                count += 2320;
            }
            else
            {
                count += 2401;
            }
            condition = isValidOrGood(pre_num);
        }
        if (condition == 0)
        {
            return count;
        }
        pre_num *= 10;
        while (n >= 1000)
        {
            ++pre_num;
            n -= 1000;
            if (condition == 0)
            {
                condition = isValidOrGood(pre_num);
                continue;
            }
            if (condition == 1)
            {
                count += 316;
            }
            else
            {
                count += 343;
            }
            condition = isValidOrGood(pre_num);
        }
        if (condition == 0)
        {
            return count;
        }
        pre_num *= 10;
        while (n >= 100)
        {
            ++pre_num;
            n -= 100;
            if (condition == 0)
            {
                condition = isValidOrGood(pre_num);
                continue;
            }
            if (condition == 1)
            {
                count += 40;
            }
            else
            {
                count += 49;
            }
            condition = isValidOrGood(pre_num);
        }
        if (condition == 0)
        {
            return count;
        }
        pre_num *= 10;
        while (n >= 10)
        {
            ++pre_num;
            n -= 10;
            if (condition == 0)
            {
                condition = isValidOrGood(pre_num);
                continue;
            }
            if (condition == 1)
            {
                count += 4;
            }
            else
            {
                count += 7;
            }
            condition = isValidOrGood(pre_num);
        }
        if (condition == 0)
        {
            return count;
        }
        pre_num *= 10;
        condition = isValidOrGood(pre_num);
        while (n >= 0)
        {
            if (condition == 1)
            {
                count += isValidOrGood(n) == 2 ? 1 : 0;
            }
            else
            {
                count += isValidOrGood(n) ? 1 : 0;
            }
            n -= 1;
        }
        return count;
    }
    int isValidOrGood(int n)
    {
        bool good = false;
        while (n)
        {
            auto residual = n % 10;
            if (residual == 3 || residual == 4 || residual == 7)
            {
                return 0;
            }
            if (!good && (residual != 0 && residual != 1 && residual != 8))
            {
                good = true;
            }
            n /= 10;
        }
        return good ? 2 : 1;
    }
};
// @lc code=end

// class Solution
// {
// public:
//     int rotatedDigits(int n)
//     {
//         int count = 0;
//         for (int i = 1; i != n + 1; ++i)
//         {
//             if (isGood(i))
//             {
//                 ++count;
//             }
//         }
//         return count;
//     }
//     bool isGood(int n)
//     {
//         bool good = false;
//         while (n)
//         {
//             auto residual = n % 10;
//             if (residual == 3 || residual == 4 || residual == 7)
//             {
//                 return false;
//             }
//             if (!good && (residual != 0 && residual != 1 && residual != 8))
//             {
//                 good = true;
//             }
//             n /= 10;
//         }
//         return good;
//     }
// };