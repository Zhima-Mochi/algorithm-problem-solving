/*
 * @lc app=leetcode id=1040 lang=cpp
 *
 * [1040] Moving Stones Until Consecutive II
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
// t:O(nlog(n)), s:O(1)
class Solution
{
public:
    vector<int> numMovesStonesII(vector<int> &stones)
    {
        sort(stones.begin(), stones.end());
        int w = stones.size();
        int min_move;
        if (stones[w - 1] - stones[0] == w - 1)
        {
            min_move = 0;
        }
        else if (stones[w - 1] - stones[1] == w - 1)
        {
            min_move = 1;
        }
        else if (stones[w - 2] - stones[0] == w - 1)
        {
            min_move = 1;
        }
        else
        {
            int left = 1, right = 1;
            int max_occupy = 0;
            while (left != w - 1)
            {
                while (right + 1 != w - 1 && stones[right + 1] - w < stones[left])
                {
                    ++right;
                }
                max_occupy = max(max_occupy, right - left + 1);
                ++left;
            }
            min_move = w - max_occupy;
        }
        return {min_move, max(stones[w - 2] - stones[0], stones[w - 1] - stones[1]) - 1 - (w - 3)};
    }
};
// @lc code=end
