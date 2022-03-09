/*
 * @lc app=leetcode id=1652 lang=cpp
 *
 * [1652] Defuse the Bomb
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> decrypt(vector<int> &code, int k)
    {
        int width = code.size();
        if (k == 0)
        {
            return vector<int>(width);
        }
        vector<int> res;
        int val = 0;
        if (k < 0)
        {
            for (int i = 0; i != k; --i)
            {
                val += code[width - 1 + i];
            }
            for (int i = 0; i != width; ++i)
            {
                res.push_back(val);
                val -= code[(i + k + width) % width];
                val += code[i];
            }
        }
        else
        {
            for (int i = 0; i != k; ++i)
            {
                val += code[1 + i];
            }
            for (int i = 0; i != width; ++i)
            {
                res.push_back(val);
                val -= code[(i + 1) % width];
                val += code[(i + 1 + k) % width];
            }
        }
        return res;
    }
};
// @lc code=end
