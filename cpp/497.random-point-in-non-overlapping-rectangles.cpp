/*
 * @lc app=leetcode id=497 lang=cpp
 *
 * [497] Random Point in Non-overlapping Rectangles
 */
#include <vector>
#include <random>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> _rects;
    vector<int> accum;
    default_random_engine gen;
    uniform_int_distribution<int> distribution;
    Solution(vector<vector<int>> &rects)
    {
        _rects = rects;
        int total_points = 0;
        for (auto &vec : rects)
        {
            total_points += (vec[2] - vec[0] + 1) * (vec[3] - vec[1] + 1);
            accum.push_back(total_points);
        }
        distribution = uniform_int_distribution<int>(1, total_points);
    }

    vector<int> pick()
    {
        int points = distribution(gen);
        int pos = lower_bound(accum.begin(), accum.end(), points) - accum.begin();
        if (pos > 0)
        {
            points -= accum[pos - 1] + 1;
        }
        else
        {
            points -= 1;
        }
        return {_rects[pos][0] + points / (_rects[pos][3] - _rects[pos][1] + 1), _rects[pos][1] + points % (_rects[pos][3] - _rects[pos][1] + 1)};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
// @lc code=end
