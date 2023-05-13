/*
 * @lc app=leetcode id=2140 lang=cpp
 *
 * [2140] Solving Questions With Brainpower
 */
#include <vector>
using namespace std;
// @lc code=start
// t:O(n), s:O(n)
using point = long long;
class Solution
{
public:
    long long mostPoints(vector<vector<int>> &questions)
    {

        int w = questions.size();
        vector<point> points(w + 1);
        for (int i = 0; i < w; i++)
        {
            int next = i + questions[i][1] + 1;
            if (next < w)
            {
                points[next] = max(points[next], points[i] + questions[i][0]);
            }
            else
            {
                points[w] = max(points[w], points[i] + questions[i][0]);
            }
            points[i + 1] = max(points[i + 1], points[i]);
        }
        return points[w];
    }
};
// @lc code=end
