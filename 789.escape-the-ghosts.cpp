/*
 * @lc app=leetcode id=789 lang=cpp
 *
 * [789] Escape The Ghosts
 */
#include <vector>
#include <queue>
using namespace std;
// @lc code=start
class Solution
{
    int distance(vector<int> &l, vector<int> &r)
    {
        return abs(l[0] - r[0]) + abs(l[1] - r[1]);
    }
    bool check(vector<int> pos, vector<vector<int>> &ghosts)
    {
        for (auto &&ghost : ghosts)
        {
            if (distance(ghost, pos) <= abs(pos[0]) + abs(pos[1]))
            {
                return false;
            }
        }
        return true;
    }

public:
    bool escapeGhosts(vector<vector<int>> &ghosts, vector<int> &target)
    {
        auto comp = [](vector<int> &l, vector<int> &r)
        {
            return abs(l[0]) + abs(l[1]) > abs(r[0]) + abs(r[1]);
        };
        return check(target, ghosts);
    }
};
// @lc code=end
