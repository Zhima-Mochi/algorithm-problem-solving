/*
 * @lc app=leetcode id=854 lang=cpp
 *
 * [854] K-Similar Strings
 */
#include <string>
#include <functional>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    int kSimilarity(string s1, string s2)
    {
        int w = s1.size();

        int res = 0;
        for (int i = 0; i != w; ++i)
        {
            if (s1[i] == s2[i])
            {
                s1[i] = '_';
                s2[i] = '_';
                continue;
            }
            for (int j = i + 1; j != w; ++j)
            {
                if (s1[i] == s2[j] && s1[j] == s2[i])
                {
                    s1[i] = '_';
                    s2[i] = '_';
                    s1[j] = '_';
                    s2[j] = '_';
                    ++res;
                    break;
                }
            }
        }
        string ns1, ns2;
        for (int i = 0; i != w; ++i)
        {
            if (s1[i] != s2[i])
            {
                ns1.push_back(s1[i]);
                ns2.push_back(s2[i]);
            }
        }
        int nw = ns1.size();
        unordered_map<string, int> seen;
        function<int(string &)> dfs = [&](string &word)
        {
            if (word == ns2)
            {
                seen[word] = 0;
                return 0;
            }
            int res = 200;
            seen[word] = res;
            for (int i = 0; i != nw; ++i)
            {
                if (word[i] == ns2[i])
                {
                    continue;
                }
                for (int j = i + 1; j != nw; ++j)
                {
                    if (word[i] != word[j] && word[j] == ns2[i])
                    {
                        swap(word[i], word[j]);
                        if (seen.count(word))
                        {
                            if (seen[word] == 200)
                            {
                                swap(word[i], word[j]);
                                continue;
                            }
                            res = min(res, 1 + seen[word]);
                        }
                        else
                        {
                            res = min(res, 1 + dfs(word));
                        }
                        swap(word[i], word[j]);
                    }
                }
            }
            seen[word] = res;
            return res;
        };
        return res + dfs(ns1);
    }
};
// @lc code=end
