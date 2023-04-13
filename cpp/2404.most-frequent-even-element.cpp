/*
 * @lc app=leetcode id=2404 lang=cpp
 *
 * [2404] Most Frequent Even Element
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
// t:O(n) s:O(n)
class Solution
{
public:
    int mostFrequentEven(vector<int> &nums)
    {
        unordered_map<int, int> records;
        for (auto num : nums)
        {
            if (num % 2 == 0)
            {
                records[num]++;
            }
        }
        if (records.size() == 0)
        {
            return -1;
        }
        int max = 0;
        int res = 0;
        for (auto record : records)
        {
            if (record.second > max)
            {
                max = record.second;
                res = record.first;
            }
            else if (record.second == max)
            {
                res = min(res, record.first);
            }
        }
        return res;
    }
};
// @lc code=end
