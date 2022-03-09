/*
 * @lc app=leetcode id=2080 lang=cpp
 *
 * [2080] Range Frequency Queries
 */
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
// @lc code=start
class RangeFreqQuery
{
public:
    unordered_map<int, vector<int>> um;
    RangeFreqQuery(vector<int> &arr)
    {
        int idx = 0;
        for (auto n : arr)
        {
            um[n].push_back(idx++);
        }
    }

    int query(int left, int right, int value)
    {
        if (!um.count(value))
        {
            return 0;
        }
        auto &arr = um[value];
        return upper_bound(arr.begin(), arr.end(), right) - lower_bound(arr.begin(), arr.end(), left);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
// @lc code=end
