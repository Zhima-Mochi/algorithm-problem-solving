/*
 * @lc app=leetcode id=2139 lang=cpp
 *
 * [2139] Minimum Moves to Reach Target Score
 */
using namespace std;
// @lc code=start
// t:O(maxDoubles), s:O(1)
class Solution
{
public:
    int minMoves(int target, int maxDoubles)
    {
        int ans = 0;
        while (target > 1)
        {
            if (maxDoubles)
            {
                maxDoubles -= 1;
                if (target % 2)
                {
                    ans += 1;
                }
                ans += 1;
                target /= 2;
            }
            else
            {
                return ans + (target - 1);
            }
        }
        return ans;
    }
};
// @lc code=end
