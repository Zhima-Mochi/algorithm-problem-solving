/*
 * @lc app=leetcode id=2466 lang=cpp
 *
 * [2466] Count Ways To Build Good Strings
 */
#include <vector>
using namespace std;
// @lc code=start
// t:O(n), s:O(n)
class Solution
{
public:
    int countGoodStrings(int low, int high, int zero, int one)
    {
        vector<long long> records(high + 1);
        records[0] = 1;
        for (int i = 0; i != high + 1; ++i)
        {
            if (i + zero <= high)
            {
                records[i + zero] += records[i];
                records[i + zero] %= 1000000007;
            }
            if (i + one <= high)
            {
                records[i + one] += records[i];
                records[i + one] %= 1000000007;
            }
        }
        long long res = 0;
        for (int i = low; i != high + 1; ++i)
        {
            res += records[i];
            res %= 1000000007;
        }
        return res;
    }
};
// @lc code=end
