/*
 * @lc app=leetcode id=528 lang=cpp
 *
 * [528] Random Pick with Weight
 */
#include <vector>
#include <random>
using namespace std;
// @lc code=start
class Solution
{
    default_random_engine gen;
    uniform_int_distribution<int> dist;
    vector<int> accum;

public:
    Solution(vector<int> &w)
    {
        int sum_val = 0;
        accum.reserve(w.size());
        for (auto n : w)
        {
            sum_val += n;
            accum.push_back(sum_val);
        }
        dist = uniform_int_distribution(1, sum_val);
    }

    int pickIndex()
    {
        return lower_bound(accum.begin(), accum.end(), dist(gen)) - accum.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end
