/*
 * @lc app=leetcode id=686 lang=cpp
 *
 * [686] Repeated String Match
 */
#include <string>
using namespace std;
// @lc code=start
// T:O(N*(N+M)) S:O(N+M)
class Solution
{
public:
    string repeat(string &s, int n)
    {
        string repeat;
        for (int i = 0; i < n; ++i)
            repeat += s;
        return repeat;
    }
    int repeatedStringMatch(string a, string b)
    {
        int pos = 0;
        int width_a = a.size();
        int width_b = b.size();
        if (width_b <= width_a)
        {
            if (a.find(b) != -1)
            {
                return 1;
            }
            else if ((a + a).find(b) != -1)
            {
                return 2;
            }
            else
            {
                return -1;
            }
        }
        string extended_a = repeat(a, width_b / width_a);
        if (width_b % width_a == 0 && extended_a == b)
        {
            return width_b / width_a;
        }
        else if ((extended_a + a).find(b) != -1)
        {
            return width_b / width_a + 1;
        }
        else if ((extended_a + a + a).find(b) != -1)
        {
            return width_b / width_a + 2;
        }
        else
        {
            return -1;
        }
    }
};
// @lc code=end
