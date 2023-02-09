/*
 * @lc app=leetcode id=2306 lang=cpp
 *
 * [2306] Naming a Company
 */
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    long long distinctNames(vector<string> &ideas)
    {
        long long res = 0;
        unordered_map<string, int> records;
        for (auto &idea : ideas)
        {
            auto tail = idea.substr(1);
            records[tail] |= 1 << (idea[0] - 'a');
        }
        vector<vector<int>> cnt(26, vector<int>(26));
        for (auto &[tail, record] : records)
        {
            auto val = record;
            vector<int> unique_word;
            for (int i = 0; i != 26; ++i)
            {
                if (((1 << i) & record) != 0)
                {
                    unique_word.push_back(i);
                }
            }
            for (int i = 0; i != 26; ++i)
            {
                if (((1 << i) & record) == 0)
                {
                    for (auto w : unique_word)
                    {
                        cnt[i][w] += 1;
                    }
                }
            }
        }
        for (auto &idea : ideas)
        {
            auto tail = idea.substr(1);
            for (int i = 0; i != 26; ++i)
            {
                if ((records[tail] & (1 << i)) == 0)
                {
                    res += cnt[idea[0] - 'a'][i];
                }
            }
        }
        return res;
    }
};
// @lc code=end
