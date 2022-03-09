/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {

        vector<vector<int>> prereq(numCourses);
        for (auto &require : prerequisites)
        {
            prereq[require.front()].push_back(require.back());
        }
        vector<int> pick_record(numCourses, 0);
        vector<int> res;
        for (int i = 0; i != numCourses; ++i)
        {
            if (!pick_record[i])
            {
                if (!nonCyclePick(res, prereq, pick_record, i))
                {
                    return vector<int>();
                }
            }
        }
        return res;

        // vector<vector<int>> prereq(numCourses);
        // vector<int> pick_times(numCourses);
        // for (auto &require : prerequisites)
        // {
        //     prereq[require.front()].push_back(require.back());
        //     ++pick_times[require.back()];
        // }
        // vector<int> res;
        // for (int i = 0; i != numCourses; ++i)
        // {
        //     int j = 0;
        //     for (; j != numCourses; ++j)
        //     {
        //         if (pick_times[j] == 0)
        //         {
        //             res.push_back(j);
        //             break;
        //         }
        //     }
        //     if (j == numCourses)
        //     {
        //         return vector<int>();
        //     }
        //     else
        //     {
        //         --pick_times[j];
        //         for (auto lesson : prereq[j])
        //         {
        //             --pick_times[lesson];
        //         }
        //     }
        // }
        // reverse(res.begin(), res.end());
        // return res;
    }
    bool nonCyclePick(vector<int> &res, vector<vector<int>> &prereq, vector<int> &pick_record, int lesson)
    {
        if (pick_record[lesson] == 1)
        {
            return true;
        }
        if (pick_record[lesson] == 2)
        {
            return false;
        }
        pick_record[lesson] = 2;
        for (auto next_lesson : prereq[lesson])
        {
            if (!nonCyclePick(res, prereq, pick_record, next_lesson))
            {
                return false;
            }
        }
        res.push_back(lesson);
        pick_record[lesson] = 1;
        return true;
    }
};
// @lc code=end
