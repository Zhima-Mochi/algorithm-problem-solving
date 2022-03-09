/*
 * @lc app=leetcode id=1619 lang=cpp
 *
 * [1619] Mean of Array After Removing Some Elements
 */
#include <vector>
#include <queue>
using namespace std;
// @lc code=start
class Solution
{
public:
    double trimMean(vector<int> &arr)
    {
        int width = arr.size();
        int prop_5 = width * 0.05;
        priority_queue<int> largest;
        priority_queue<int, vector<int>, greater<int>> smallest;
        double sum_val = 0;
        for (auto n : arr)
        {
            sum_val += n;
            largest.push(n);
            smallest.push(n);
            if (largest.size() > prop_5)
            {
                largest.pop();
            }
            if (smallest.size() > prop_5)
            {
                smallest.pop();
            }
        }
        while (!largest.empty())
        {
            sum_val -= largest.top();
            largest.pop();
        }
        while (!smallest.empty())
        {
            sum_val -= smallest.top();
            smallest.pop();
        }
        return sum_val / (width - prop_5 * 2);
    }
};
// @lc code=end
