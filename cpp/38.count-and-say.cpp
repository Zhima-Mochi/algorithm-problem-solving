/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */
#include <string>
#include <vector>
#include <stack>
using namespace std;
// @lc code=start
class Solution
{
    static vector<string> sol_arr;
    void generate_sol_arr(int n)
    {
        auto sol_arr_len = sol_arr.size();
        if (sol_arr_len >= n)
        {
            return;
        }
        for (int i = sol_arr_len; i != n; i++)
        {
            vector<char> collect;
            int count = 0;
            string s;
            auto arr = sol_arr.back();
            auto arr_len = arr.size();

            for (int i = 0; i != arr_len; i++)
            {
                if (collect.empty())
                {
                    collect.push_back(arr[i]);
                    count++;
                }
                else if (arr[i] == collect.back())
                {
                    count++;
                }
                else
                {
                    s.push_back(count + '0');
                    s.push_back(collect.back());
                    collect[0]=arr[i];
                    count = 1;
                }
            }
            s.push_back(count + '0');
            s.push_back(collect.back());
            sol_arr.push_back(s);
        }
        return;
    }

public:
    string countAndSay(int n)
    {
        generate_sol_arr(n);
        return sol_arr[n - 1];
    }
};
vector<string> Solution::sol_arr = {"1"};

// @lc code=end
vector<string> sol_arr;
int main()
{
    sol_arr.push_back("1");
    for (int i = 1; i != 30; i++)
    {
        stack<char> collect;
        string s;
        auto arr = sol_arr[i - 1];
        auto arr_len = arr.size();

        for (int i = 0; i != arr_len; i++)
        {
            if (collect.empty() || arr[i] == collect.top())
            {
                collect.push(arr[i]);
            }
            else
            {
                s.push_back(collect.size() + '0');
                s.push_back(collect.top());
                collect = stack<char>();
                collect.push(arr[i]);
            }
        }
        s.push_back(collect.size() + '0');
        s.push_back(collect.top());
        sol_arr.push_back(s);
    }
}