/*
 * @lc app=leetcode id=997 lang=cpp
 *
 * [997] Find the Town Judge
 */
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        unordered_map<short, short> beTrusted;
        unordered_set<short> nonJudge;
        vector<short> candidate;
        for (auto &vec : trust)
        {
            ++beTrusted[vec[1]];
            if (beTrusted[vec[1]] == n - 1)
            {
                candidate.push_back(vec[1]);
            }
            nonJudge.insert(vec[0]);
        }
        if (n == 1 && !nonJudge.count(1))
        {
            return 1;
        }
        for (auto &n : candidate)
        {
            if (!nonJudge.count(n))
            {
                return n;
            }
        }
        return -1;
    }
};
// @lc code=end
