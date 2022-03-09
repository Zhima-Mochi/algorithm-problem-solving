/*
 * @lc app=leetcode id=989 lang=cpp
 *
 * [989] Add to Array-Form of Integer
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> addToArrayForm(vector<int> &num, int k)
    {
        reverse(num.begin(), num.end());
        for (auto &n : num)
        {
            n += k % 10;
            k /= 10;
            if (n > 9)
            {
                n -= 10;
                ++k;
            }
            if (k == 0)
            {
                break;
            }
        }
        while (k)
        {
            num.push_back(k % 10);
            k /= 10;
        }
        reverse(num.begin(), num.end());
        return num;
    }
};
// @lc code=end
