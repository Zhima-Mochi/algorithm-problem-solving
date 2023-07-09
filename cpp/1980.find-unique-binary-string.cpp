/*
 * @lc app=leetcode id=1980 lang=cpp
 *
 * [1980] Find Unique Binary String
 */
#include <string>
#include <vector>
#include <set>
using namespace std;
// @lc code=start
class Solution
{
public:
    string findDifferentBinaryString(vector<string> &nums)
    {
        string res(nums.size(), '0');
        set<int> seen;
        for (auto s : nums)
        {
            int r = 0;
            for (int i = 0; i != nums.size(); ++i)
            {
                r <<= 1;
                if (s[i] == '1')
                {
                    r += 1;
                }
            }
            seen.insert(r);
        }
        for (auto val : seen)
        {
            if (!seen.count(val + 1))
            {
                int k = val + 1;
                for (int i = 0; i != nums.size(); ++i)
                {
                    if (k & (1 << i))
                    {
                        res[nums.size() - i - 1] = '1';
                    }
                }
                return res;
            }
        }
        return res;
    }
};
// @lc code=end
