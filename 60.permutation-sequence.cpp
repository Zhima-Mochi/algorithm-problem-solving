/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
// t:O(n^2), s:O(n)
class Solution
{
    vector<int> perm_count = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

public:
    string getPermutation(int n, int k)
    {
        vector<bool> used(n + 1);
        string res = "";
        for (int i = 1; i <= n; ++i)
        {
            for (int num = 1; num <= n; ++num)
            {
                if (used[num])
                {
                    continue;
                }
                if (k - perm_count[n - i] <= 0)
                {
                    res.push_back('0' + num);
                    used[num] = true;
                    break;
                }
                else
                {
                    k -= perm_count[n - i];
                }
            }
        }
        return res;
    }
};
// @lc code=end
