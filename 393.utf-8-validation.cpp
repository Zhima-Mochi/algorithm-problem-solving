/*
 * @lc app=leetcode id=393 lang=cpp
 *
 * [393] UTF-8 Validation
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
    int eigthBit = 1 << 7;

public:
    bool validUtf8(vector<int> &data)
    {
        int neededOneZeroCount = 0;
        for (auto val : data)
        {
            if (neededOneZeroCount)
            {
                if (!validOneZero(val))
                {
                    return false;
                }
                else
                {
                    --neededOneZeroCount;
                }
            }
            else if (val & eigthBit)
            {
                int num = numOfOne(val);
                if (val > 0)
                {
                    neededOneZeroCount += num - 1;
                }
                else
                {
                    return false;
                }
            }
        }
        return neededOneZeroCount == 0;
    }
    short numOfOne(const int &val)
    {
        short count = 0;
        int b = (1 << 7);
        while (val & b)
        {
            b >>= 1;
            ++count;
        }
        return count > 4 || count == 1 ? -1 : count;
    }
    bool validOneZero(const int &val)
    {
        return (val & (1 << 7)) && !(val & (1 << 6));
    }
};
// @lc code=end
