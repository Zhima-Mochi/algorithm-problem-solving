/*
 * @lc app=leetcode id=2053 lang=cpp
 *
 * [2053] Kth Distinct String in an Array
 */
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    string kthDistinct(vector<string> &arr, int k)
    {
        unordered_map<string, int> record;
        for (auto &&s : arr)
        {
            ++record[s];
        }
        for (auto &&s : arr)
        {
            if (record[s] == 1)
            {
                --k;
                if (k == 0)
                {
                    return s;
                }
            }
        }
        return "";
    }
};
// @lc code=end
