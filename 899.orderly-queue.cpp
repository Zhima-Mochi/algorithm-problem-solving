/*
 * @lc app=leetcode id=899 lang=cpp
 *
 * [899] Orderly Queue
 */
#include <string>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    string orderlyQueue(string s, int k)
    {
        if (k > 1)
        {
            sort(s.begin(), s.end());
            return s;
        }
        else
        {
            deque<char> candidate(s.begin(), s.end());
            deque<char> str = candidate;
            int len = s.size();
            for (int i = 0; i != len - 1; ++i)
            {
                str.push_back(str.front());
                str.pop_front();
                candidate = min(str, candidate);
            }
            return string(candidate.begin(), candidate.end());
        }
    }
};
// @lc code=end
