/*
 * @lc app=leetcode id=1884 lang=cpp
 *
 * [1884] Egg Drop With 2 Eggs and N Floors
 */
#include <unordered_map>
using namespace std;
// @lc code=start
// t:O(n^2) s:O(n)
class Solution
{
public:
    unordered_map<int, int> records;
    int twoEggDrop(int n)
    {
        if (records.count(n))
        {
            return records[n];
        }
        int res = n;
        if (n <= 2)
        {
            return n;
        }
        for (int i = 2; i <= n / 2 + 1; ++i)
        {
            res = min(res, max(i, 1 + twoEggDrop(n - i)));
        }
        records[n] = res;
        return res;
    }
};
// @lc code=end