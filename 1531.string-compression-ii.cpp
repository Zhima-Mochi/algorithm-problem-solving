/*
 * @lc app=leetcode id=1531 lang=cpp
 *
 * [1531] String Compression II
 */
#include <string>
#include <queue>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int getLen(int num)
    {
        if (num > 0)
        {
            int res = 0;
            while (num)
            {
                ++res;
                num /= 10;
            }
            return res;
        }
        return 0;
    }
    int getLengthOfOptimalCompression(string s, int k)
    {
        vector<int> l_bases = {1};
        for (int i = 1; i != 32; ++i)
        {
            l_bases.push_back(l_bases.back() * 10);
        }
        priority_queue<int, vector<int>, greater<int>> candidates1;
        priority_queue<int, vector<int>, greater<int>> candidates2;

        int cur = 0;
        int w = s.size();
        int res = 0;
        char prev = -1;
        int num = 0;
        while (cur != w)
        {
            if (prev != s[cur])
            {
                int l = getLen(num);
                if (l == 0)
                {
                    continue;
                }
                if (l <= 9)
                {
                    candidates2.push(l);
                }
                prev = s[cur];
            }
        }
    }
};
// @lc code=end
