/*
 * @lc app=leetcode id=1239 lang=cpp
 *
 * [1239] Maximum Length of a Concatenated String with Unique Characters
 */
#include <vector>
#include <string>
#include <bitset>
#include <set>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
    int vec_len;
public:
    int maxLength(vector<string> &arr)
    {
        vector<bitset<26>> v;
        for (auto &s : arr)
        {
            if (!wordToInt(s).none())
            {
                v.push_back(wordToInt(s));
            }
        }
        int res = 0;
        vec_len=v.size();
        dfs(res, v, bitset<26>(), 0);
        return res;
    }
    void dfs(int &res, vector<bitset<26>> &vec, bitset<26> current, int pos)
    {
        res = max(res, static_cast<int>(current.count()));
        if (pos == vec_len)
        {
            return;
        }
        for (int i = pos; i != vec_len; ++i)
        {
            if (!(current & vec[i]).any())
            {
                dfs(res, vec, current | vec[i], i + 1);
            }
        }
    }
    bitset<26> wordToInt(string &s)
    {
        bitset<26> res;
        for (auto c : s)
        {
            if (!res.test(c - 'a'))
            {
                res.set(c - 'a');
            }
            else
            {
                return bitset<26>();
            }
        }
        return res;
    }
};
// @lc code=end
