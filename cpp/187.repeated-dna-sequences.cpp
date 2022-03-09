/*
 * @lc app=leetcode id=187 lang=cpp
 *
 * [187] Repeated DNA Sequences
 */
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        int len = s.size();
        unordered_map<int, short> umap;
        vector<string> res;
        if (len < 11)
        {
            return res;
        }
        int num = 0;
        for (int i = 0; i != 10; ++i)
        {
            num = num << 3 | s[i] & 7;
        }
        ++umap[num];
        for (int i = 10; i != len; ++i)
        {
            num = (num & 0x7FFFFFF) << 3 | s[i] & 7;
            if (++umap[num] == 2)
            {
                res.push_back(s.substr(i - 9, 10));
            }
        }
        return res;
        // int len = s.size();
        // unordered_map<string, short> umap;
        // vector<string> res;
        // for (int i = 0; i < len - 9; ++i)
        // {
        //     auto word = s.substr(i, 10);
        //     if (++umap[word] == 2)
        //     {
        //         res.push_back(word);
        //     }
        // }
        // return res;
    }
};
// @lc code=end
