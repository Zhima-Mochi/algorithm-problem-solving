/*
 * @lc app=leetcode id=1963 lang=cpp
 *
 * [1963] Minimum Number of Swaps to Make the String Balanced
 */
#include <string>
using namespace std;
// @lc code=start
// t:O(n), s:O(1)
class Solution
{
public:
    int minSwaps(string s)
    {
        int min_cnt = 0;
        int cnt = 0;
        for (auto c : s)
        {
            if (c == '[')
            {
                cnt++;
            }
            else
            {
                cnt--;
                min_cnt = min(min_cnt, cnt);
            }
        }
        return (-min_cnt + 1) / 2;
    }
};
// @lc code=end
