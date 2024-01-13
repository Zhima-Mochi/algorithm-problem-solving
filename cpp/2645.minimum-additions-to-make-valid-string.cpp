/*
 * @lc app=leetcode id=2645 lang=cpp
 *
 * [2645] Minimum Additions to Make Valid String
 */
#include <string>
using namespace std;
// @lc code=start
// t:O(n), s:O(1)
class Solution
{
public:
    int addMinimum(string word)
    {
        int n = word.size();
        int cur = 0;
        int ans = 0;
        while (cur < n)
        {
            if (cur >= n || word[cur] != 'a')
            {
                ans += 1;
            }
            else
            {
                cur++;
            }
            if (cur >= n || word[cur] != 'b')
            {
                ans += 1;
            }
            else
            {
                cur++;
            }
            if (cur >= n || word[cur] != 'c')
            {
                ans += 1;
            }
            else
            {
                cur++;
            }
        }
        return ans;
    }
};
// @lc code=end
