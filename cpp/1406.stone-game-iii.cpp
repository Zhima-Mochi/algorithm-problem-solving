/*
 * @lc app=leetcode id=1406 lang=cpp
 *
 * [1406] Stone Game III
 */
#include <string>
#include <vector>
#include <functional>
using namespace std;
// @lc code=start
// t:O(n) s:O(n)
class Solution
{
    int no_val = -1000000000;

public:
    string stoneGameIII(vector<int> &stoneValue)
    {
        int w = stoneValue.size();
        vector<vector<int>> records(2, vector<int>(w + 1, no_val)); // 0 alice, 1 bob
        records[0][w] = 0;
        records[1][w] = 0;

        function<int(int, int)> dp = [&](int turn, int pos) -> int
        {
            if (records[turn ^ 1][pos - 1] != no_val)
            {
                return records[turn ^ 1][pos - 1];
            }
            int cur_val = 0;
            int expected_val = no_val;
            for (int i = 0; i != 3; ++i)
            {
                if (i + pos > w)
                {
                    break;
                }
                cur_val += stoneValue[i + pos - 1];
                expected_val = max(expected_val, cur_val + dp(turn ^ 1, i + pos + 1) * -1);
            }
            records[turn ^ 1][pos - 1] = expected_val;
            return records[turn ^ 1][pos - 1];
        };
        int res = dp(0, 1);
        if (res > 0)
        {
            return "Alice";
        }
        else if (res == 0)
        {
            return "Tie";
        }
        else
        {
            return "Bob";
        }
    }
};
// @lc code=end
