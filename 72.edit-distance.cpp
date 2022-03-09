/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */
#include <string>
#include <vector>
#include <numeric>
using namespace std;
// @lc code=start
// t:O(len(word1)*len(word2)), s:O(len(word2))
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int w1 = word1.size(), w2 = word2.size();
        if (w1 == 0 && w2 == 0)
        {
            return 0;
        }
        else if (w1 == 0)
        {
            return w2;
        }
        else if (w2 == 0)
        {
            return w1;
        }
        vector<int> record(w2 + 1);
        iota(record.begin(), record.end(), 0);
        for (int i = 0; i != w1; ++i)
        {
            int prev = i;
            record[0] = prev;
            for (int j = 0; j != w2; ++j)
            {
                int next_prev = record[j + 1];
                if (word1[i] == word2[j])
                {
                    record[j + 1] = min({prev, record[j] + 1, record[j + 1] + 1});
                }
                else
                {
                    record[j + 1] = min({prev + 1, record[j] + 1, record[j + 1] + 1});
                }
                prev = next_prev;
            }
        }
        return record.back();
    }
};
// @lc code=end
