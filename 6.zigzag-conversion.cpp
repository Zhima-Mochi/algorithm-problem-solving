/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
// t:O(len(s)), s:O(len(s))
class Solution
{
public:
    string convert(string s, int numRows)
    {
        int w = s.size();
        if (numRows == 1 || numRows >= w)
        {
            return s;
        }
        vector<int> row_pos;
        int pos = 0;
        bool up = true;
        for (auto c : s)
        {
            row_pos.push_back(pos);
            if (up)
            {
                ++pos;
            }
            else
            {
                --pos;
            }
            if (pos == -1)
            {
                up = true;
                pos = 1;
            }
            else if (pos == numRows)
            {
                up = false;
                pos = numRows - 2;
            }
        }
        vector<string> res_vec(numRows);
        for (int i = 0; i != w; ++i)
        {
            res_vec[row_pos[i]].push_back(s[i]);
        }
        string res = res_vec[0];
        for (int i = 1; i < numRows; ++i)
        {
            res += res_vec[i];
        }
        return res;
    }
};
// @lc code=end
