/*
 * @lc app=leetcode id=1048 lang=cpp
 *
 * [1048] Longest String Chain
 */
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
// t:O(Nlog(N)), s:O(N) (neglect len of each word)
class Solution
{
public:
    int longestStrChain(vector<string> &words)
    {
        sort(words.begin(), words.end(), [](string &l, string &r)
             { return l.size() < r.size(); });
        int w = words.size();
        vector<int> dp(w, 1);
        int min_len = words.front().size();
        int left_cur = 0;
        int right_cur = 0;
        while (right_cur != w && words[right_cur].size() == min_len)
        {
            ++right_cur;
        }
        int res = 1;
        while (right_cur != w)
        {
            int current_len = words[right_cur].size();
            int prev_len = words[left_cur].size();
            int next_cur = right_cur + 1;
            while (next_cur != w && words[next_cur].size() == current_len)
            {
                ++next_cur;
            }
            if (current_len == prev_len + 1)
            {
                for (int i = right_cur; i != next_cur; ++i)
                {
                    for (int j = left_cur; j != right_cur; ++j)
                    {
                        if (is_sub(words[i], words[j]))
                        {
                            dp[i] = max(dp[i], dp[j] + 1);
                        }
                    }
                    res = max(res, dp[i]);
                }
            }
            left_cur = right_cur;
            right_cur = next_cur;
        }
        return res;
    }
    bool is_sub(string &l, string &r)
    {
        int idx = 0;
        for (auto c : r)
        {
            idx = l.find(c, idx);
            if (idx == -1)
            {
                break;
            }
            else
            {
                idx = idx + 1;
            }
        }
        return idx != -1;
    }
};
// @lc code=end
