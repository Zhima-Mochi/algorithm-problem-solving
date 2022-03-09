/*
 * @lc app=leetcode id=2029 lang=cpp
 *
 * [2029] Stone Game IX
 */
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <numeric>
using namespace std;
// @lc code=start
// t:O(N), s:O(1)
class Solution
{
public:
    bool stoneGameIX(vector<int> &stones)
    {
        vector<int> mod_cnt(3);
        for (auto stn : stones)
        {
            ++mod_cnt[stn % 3];
        }
        mod_cnt[0] = mod_cnt[0] % 2;
        if (mod_cnt[0] == 1)
        {
            return abs(mod_cnt[1] - mod_cnt[2]) > 2;
        }
        else
        {
            return mod_cnt[1] >= 1 && mod_cnt[2] >= 1;
        }
    }
};
// @lc code=end