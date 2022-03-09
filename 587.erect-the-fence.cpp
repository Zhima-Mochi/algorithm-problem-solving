/*
 * @lc app=leetcode id=587 lang=cpp
 *
 * [587] Erect the Fence
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
    using position = vector<int>;
    int distanceSquare(const vector<int> &vec)
    {
        return vec[0] * vec[0] + vec[1] * vec[1];
    }
    short change(const position &o, const position &l, const position &r)
    {
        vector<int> vec1 = {l[0] - o[0], l[1] - o[1]};
        vector<int> vec2 = {r[0] - o[0], r[1] - o[1]};
        int cross = vec1[0] * vec2[1] - vec1[1] * vec2[0];
        if (cross < 0)
        {
            return 1;
        }
        else if (cross == 0)
        {
            return distanceSquare(vec2) > distanceSquare(vec1) ? 2 : 3;
        }
        else
        {
            return 0;
        }
    }

public:
    vector<vector<int>> outerTrees(vector<vector<int>> &trees)
    {
        if (trees.size() == 1)
        {
            return trees;
        }
        const position *start = &trees[0];
        vector<vector<int>> res;
        res.reserve(trees.size());
        for (const auto &v : trees)
        {
            if (v < *start)
            {
                start = &v;
            }
        }
        res.push_back(*start);
        const position *prev = nullptr;
        while (true)
        {
            const position *target = nullptr;
            const position &origin = res.back();
            vector<position> onLine;
            for (const auto &v : trees)
            {
                if (v == origin)
                {
                    continue;
                }
                if (target == nullptr)
                {
                    target = &v;
                    continue;
                }
                short changeType = change(origin, *target, v);

                if (changeType == 1)
                {
                    target = &v;
                    onLine.clear();
                }
                else if (changeType == 2)
                {
                    onLine.push_back(*target);
                    target = &v;
                }
                else if (changeType == 3)
                {
                    onLine.push_back(v);
                }
            }
            if (!prev || *target != *prev)
            {
                for (const auto &p : onLine)
                {
                    res.push_back(p);
                }
            }
            if (*target == res.front())
            {
                break;
            }
            else
            {

                res.push_back(*target);
            }
            prev = &origin;
        }
        return res;
    }
};
// @lc code=end
