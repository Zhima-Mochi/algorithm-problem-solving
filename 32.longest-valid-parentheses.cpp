/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int res = 0;
        stack<int> st;
        st.push(0);
        for (auto &c : s)
        {
            if (c == '(')
            {
                st.push(0);
            }
            else
            {
                if (st.size() > 1)
                {
                    auto val = st.top() + 2;
                    st.pop();
                    st.top() += val;
                    res = max(res, st.top());
                }
                else
                {
                    st.top() = 0;
                }
            }
        }
        return res;
    }
};
// @lc code=end
