/*
 * @lc app=leetcode id=375 lang=cpp
 *
 * [375] Guess Number Higher or Lower II
 */
#include <algorithm>
#include <vector>
#include <array>
using namespace std;
// @lc code=start
class Solution
{
    array<array<short, 200>, 200> moneyAmount;

public:
    int getMoneyAmount(int n)
    {
        array<short, 200> arr;
        arr.fill(-1);
        moneyAmount.fill(arr);
        return getMoneyAmount(1, n);
    }
    int getMoneyAmount(int n1, int n2)
    {
        if (n1 >= n2)
        {
            return 0;
        }
        if (moneyAmount[n1 - 1][n2 - 1] != -1)
        {
            return moneyAmount[n1 - 1][n2 - 1];
        }
        int res = INT_MAX;
        for (int num = n1 + (n2 - n1) / 2; num <= n2; ++num)
        {
            res = min(res, num + max(getMoneyAmount(num + 1, n2), getMoneyAmount(n1, num - 1)));
            if (getMoneyAmount(num + 1, n2) < getMoneyAmount(n1, num - 1))
            {
                break;
            }
        }
        moneyAmount[n1-1][n2-1] = res;
        return res;
    }
};
// @lc code=end
