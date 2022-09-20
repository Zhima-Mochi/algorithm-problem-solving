/*
 * @lc app=leetcode id=1915 lang=cpp
 *
 * [1915] Number of Wonderful Substrings
 */
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    long long wonderfulSubstrings(string word)
    {
        long long res = 0;
        unordered_map<int, long long> records;
        int current = 0;
        records[0] = 1;
        for (auto c : word)
        {
            current ^= 1 << (c - 'a');
            for (int i = 0; i != 10; i++)
            {
                res += records[(1 << i) ^ current];
            }
            res += records[0 ^ current];
            ++records[current];
        }
        return res;
    }
};
// @lc code=end
