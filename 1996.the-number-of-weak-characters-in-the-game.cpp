/*
 * @lc app=leetcode id=1996 lang=cpp
 *
 * [1996] The Number of Weak Characters in the Game
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
// t:O(Nlog(N)), s:O(1)
class Solution
{
public:
    int numberOfWeakCharacters(vector<vector<int>> &properties)
    {
        sort(properties.begin(), properties.end(), [](vector<int> &l, vector<int> &r)
             { return l[0] == r[0] ? l[1] < r[1] : l[0] > r[0]; });
        int current_max = 0;
        int res = 0;
        for (auto &p : properties)
        {
            if (p[1] < current_max)
            {
                ++res;
            }
            else
            {
                current_max = p[1];
            }
        }
        return res;
    }
};
// @lc code=end
