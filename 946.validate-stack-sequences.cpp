/*
 * @lc app=leetcode id=946 lang=cpp
 *
 * [946] Validate Stack Sequences
 */
#include <vector>
using namespace std;
// @lc code=start
// t:O(N), s:O(N)
class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        vector<int> stk;
        int pop_idx = 0;
        for (auto n : pushed)
        {
            stk.push_back(n);
            while (!stk.empty() && stk.back() == popped[pop_idx])
            {
                stk.pop_back();
                ++pop_idx;
            }
        }
        return pop_idx == pushed.size();
    }
};
// @lc code=end
