/*
 * @lc app=leetcode id=301 lang=cpp
 *
 * [301] Remove Invalid Parentheses
 */
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution
{
    int width;
    vector<string> collections;

public:
    vector<string> removeInvalidParentheses(string s)
    {
        width = s.size();
        int left_paran_count = 0;
        int right_paran_count = 0;
        int removed_min_left = 0;
        int removed_min_right = 0;
        for (auto c : s)
        {
            if (c == '(')
            {
                ++left_paran_count;
            }
            else if (c == ')')
            {
                ++right_paran_count;
                if (right_paran_count - removed_min_right > left_paran_count)
                {
                    ++removed_min_right;
                }
            }
        }
        removed_min_left = left_paran_count - (right_paran_count - removed_min_right);
        dfs(s, 0, "", 0, removed_min_left, removed_min_right);
        return collections;
    }
    bool valid_check(string &s)
    {
        int balance_count = 0;
        for (auto c : s)
        {
            if (c == '(')
            {
                ++balance_count;
            }
            else if (c == ')')
            {
                --balance_count;
                if (balance_count < 0)
                {
                    return false;
                }
            }
        }
        return balance_count == 0;
    }
    void dfs(string &s, int pos, string current_word, int current_balance, int removed_min_left, int removed_min_right)
    {
        if (current_balance < 0)
        {
            return;
        }
        if (removed_min_left == 0 && removed_min_right == 0)
        {
            current_word.append(s.substr(pos));
            if (valid_check(current_word))
            {
                collections.push_back(current_word);
            }
            return;
        }
        if (pos == width)
        {
            return;
        }
        if (width - pos < removed_min_left + removed_min_right)
        {
            return;
        }
        while (pos != width && s[pos] != '(' && s[pos] != ')')
        {
            current_word.push_back(s[pos++]);
        }
        if (pos == width)
        {
            return;
        }
        if (s[pos] == '(' && removed_min_left > 0)
        {
            dfs(s, pos + 1, current_word, current_balance, removed_min_left - 1, removed_min_right);
        }
        else if (s[pos] == ')' && removed_min_right > 0)
        {
            dfs(s, pos + 1, current_word, current_balance, removed_min_left, removed_min_right - 1);
        }
        current_word += s[pos];
        if (s[pos] == '(')
        {
            current_balance += 1;
        }
        else
        {
            current_balance -= 1;
        }
        pos += 1;
        while (pos != width and s[pos] == s[pos - 1])
        {
            current_word += s[pos];
            if (s[pos] == '(')
            {
                current_balance += 1;
            }
            else
            {
                current_balance -= 1;
            }
            pos += 1;
        }
        dfs(s, pos, current_word, current_balance,
            removed_min_left, removed_min_right);
    }
};
// @lc code=end
