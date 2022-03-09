/*
 * @lc app=leetcode id=2094 lang=cpp
 *
 * [2094] Finding 3-Digit Even Numbers
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> findEvenNumbers(vector<int> &digits)
    {
        vector<int> record(10);
        for (auto d : digits)
        {
            ++record[d];
        }
        vector<int> res;
        for (int i = 100; i != 1000; i += 2)
        {
            vector<int> require(10);
            ++require[i / 100];
            ++require[i / 10 % 10];
            ++require[i % 10];
            auto match = true;
            for (int j = 0; j != 10; ++j)
            {
                if (require[j] > record[j])
                {
                    match = false;
                    break;
                }
            }
            if (match)
            {
                res.push_back(i);
            }
        }
        return res;
    }
};
// @lc code=end
