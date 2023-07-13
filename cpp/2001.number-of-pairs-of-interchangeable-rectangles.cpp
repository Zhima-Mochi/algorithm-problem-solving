/*
 * @lc app=leetcode id=2001 lang=cpp
 *
 * [2001] Number of Pairs of Interchangeable Rectangles
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
// t:O(n), s:O(n)
class Solution
{
public:
    long long interchangeableRectangles(vector<vector<int>> &rectangles)
    {
        unordered_map<double, long long> cnt;
        for (auto &rec : rectangles)
        {
            cnt[rec[0] * 1.0 / rec[1]]++;
        }
        long long res = 0;
        for (auto &[r, c] : cnt)
        {
            res += c * (c - 1) / 2;
        }
        return res;
    }
};
// @lc code=end
