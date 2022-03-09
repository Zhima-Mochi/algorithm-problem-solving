/*
 * @lc app=leetcode id=957 lang=cpp
 *
 * [957] Prison Cells After N Days
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> prisonAfterNDays(vector<int> &cells, int n)
    {
        unordered_map<int, int> status_day;
        unordered_map<int, int> day_status;
        int day = 0;
        int status = 0;
        for (auto n : cells)
        {
            status <<= 1;
            status |= n;
        }
        status_day[status] = 0;
        day_status[0] = status;
        while (day++ < n)
        {
            int next_status = 0;
            for (int i = 1; i != 7; ++i)
            {
                if (!((status >> i - 1) & 1) ^ ((status >> i + 1) & 1))
                {
                    next_status |= 1 << i;
                }
            }
            status = move(next_status);
            if (status_day.count(status))
            {
                return transform(day_status[(n - status_day[status]) % (day - status_day[status])+ status_day[status]]);
            }
            else
            {
                status_day[status] = day;
                day_status[day] = status;
            }
        }
        return transform(status);
    }
    vector<int> transform(int status)
    {
        vector<int> res(8);
        for (int i = 0; i != 8; ++i)
        {
            res[i] = (status >> 7 - i) & 1;
        }
        return res;
    }
};
// @lc code=end
