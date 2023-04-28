/*
 * @lc app=leetcode id=2418 lang=cpp
 *
 * [2418] Sort the People
 */
#include <string>
#include <vector>
#include <numeric>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        int w = names.size();
        vector<int> indices(w);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int i, int j)
             { return heights[i] > heights[j]; });
        vector<string> result(w);
        for (int i = 0; i < w; i++)
        {
            result[i] = names[indices[i]];
        }
        return result;
    }
};
// @lc code=end
