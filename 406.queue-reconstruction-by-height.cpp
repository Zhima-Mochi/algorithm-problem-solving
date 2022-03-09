/*
 * @lc app=leetcode id=406 lang=cpp
 *
 * [406] Queue Reconstruction by Height
 */
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        sort(people.begin(), people.end(), [](vector<int> &l, vector<int> &r)
             {
                 if (l[0] == r[0])
                 {
                     return l[1] < r[1];
                 }
                 else
                 {
                     return l[0] > r[0];
                 }
             });
        list<vector<int>> res;
        for (auto &vec : people)
        {
            res.insert(next(res.begin(), vec[1]), vec);
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};
// @lc code=end
