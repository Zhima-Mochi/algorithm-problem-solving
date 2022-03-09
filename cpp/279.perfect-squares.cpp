/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int numSquares(int n)
    {
        int count = 0;
        queue<int> q;
        q.push(n);
        while (count < 4)
        {
            ++count;
            int q_len = q.size();
            while (q_len--)
            {
                int val = q.front();
                q.pop();
                int sqrt_val = sqrt(val);
                for (int i = sqrt_val; i != 0; --i)
                {
                    if (val - i * i == 0)
                    {
                        return count;
                    }
                    else
                    {
                        if (count < 3)
                        {
                            q.push(val - i * i);
                        }
                    }
                }
            }
        }
        return 4;
    }
};
// @lc code=end
