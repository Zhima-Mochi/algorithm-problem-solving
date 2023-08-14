/*
 * @lc app=leetcode id=2698 lang=cpp
 *
 * [2698] Find the Punishment Number of an Integer
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
// t:O(n^2) s:O(n)
class Solution
{
    vector<int> memo = {0};

public:
    int punishmentNumber(int n)
    {
        int w = memo.size();
        while (w < n + 1)
        {
            if (IsPunishMent(w))
            {
                memo.push_back(memo.back() + w * w);
            }
            else
            {
                memo.push_back(memo.back());
            }
            w++;
        }
        return memo[n];
    }

    bool IsPunishMent(int n)
    {
        string n_str = to_string(n * n);
        return dfs(n_str, 0, n);
    }
    bool dfs(string &word, int pos, int goal)
    {
        int w = word.size();
        int val = 0;
        for (int i = pos; i != w; ++i)
        {
            val *= 10;
            val += word[i] - '0';
            if (val > goal)
            {
                return false;
            }
            if (dfs(word, i + 1, goal - val))
            {
                return true;
            }
        }
        return val == goal;
    }
};
// @lc code=end
