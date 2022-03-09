/*
 * @lc app=leetcode id=1720 lang=cpp
 *
 * [1720] Decode XORed Array
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> decode(vector<int> &encoded, int first)
    {
        encoded[0] ^= first;
        for (int i = 1, width = encoded.size(); i != width; ++i)
        {
            encoded[i] ^= encoded[i - 1];
        }
        encoded.insert(encoded.begin(), first);
        return encoded;
    }
};
// @lc code=end
