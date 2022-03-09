/*
 * @lc app=leetcode id=949 lang=cpp
 *
 * [949] Largest Time for Given Digits
 */
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
// @lc code=start
// t:O(1), s:O(1)
class Solution
{
public:
    static unordered_map<string, string> rd;
    string largestTimeFromDigits(vector<int> &arr)
    {
        if (rd.empty())
        {
            for (int i = 0; i != 24; ++i)
            {
                for (int j = 0; j != 60; ++j)
                {
                    string time = string(i < 10 ? 1 : 0, '0') + to_string(i) + ':' + string(j < 10 ? 1 : 0, '0') + to_string(j);
                    string sorted_time = time;
                    sort(sorted_time.begin(), sorted_time.end());
                    rd[sorted_time] = time;
                }
            }
        }
        string t = ":";
        for (auto n : arr)
        {
            t.push_back(n + '0');
        }
        sort(t.begin(), t.end());
        return rd[t];
    }
};
unordered_map<string, string> Solution::rd = unordered_map<string, string>();

// @lc code=end
