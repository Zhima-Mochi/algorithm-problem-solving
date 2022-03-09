/*
 * @lc app=leetcode id=1128 lang=cpp
 *
 * [1128] Number of Equivalent Domino Pairs
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes)
    {
        unordered_map<int, int> same_count;
        int res = 0;
        for (auto &vec : dominoes)
        {
            sort(vec.begin(), vec.end());
            ++same_count[(vec[0] << 20) + vec[1]];
        }
        for (auto &pr : same_count)
        {
            res += pr.second * (pr.second - 1) / 2;
        }
        return res;
    }
};
// @lc code=end

// class Solution
// {
// public:
//     int numEquivDominoPairs(vector<vector<int>> &dominoes)
//     {
//         auto len = dominoes.size();
//         vector<bool> has_used(len);
//         int res = 0;
//         for (auto i = 0; i != len - 1; ++i)
//         {
//             if (has_used[i])
//             {
//                 continue;
//             }

//             has_used[i] = true;
//             auto same_sum = 1;
//             for (auto j = i + 1; j != len; ++j)
//             {
//                 if (dominoes[i] == dominoes[j] || dominoes[i][0] == dominoes[j][1] && dominoes[i][1] == dominoes[j][0])
//                 {
//                     has_used[j] = true;
//                     ++same_sum;
//                 }
//             }
//             res += (same_sum) * (same_sum - 1) / 2;
//         }
//         return res;
//     }
// };