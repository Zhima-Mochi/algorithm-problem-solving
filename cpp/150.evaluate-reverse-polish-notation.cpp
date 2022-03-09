/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */
#include <stack>
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;
        for (auto &s : tokens)
        {
            if (s == "*")
            {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(a * b);
            }
            else if (s == "+")
            {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(a + b);
            }
            else if (s == "-")
            {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(a - b);
            }
            else if (s == "/")
            {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(a / b);
            }
            else
            {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};
// @lc code=end
