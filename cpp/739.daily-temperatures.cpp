/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> index_stack;
        int width = temperatures.size();
        vector<int> res(width);
        for (int i = 0; i != width; ++i)
        {
            while (!index_stack.empty() && temperatures[i] > temperatures[index_stack.back()])
            {
                res[index_stack.back()] = i - index_stack.back();
                index_stack.pop_back();
            }
            index_stack.push_back(i);
        }
        return res;
    }
};
// @lc code=end
