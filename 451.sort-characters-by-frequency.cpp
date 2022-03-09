/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 */
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    string frequencySort(string s)
    {
        vector<int> count(128);
        for (auto c : s)
        {
            ++count[c];
        }
        auto comp = [](const pair<char, int> &l, const pair<char, int> &r)
        {
            return l.second < r.second;
        };
        for (int i = 0; i != 128; ++i)
        {
            if (count[i] > 0)
            {
                count[i] *= 128;
                count[i] += i;
            }
        }
        sort(count.begin(), count.end(), greater<int>());
        auto pos = 0;
        for (auto &val : count)
        {
            auto ch = static_cast<char>(val & 127);
            auto freq = val >> 7;
            for (int i = 0; i != freq; ++i)
            {
                s[pos++] = ch;
            }
        }
        return s;
    }
};
// @lc code=end
// class Solution
// {
// public:
//     string frequencySort(string s)
//     {
//         vector<int> count(128);
//         for (auto c : s)
//         {
//             ++count[c];
//         }
//         auto comp = [](const pair<char, int> &l, const pair<char, int> &r)
//         {
//             return l.second < r.second;
//         };
//         priority_queue<pair<char, int>,
//                        vector<pair<char, int>>, decltype(comp)>
//             pq(comp);
//         for (int i = 0; i != 128; ++i)
//         {
//             if (count[i] > 0)
//             {
//                 pq.push({i, count[i]});
//             }
//         }
//         auto pos = 0;
//         while (!pq.empty())
//         {
//             auto &elem = pq.top();
//             for (int i = 0; i != elem.second; ++i)
//             {
//                 s[pos++] = elem.first;
//             }
//             pq.pop();
//         }
//         return s;
//     }
// };