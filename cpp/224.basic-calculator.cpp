/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
#define original true
#if original
class Solution
{
public:
    int calculate(string s)
    {
        vector<bool> sign_st;
        sign_st.push_back(true);
        bool sign = true;
        int val = 0;
        int res = 0;
        for (auto c : s)
        {
            if (isdigit(c))
            {
                val *= 10;
                val += c - '0';
            }
            else if (c == '+' || c == '-')
            {
                res += (sign ? 1 : -1) * val;
                val = 0;
                sign = c == '+' ? sign_st.back() : !sign_st.back();
            }
            else if (c == '(')
            {
                sign_st.push_back(sign);
            }
            else if (c == ')')
            {
                sign_st.pop_back();
            }
        }
        return res + (sign ? 1 : -1) * val;
    }
};
#else
class Solution
{
public:
    int calculate(string s)
    {
        vector<pair<int, int>> num_st = {{0, 0}};
        vector<char> operator_st;
        int pos = 0;
        int len = s.size();
        while (pos != len)
        {
            if (s[pos] == '(')
            {
                num_st.push_back({0, 0});
                while (operator_st.size() < num_st.size())
                {
                    operator_st.push_back('+');
                }
            }
            else if (isdigit(s[pos]) || s[pos] == ')')
            {
                int val;
                if (s[pos] != ')')
                {
                    val = s[pos] - '0';
                    while (pos != len - 1 && isdigit(s[pos + 1]))
                    {
                        ++pos;
                        val *= 10;
                        val += s[pos] - '0';
                    }
                }
                else
                {
                    val = num_st.back().first + num_st.back().second;
                    num_st.pop_back();
                }

                if (operator_st.empty())
                {
                    operator_st.push_back('+');
                }
                switch (operator_st.back())
                {
                case '+':
                    num_st.back().first += num_st.back().second;
                    num_st.back().second = val;
                    break;
                case '-':
                    num_st.back().first += num_st.back().second;
                    num_st.back().second = -val;
                    break;
                case '*':
                    num_st.back().second *= val;
                    break;
                case '/':
                    num_st.back().second /= val;
                    break;
                default:
                    break;
                }
                operator_st.pop_back();
            }
            else if (!isblank(s[pos]))
            {
                operator_st.push_back(s[pos]);
            }
            ++pos;
        }
        while (num_st.size() > 1)
        {
            int val = num_st.back().first + num_st.back().second;
            num_st.pop_back();

            switch (operator_st.back())
            {
            case '+':
                num_st.back().first += num_st.back().second;
                num_st.back().second = val;
                break;
            case '-':
                num_st.back().first += num_st.back().second;
                num_st.back().second = -val;
                break;
            case '*':
                num_st.back().second *= val;
                break;
            case '/':
                num_st.back().second /= val;
                break;
            default:
                break;
            }
            operator_st.pop_back();
        }
        return num_st.front().first + num_st.front().second;
    }
};
#endif
// @lc code=end
