/*
 * @lc app=leetcode id=1200 lang=cpp
 *
 * [1200] Minimum Absolute Difference
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        auto result = vector<vector<int>>();
        int min_val = INT32_MAX;
        int len = arr.size();
        for (int i = 1; i != len; ++i)
        {
            if (arr[i] - arr[i - 1] < min_val)
            {
                min_val = arr[i] - arr[i - 1];
            }
        }
        for (int i = 1; i != len; ++i)
        {
            if (arr[i] - arr[i - 1] == min_val)
            {
                result.push_back({arr[i - 1], arr[i]});
            }
        }
        return result;
    }
};
// @lc code=end
