/*
 * @lc app=leetcode id=1416 lang=cpp
 *
 * [1416] Restore The Array
 */
#include <string>
#include <vector>
#include <functional>
using namespace std;
// @lc code=start
// t:O(n^2) s:O(1)
class Solution
{
public:
    int numberOfArrays(string s, int k)
    {
        int w = s.size();
        int records[11];
        for (int i = 0; i != 11; i++)
        {
            records[i] = 1;
        }
        records[1] = 1;
        for (int i = w - 1; i != -1; --i)
        {
            long long val = 0;
            long long res = 0;
            for (int j = i; j != w; ++j)
            {
                val *= 10;
                val += s[j] - '0';
                if (val > k || val == 0)
                {
                    break;
                }
                res += records[j - i + 1];
                res %= 1000000007;
            }
            for (int k = 10; k != 1; --k)
            {
                records[k] = records[k - 1];
            }
            records[1] = res;
        }
        return records[1];
    }
};
// @lc code=end
