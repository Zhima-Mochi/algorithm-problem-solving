/*
 * @lc app=leetcode id=1346 lang=cpp
 *
 * [1346] Check If N and Its Double Exist
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool checkIfExist(vector<int> &arr)
    {
        vector<bool> check(2001);
        for (auto n : arr)
        {
            if (n <= 500 && n >= -500 && check[2 * n + 1000])
            {
                return true;
            };
            if (n % 2 == 0 && check[n / 2 + 1000])
            {
                return true;
            }
            check[n + 1000] = true;
        }
        return false;
    }
};
// @lc code=end
