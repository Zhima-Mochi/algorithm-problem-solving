/*
 * @lc app=leetcode id=2284 lang=cpp
 *
 * [2284] Sender With Largest Word Count
 */
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    string largestWordCount(vector<string> &messages, vector<string> &senders)
    {
        int w = messages.size();
        unordered_map<string, int> um;
        for (int i = 0; i != w; ++i)
        {
            messages[i].push_back(' ');
            um[senders[i]] += count(messages[i].begin(), messages[i].end(), ' ');
        }
        string res;
        int word_cnt = -1;
        for (auto &[name, cnt] : um)
        {
            if (cnt > word_cnt)
            {
                res = name;
                word_cnt = cnt;
            }
            else if (cnt == word_cnt)
            {
                if (name > res)
                {
                    res = name;
                }
            }
        }
        return res;
    }
};
// @lc code=end
