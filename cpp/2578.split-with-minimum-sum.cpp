/*
 * @lc app=leetcode id=2578 lang=cpp
 *
 * [2578] Split With Minimum Sum
 */
#include <climits>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int splitNum(int num)
    {
        int res = 0;
        vector<int> n;
        int t = 0;
        while (num)
        {
            n.push_back(num % 10);
            num /= 10;
            t += 1;
        }
        sort(n.begin(), n.end());
        for (auto val : n)
        {
            for (int i = 0; i != (t + 1) / 2 - 1; i += 1)
            {
                val *= 10;
            }
            res += val;
            t -= 1;
        }
        return res;
    }
};
// @lc code=end
