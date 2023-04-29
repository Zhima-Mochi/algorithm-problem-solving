/*
 * @lc app=leetcode id=2423 lang=cpp
 *
 * [2423] Remove Letter To Equalize Frequency
 */
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// @lc code=start
// t:O(n), s:O(n)
class Solution
{
public:
    bool equalFrequency(string word)
    {
        unordered_map<char, int> m;

        for (auto c : word)
        {
            m[c]++;
        }
        for (int i = 0; i != 26; i++)
        {
            char c = 'a' + i;
            if (!m.count(c))
            {
                continue;
            }
            unordered_set<int> ss;
            for (auto &[k, v] : m)
            {
                int val = v;
                if (k == c)
                {
                    val -= 1;
                }
                if (val > 0)
                {
                    ss.insert(val);
                    if (ss.size() > 1)
                    {
                        break;
                    }
                }
            }
            if (ss.size() <= 1)
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
