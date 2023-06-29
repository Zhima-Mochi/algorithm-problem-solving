/*
 * @lc app=leetcode id=943 lang=cpp
 *
 * [943] Find the Shortest Superstring
 */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
// t:O(n^2∗(2^n+w)), s:O(n^2∗(2^n+w))
class Solution
{
public:
    string shortestSuperstring(vector<string> &words)
    {
        int l = words.size();
        vector<vector<string>> records(1 << l, vector<string>(l));
        vector<vector<int>> overlap(l, vector<int>(l));
        for (int i = 0; i != l; ++i)
        {
            for (int j = 0; j != l; ++j)
            {
                if (i == j)
                {
                    continue;
                }
                int ml = min(words[i].size(), words[j].size());
                while (ml)
                {
                    if (words[i].substr(words[i].size() - ml) == words[j].substr(0, ml))
                    {
                        overlap[i][j] = ml;
                        break;
                    }
                    ml--;
                }
            }
        }
        for (int i = 0; i != l; ++i)
        {
            records[1 << i][i] = words[i];
        }
        for (int j = 1; j != (1 << l); ++j)
        {
            for (int i = 0; i != l; ++i)
            {
                if ((j & (1 << i)) == 0)
                {
                    int next = j | (1 << i);
                    for (int k = 0; k != l; ++k)
                    {
                        if (records[j][k] == "")
                        {
                            continue;
                        }
                        string new_word = records[j][k] + words[i].substr(overlap[k][i]);
                        int m = i;
                        if (new_word.size() >= words[m].size() && new_word.substr(new_word.size() - words[m].size()) == words[m])
                        {
                            if (records[next][m] == "" || records[next][m].size() > new_word.size())
                            {
                                records[next][m] = new_word;
                            }
                        }
                    }
                }
            }
        }
        string res = string(l * 20, 'a');
        for (auto &word : records[(1 << l) - 1])
        {
            if (word != "" && word.size() < res.size())
            {
                res = word;
            }
        }
        return res;
    }
};
// @lc code=end
