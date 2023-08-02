/*
 * @lc app=leetcode id=1981 lang=cpp
 *
 * [1981] Minimize the Difference Between Target and Chosen Elements
 */
#include <vector>
#include <queue>
#include <climits>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minimizeTheDifference(vector<vector<int>> &mat, int target)
    {
        int h = mat.size();
        int w = mat[0].size();
        int max_val = 0;
        vector<int> memo{1};
        for (auto &vec : mat)
        {
            int cur_max = *max_element(vec.begin(), vec.end());
            vector<int> next_memo(max_val + cur_max + 1);
            for (auto v : vec)
            {
                for (int i = v; i <= max_val + v; ++i)
                {
                    next_memo[i] |= memo[i - v];
                }
            }
            memo = move(next_memo);
            max_val += cur_max;
        }
        int res = INT_MAX;
        for (int i = 0; i <= max_val; ++i)
        {
            if (memo[i])
            {
                res = min(res, abs(target - i));
                if (i >= target)
                {
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end
