/*
 * @lc app=leetcode id=2048 lang=cpp
 *
 * [2048] Next Greater Numerically Balanced Number
 */
#include <string>
#include <cmath>
#include <vector>
#include <set>
using namespace std;
// @lc code=start
set<int> candidates;
class Solution
{
    void helper(int i)
    {
        vector<int> cnt(10);
        int val = i;
        while (val)
        {
            cnt[val % 10]++;
            val /= 10;
        }
        if (cnt[0])
        {
            return;
        }
        bool flag = true;
        for (int i = 1; i != 10; ++i)
        {
            if (cnt[i] && cnt[i] != i)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            candidates.insert(i);
        }
    }

public:
    int nextBeautifulNumber(int n)
    {
        if (candidates.size() == 0)
        {
            candidates.insert(1224444);
            candidates.insert(1);
            for (int i = 10; i != 23; ++i)
            {
                helper(i);
            }
            for (int i = 122; i != 334; ++i)
            {
                helper(i);
            }
            for (int i = 1333; i != 4445; ++i)
            {
                helper(i);
            }
            for (int i = 14444; i != 55556; ++i)
            {
                helper(i);
            }
            for (int i = 122333; i != 666667; ++i)
            {
                helper(i);
            }
        }
        return *candidates.upper_bound(n);
    }
};
// @lc code=end
