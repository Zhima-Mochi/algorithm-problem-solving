/*
 * @lc app=leetcode id=1125 lang=cpp
 *
 * [1125] Smallest Sufficient Team
 */
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> smallestSufficientTeam(vector<string> &req_skills, vector<vector<string>> &people)
    {
        int skill_w = req_skills.size();
        int p_w = people.size();
        unordered_map<int, int> people_can;
        unordered_map<string, int> skill_to_idx;
        for (int i = 0; i != skill_w; ++i)
        {
            skill_to_idx[req_skills[i]] = 1 << i;
        }
        for (int i = 0; i != p_w; ++i)
        {
            for (auto &skill : people[i])
            {
                people_can[i] |= skill_to_idx[skill];
            }
        }
        vector<vector<long long>> memo(p_w + 1, vector<long long>(1 << skill_w, -1));
        memo[0][0] = 0;
        for (int j = 1; j != p_w + 1; ++j)
        {
            for (int i = 0; i != 1 << skill_w; ++i)
            {
                if (memo[j - 1][i] == -1)
                {
                    continue;
                }
                if (memo[j][i] == -1)
                {
                    memo[j][i] = memo[j - 1][i];
                }
                else if (__builtin_popcountll(memo[j][i]) > __builtin_popcountll(memo[j - 1][i]))
                {
                    memo[j][i] = memo[j - 1][i];
                }
                if ((i | people_can[j - 1]) == i)
                {
                    continue;
                }
                if (memo[j][i | people_can[j - 1]] == -1)
                {
                    memo[j][i | people_can[j - 1]] = memo[j - 1][i] | (1LL << (j - 1));
                }
                else if (__builtin_popcountll(memo[j][i | people_can[j - 1]]) > __builtin_popcountll(memo[j - 1][i] | (1LL << (j - 1))))
                {
                    memo[j][i | people_can[j - 1]] = memo[j - 1][i] | (1LL << (j - 1));
                }
            }
        }
        vector<int> res;
        for (int i = 0; i != p_w; ++i)
        {
            if (memo[p_w][(1 << skill_w) - 1] & (1LL << i))
            {
                res.push_back(i);
            }
        }
        return res;
    }
};
// @lc code=end
