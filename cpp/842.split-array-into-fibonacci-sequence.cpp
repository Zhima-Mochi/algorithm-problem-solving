/*
 * @lc app=leetcode id=842 lang=cpp
 *
 * [842] Split Array into Fibonacci Sequence
 */
#include <string>
#include <vector>
#include <climits>
using namespace std;
// @lc code=start
// t:O(len(num)*log^2(INT_MAX)), s:O(len(num))
class Solution
{
    vector<int> res;

public:
    vector<int> splitIntoFibonacci(string num)
    {
        int w = num.size();
        helpler(num, w - 1, -1, -1);
        if (res.size() > 2)
        {
            return res;
        }
        else
        {
            return {};
        }
    }
    bool helpler(string &num, int end, int next, int next_next)
    {
        if (end < 0)
        {
            return true;
        }
        long long val = 0;
        long long mul = 1;
        for (int i = end; i != -1; --i)
        {
            val += (num[i] - '0') * mul;
            mul *= 10;
            if (val > INT_MAX)
            {
                return false;
            }
            if (num[i] == '0' && val != 0)
            {
                continue;
            }
            if (next_next != -1)
            {
                if (val + next > next_next)
                {
                    return false;
                }
                else if (val + next == next_next && helpler(num, i - 1, val, next))
                {
                    res.push_back(val);
                    return true;
                }
            }
            else
            {
                if (next != -1)
                {
                    if (val > next)
                    {
                        return false;
                    }
                    if (helpler(num, i - 1, val, next))
                    {
                        res.push_back(val);
                        return true;
                    }
                }
                else
                {
                    if (i > 0 && helpler(num, i - 1, val, -1))
                    {
                        res.push_back(val);
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
// @lc code=end
