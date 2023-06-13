/*
 * @lc app=leetcode id=1871 lang=cpp
 *
 * [1871] Jump Game VII
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
// t:O(n) s:O(n)
class Solution
{
public:
    bool canReach(string s, int minJump, int maxJump)
    {
        int w = s.size();
        vector<int> positions;
        for (int i = 0; i != w; ++i)
        {
            if (s[i] == '0')
            {
                positions.push_back(i);
                s[i] = '1';
            }
        };
        if (positions.back() != w - 1)
        {
            return false;
        }
        positions.pop_back();
        s[w - 1] = '0';
        int cur = w - 1;
        while (cur >= 0)
        {
            if (s[cur] == '1')
            {
                --cur;
                continue;
            }
            while (!positions.empty())
            {
                if (cur - positions.back() > maxJump)
                {
                    break;
                }
                if (cur - positions.back() < minJump)
                {
                    s[positions.back()] = '1';
                }
                else
                {
                    s[positions.back()] = '0';
                }
                positions.pop_back();
            }
            --cur;
        }
        return s[0] == '0';
    }
};
// @lc code=end
