/*
 * @lc app=leetcode id=1003 lang=cpp
 *
 * [1003] Check If Word Is Valid After Substitutions
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        vector<pair<string, int>> st;
        s.append("abc");
        int w = s.size();
        if (w < 3)
        {
            return false;
        }
        int i = 0;
        while (i < w - 2)
        {
            if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c')
            {
                i += 3;
            }
            else if (s[i] == 'a' && s[i + 1] == 'b')
            {
                if (st.empty() || st.back().first != "ab")
                {
                    st.push_back({"ab", 1});
                }
                else
                {
                    st.back().second += 1;
                }
                i += 2;
            }
            else if (s[i] == 'a')
            {
                if (st.empty() || st.back().first != "a")
                {
                    st.push_back({"a", 1});
                }
                else
                {
                    st.back().second += 1;
                }
                i += 1;
            }
            else if (s[i] == 'b' && s[i + 1] == 'c')
            {
                if (st.empty() || st.back().first != "a")
                {
                    return false;
                }
                else
                {
                    st.back().second -= 1;
                    if (st.back().second == 0)
                    {
                        st.pop_back();
                    }
                }
                i += 2;
            }
            else if (s[i] == 'b')
            {
                if (st.empty() || st.back().first != "a")
                {
                    return false;
                }
                else
                {
                    st.back().second -= 1;
                    if (st.back().second == 0)
                    {
                        st.pop_back();
                    }
                    st.push_back({"ab", 1});
                }
                i += 1;
            }
            else if (s[i] == 'c')
            {
                if (st.empty() || st.back().first != "ab")
                {
                    return false;
                }
                else
                {
                    st.back().second -= 1;
                    if (st.back().second == 0)
                    {
                        st.pop_back();
                    }
                }
                i += 1;
            }
            else
            {
                return false;
            }
        }
        return st.empty() && i == w;
    }
};
// @lc code=end
