/*
 * @lc app=leetcode id=403 lang=cpp
 *
 * [403] Frog Jump
 */
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// @lc code=start
// t:O(n^2) s:O(n^2)
class Solution
{
public:
    bool canCross(vector<int> &stones)
    {
        int w = stones.size();
        unordered_map<int, unordered_set<int>> memo;
        memo[0].insert(0);
        for (int i = 0; i != w; ++i)
        {
            for (auto pt : memo[stones[i]])
            {
                memo[stones[i] + pt + 1].insert(pt + 1);
                if (pt > 0)
                {
                    memo[stones[i] + pt].insert(pt);
                }
                if (pt > 1)
                {
                    memo[stones[i] + pt - 1].insert(pt - 1);
                }
            }
        }
        return !memo[stones[w - 1]].empty();
    }
};
// @lc code=end
