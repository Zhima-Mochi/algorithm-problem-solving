/*
 * @lc app=leetcode id=335 lang=cpp
 *
 * [335] Self Crossing
 */
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <climits>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isSelfCrossing(vector<int> &distance)
    {
        int width = distance.size();
        if (width < 4)
        {
            return false;
        }
        // if (distance[0] >= distance[2] && distance[1] <= distance[3])
        // {
        //     return true;
        // }
        int right_bound = distance[0] >= distance[2] ? distance[1] : INT_MAX;
        int up_bound = distance[1] == distance[3] ? distance[2] - distance[0] : distance[1] > distance[3] ? distance[2]
                                                                                                          : INT_MAX;
        int down_bound = INT_MAX;
        int left_bound = INT_MAX;
        for (int i = 2; i < width; ++i)
        {
            if (i % 4 == 0)
            {
                if (distance[i] >= up_bound)
                {
                    return true;
                }
                else if (i + 2 < width)
                {
                    if (distance[i + 2] < distance[i] - distance[i - 2] || distance[i + 1] < distance[i - 1])
                    {
                        right_bound = distance[i + 1];
                    }
                    else if (distance[i + 2] <= distance[i])
                    {
                        right_bound = distance[i + 1] - distance[i - 1];
                    }
                    else
                    {
                        right_bound = INT_MAX;
                    }
                }
            }
            else if (i % 4 == 1)
            {
                if (distance[i] >= left_bound)
                {
                    return true;
                }
                else if (i + 2 < width)
                {
                    if (distance[i + 2] < distance[i] - distance[i - 2] || distance[i + 1] < distance[i - 1])
                    {
                        up_bound = distance[i + 1];
                    }
                    else if (distance[i + 2] <= distance[i])
                    {
                        up_bound = distance[i + 1] - distance[i - 1];
                    }
                    else
                    {
                        up_bound = INT_MAX;
                    }
                }
            }
            else if (i % 4 == 2)
            {
                if (distance[i] >= down_bound)
                {
                    return true;
                }
                else if (i + 2 < width)
                {
                    if (distance[i + 2] < distance[i] - distance[i - 2] || distance[i + 1] < distance[i - 1])
                    {
                        left_bound = distance[i + 1];
                    }
                    else if (distance[i + 2] <= distance[i])
                    {
                        left_bound = distance[i + 1] - distance[i - 1];
                    }
                    else
                    {
                        left_bound = INT_MAX;
                    }
                }
            }
            else
            {
                if (distance[i] >= right_bound)
                {
                    return true;
                }
                else if (i + 2 < width)
                {
                    if (distance[i + 2] < distance[i] - distance[i - 2] || distance[i + 1] < distance[i - 1])
                    {
                        down_bound = distance[i + 1];
                    }
                    else if (distance[i + 2] <= distance[i])
                    {
                        down_bound = distance[i + 1] - distance[i - 1];
                    }
                    else
                    {
                        down_bound = INT_MAX;
                    }
                }
            }
        }
        return false;
    }
};
// @lc code=end