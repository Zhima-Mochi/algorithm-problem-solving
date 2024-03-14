/*
 * @lc app=leetcode id=2086 lang=cpp
 *
 * [2086] Minimum Number of Food Buckets to Feed the Hamsters
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
// t:O(n), s:O(1)
class Solution
{
public:
    int minimumBuckets(string hamsters)
    {
        int n = hamsters.size();
        int ans = 0;
        for (int i = 0; i != n; ++i)
        {
            if (hamsters[i] == 'H')
            {
                if (i > 0 && hamsters[i - 1] == 'O')
                {
                }
                else if (i < n - 1 && hamsters[i + 1] == '.')
                {
                    ans++;
                    hamsters[i + 1] = 'O';
                }
                else if (i > 0 && hamsters[i - 1] == '.')
                {
                    ans += 1;
                    hamsters[i - 1] = 'O'; // not required
                }
                else
                {
                    return -1;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
