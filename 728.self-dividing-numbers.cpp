/*
 * @lc app=leetcode id=728 lang=cpp
 *
 * [728] Self Dividing Numbers
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> selfDividingNumbers(int left, int right)
    {
        vector<int> res;
        for (int i = left; i < right + 1; ++i)
        {
            int num = i;
            while (num)
            {
                if ((num % 10 == 0) || i % (num % 10) != 0)
                {
                    break;
                }
                num /= 10;
            }
            if (!num)
            {
                res.push_back(i);
                if (i > 10 && 1 % 10 != 1)
                {
                    ++i;
                }
            }
        }
        return res;
    }
};
// @lc code=end
