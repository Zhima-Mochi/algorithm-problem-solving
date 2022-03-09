/*
 * @lc app=leetcode id=2055 lang=cpp
 *
 * [2055] Plates Between Candles
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
// t:(len(s)+len(queries)), s:(len(s)+len(queries))
class Solution
{
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>> &queries)
    {
        int w = s.size();
        vector<int> left_candle_pos(w, -1), right_candle_pos(w, w), accum_candles(w);
        if (s[0] == '|')
        {
            accum_candles[0] = 1;
            left_candle_pos[0] = 0;
        }
        for (int i = 1; i != w; ++i)
        {
            if (s[i] == '|')
            {
                accum_candles[i] = accum_candles[i - 1] + 1;
                left_candle_pos[i] = i;
            }
            else
            {
                accum_candles[i] = accum_candles[i - 1];
                left_candle_pos[i] = left_candle_pos[i - 1];
            }
        }
        if (s[w - 1] == '|')
        {
            right_candle_pos[w - 1] = w - 1;
        }
        for (int i = w - 2; i != -1; --i)
        {
            if (s[i] == '|')
            {
                right_candle_pos[i] = i;
            }
            else
            {
                right_candle_pos[i] = right_candle_pos[i + 1];
            }
        }
        vector<int> res;
        for (auto &q : queries)
        {
            int left_pos = right_candle_pos[q[0]];
            int right_pos = left_candle_pos[q[1]];
            if (left_pos > q[1] || right_pos < q[0] || left_pos == right_pos)
            {
                res.push_back(0);
            }
            else
            {
                res.push_back(right_pos - left_pos - (accum_candles[right_pos] - accum_candles[left_pos]));
            }
        }
        return res;
    }
};
// @lc code=end

// t:O(len(s)+len(queries)*log(len(s))), s:O(len(s)+len(queries))
// class Solution
// {
// public:
//     vector<int> platesBetweenCandles(string s, vector<vector<int>> &queries)
//     {
//         vector<int> candle_pos;
//         int w = s.size();
//         for (int i = 0; i != w; ++i)
//         {
//             if (s[i] == '|')
//             {
//                 candle_pos.push_back(i);
//             }
//         }
//         vector<int> res;
//         if (candle_pos.size() == 0)
//         {
//             return vector<int>(queries.size());
//         }
//         for (auto &q : queries)
//         {
//             auto left_candle_pos_pos = lower_bound(candle_pos.begin(), candle_pos.end(), q[0]);
//             auto right_candle_pos_pos = lower_bound(candle_pos.begin(), candle_pos.end(), q[1]);
//             if (right_candle_pos_pos == candle_pos.end() || *right_candle_pos_pos > q[1])
//             {
//                 right_candle_pos_pos = prev(right_candle_pos_pos);
//             }
//             if (left_candle_pos_pos == candle_pos.end() || left_candle_pos_pos == right_candle_pos_pos)
//             {
//                 res.push_back(0);
//             }
//             else if (*left_candle_pos_pos > q[1] || *right_candle_pos_pos < q[0])
//             {
//                 res.push_back(0);
//             }
//             else
//             {
//                 res.push_back(*right_candle_pos_pos - *left_candle_pos_pos - (right_candle_pos_pos - left_candle_pos_pos));
//             }
//         }
//         return res;
//     }
// };