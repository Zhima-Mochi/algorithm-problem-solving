/*
 * @lc app=leetcode id=1073 lang=cpp
 *
 * [1073] Adding Two Negabinary Numbers
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> addNegabinary(vector<int> &arr1, vector<int> &arr2)
    {
        int w1 = arr1.size();
        int w2 = arr2.size();
        int w = max(w1, w2) + 4;
        vector<int> res(w);
        for (int i = 0; i != w1; ++i)
        {
            res[i] += arr1[w1 - 1 - i];
        }
        for (int i = 0; i != w2; ++i)
        {
            res[i] += arr2[w2 - 1 - i];
        }
        for (int i = 0; i != w - 2; ++i)
        {
            int del = min(res[i] / 2, res[i + 1]);
            res[i] -= del * 2;
            res[i + 1] -= del;
            if (res[i] > 1)
            {
                res[i + 1] += res[i] / 2;
                res[i + 2] += res[i] / 2;
                res[i] &= 1;
            }
        }
        while (res.size() > 1 && res.back() == 0)
        {
            res.pop_back();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
