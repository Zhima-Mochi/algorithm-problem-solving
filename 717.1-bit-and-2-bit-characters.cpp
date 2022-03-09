/*
 * @lc app=leetcode id=717 lang=cpp
 *
 * [717] 1-bit and 2-bit Characters
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isOneBitCharacter(vector<int> &bits)
    {
        if (bits.back() == 1)
        {
            return false;
        }
        int len = bits.size();
        int count = 0;
        for (int i = len - 2; i != -1 && bits[i] == 1; --i)
        {
            ++count;
        }
        return count % 2 == 0;
    }
};
// @lc code=end
