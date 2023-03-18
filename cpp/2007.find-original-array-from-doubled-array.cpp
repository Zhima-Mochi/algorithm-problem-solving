/*
 * @lc app=leetcode id=2007 lang=cpp
 *
 * [2007] Find Original Array From Doubled Array
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> findOriginalArray(vector<int> &changed)
    {
        int w = changed.size();
        if (w % 2)
        {
            return {};
        }
        unordered_map<int, int> records;
        sort(changed.begin(), changed.end());
        vector<int> res;
        for (int i = w - 1; i != -1; --i)
        {
            if (records.count(changed[i] * 2))
            {
                records[changed[i] * 2]--;
                if (records[changed[i] * 2] == 0)
                {
                    records.erase(changed[i] * 2);
                }
                res.push_back(changed[i]);
            }
            else
            {
                records[changed[i]]++;
            }
        }
        if (!records.empty())
        {
            return {};
        }
        return res;
    }
};
// @lc code=end
