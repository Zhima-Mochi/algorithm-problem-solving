/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 */
#include <string>
#include <vector>
#include <stack>
using namespace std;
// @lc code=start
class Solution
{
public:
    int calculate(string s)
    {
        auto len = s.size();
        size_t pos = s.find_first_of("+-*/");
        vector<int> st;
        st.push_back(stoi(s.substr(0, pos)));
        if (pos == -1)
        {
            return st[0];
        }
        while (pos != len)
        {
            auto next_pos = pos + 1;
            while (next_pos != len && s[next_pos] == ' ')
            {
                ++next_pos;
            }
            int val = 0;
            while (next_pos != len && isdigit(s[next_pos]))
            {
                val *= 10;
                val += s[next_pos] - '0';
                ++next_pos;
            }
            while (next_pos != len && s[next_pos] == ' ')
            {
                ++next_pos;
            }

            switch (s[pos])
            {
            case '*':
                st.back() *= val;
                break;
            case '/':
                st.back() /= val;
                break;
            case '-':
                if (st.size() == 2)
                {
                    st[0] += st[1];
                    st[1] = -val;
                }
                else
                {
                    st.push_back(-val);
                }
                break;
            case '+':
                if (st.size() == 2)
                {
                    st[0] += st[1];
                    st[1] = val;
                }
                else
                {
                    st.push_back(val);
                }
                break;
            }
            pos = next_pos;
        }
        if (st.size() == 2)
        {
            st[0] += st[1];
        }
        return st[0];
    }
};
// @lc code=end
