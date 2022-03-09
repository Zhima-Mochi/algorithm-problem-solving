/*
 * @lc app=leetcode id=986 lang=cpp
 *
 * [986] Interval List Intersections
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList)
    {
        int f_width = firstList.size();
        int s_width = secondList.size();
        int i = 0, j = 0;
        vector<vector<int>> res;
        while (i < f_width && j < s_width)
        {
            if (firstList[i][1] <= secondList[j][1])
            {
                if (firstList[i][1] >= secondList[j][0])
                {
                    res.push_back({max(firstList[i][0], secondList[j][0]), firstList[i][1]});
                }
                ++i;
            }
            else
            {
                if (firstList[i][0] <= secondList[j][1])
                {
                    res.push_back({max(firstList[i][0], secondList[j][0]), secondList[j][1]});
                }
                ++j;
            }
        }
        return res;
    }
};
// @lc code=end
