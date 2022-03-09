/*
 * @lc app=leetcode id=1528 lang=cpp
 *
 * [1528] Shuffle String
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    string restoreString(string s, vector<int> &indices)
    {
        int width = s.size();
        int pos = 0;
        while (pos != width)
        {
            if (indices[pos] == pos)
            {
                ++pos;
            }
            else
            {
                swap(s[pos], s[indices[pos]]);
                swap(indices[pos], indices[indices[pos]]);
            }
        }
        return s;
    }
};
// @lc code=end
