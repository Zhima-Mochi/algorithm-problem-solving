/*
 * @lc app=leetcode id=1291 lang=cpp
 *
 * [1291] Sequential Digits
 */
#include <vector>
#include <queue>
using namespace std;
// @lc code=start
// t:O(1), s:O(1)
class Solution
{
public:
    vector<int> sequentialDigits(int low, int high)
    {
        vector<int> res;
        queue<int> q;
        for (int i = 1; i != 10; ++i)
        {
            q.push(i);
        }
        while (!q.empty())
        {
            long long n = q.front();
            q.pop();
            if (n >= low)
            {
                res.push_back(n);
            }
            if (n % 10 != 9)
            {
                n = n * 10 + n % 10 + 1;
                if (n <= high)
                {
                    q.push(n);
                }
            }
        }
        return res;
    }
};
// @lc code=end
