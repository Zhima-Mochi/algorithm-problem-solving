/*
 * @lc app=leetcode id=630 lang=cpp
 *
 * [630] Course Schedule III
 */
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int scheduleCourse(vector<vector<int>> &courses)
    {
        sort(courses.begin(), courses.end(), [](vector<int> &l, vector<int> &r)
             { return l[1] < r[1]; });
        int total_time = 0;
        priority_queue<int> pq;
        for (auto &&course : courses)
        {
            if (total_time + course[0] <= course[1])
            {
                total_time += course[0];
                pq.push(course[0]);
            }
            else
            {
                if (!pq.empty() && pq.top() > course[0])
                {
                    total_time -= pq.top();
                    pq.pop();
                    total_time += course[0];
                    pq.push(course[0]);
                }
            }
        }
        return pq.size();
    }
};
// @lc code=end
