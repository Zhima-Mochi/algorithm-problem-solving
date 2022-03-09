/*
 * @lc app=leetcode id=503 lang=cpp
 *
 * [503] Next Greater Element II
 */
#include <vector>
#include <stack>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        stack<pair<int, int>> st;
        int len = nums.size();
        vector<int> res(len, -1);
        for (int i = 0; i != len; ++i)
        {
            while (!st.empty() && st.top().second < nums[i])
            {
                res[st.top().first] = nums[i];
                st.pop();
            }
            st.push({i, nums[i]});
        }
        for (int i = 0; i != len; ++i)
        {
            while (!st.empty() && st.top().second < nums[i])
            {
                res[st.top().first] = nums[i];
                st.pop();
            }
            if (st.top().first <= i)
            {
                break;
            }
        }
        return res;
    }
};
// @lc code=end
