/*
 * @lc app=leetcode id=2081 lang=cpp
 *
 * [2081] Sum of k-Mirror Numbers
 */
#include <vector>
#include <queue>
#include <string>
using namespace std;
// @lc code=start
using ll = long long;
class Solution
{
    int arr[100];

public:
    long long kMirror(int k, int n)
    {
        auto is_pl = [&](ll n) -> bool
        {
            int w = 0;
            while (n)
            {
                arr[w] = n % k;
                ++w;
                n /= k;
            }
            bool flag = true;
            for (int i = 0; i != w / 2; ++i)
            {
                if (arr[i] != arr[w - 1 - i])
                {
                    flag = false;
                    break;
                }
            }
            return flag;
        };
        ll res = 0;
        ll start = 1;
        int cnt = 0;
        while (cnt < n)
        {
            for (int is_even = 0; is_even < 2 && cnt < n; ++is_even)
            {
                for (int i = start, end = start * 10; i != end && cnt < n; ++i)
                {
                    ll ext_val = i;
                    ll tail = is_even ? i : i / 10;
                    while (tail)
                    {
                        ext_val = ext_val * 10 + tail % 10;
                        tail /= 10;
                    }
                    if (is_pl(ext_val))
                    {
                        ++cnt;
                        res += ext_val;
                    }
                }
            }
            start *= 10;
        }
        return res;
    }
};
// @lc code=end

// using ll = long long;
// class Solution
// {
// public:
//     vector<ll> arr;
//     int arr_val_len = 0;
//     long long kMirror(int k, int n)
//     {
//         long long res = 0;

//         while (n)
//         {
//             if (arr.size() == 0)
//             {
//                 helpler(++arr_val_len, k);
//             }
//             auto base_10_val = arr.back();
//             arr.pop_back();
//             string base_10_str = to_string(base_10_val);
//             bool flag = true;
//             for (int i = 0, w = base_10_str.size(); i != w; ++i)
//             {
//                 if (base_10_str[i] != base_10_str[w - 1 - i])
//                 {
//                     flag = false;
//                     break;
//                 }
//             }
//             if (flag)
//             {
//                 res += base_10_val;
//                 --n;
//             }
//         }
//         return res;
//     }
//     void helpler(int idx, int k)
//     {
//         auto s = string(arr_val_len, '0');
//         vector<string> nw_arr = {};
//         for (int i = 1; i != k; ++i)
//         {
//             nw_arr.push_back(s);
//             nw_arr.back()[0] = '0' + i;
//             nw_arr.back()[arr_val_len - 1] = '0' + i;
//         }
//         for (int i = 1; i < arr_val_len / 2; ++i)
//         {
//             for (int j = 0, w = nw_arr.size(); j != w; ++j)
//             {
//                 for (int m = 1; m != k; ++m)
//                 {
//                     nw_arr.push_back(nw_arr[j]);
//                     nw_arr.back()[i] = '0' + m;
//                     nw_arr.back()[arr_val_len - 1 - i] = '0' + m;
//                 }
//             }
//         }

//         if (arr_val_len % 2 && arr_val_len > 1)
//         {
//             for (int j = 0, w = nw_arr.size(); j != w; ++j)
//             {
//                 for (int m = 1; m != k; ++m)
//                 {
//                     nw_arr.push_back(nw_arr[j]);
//                     nw_arr.back()[arr_val_len / 2] += m;
//                 }
//             }
//         }
//         for (auto &&s : nw_arr)
//         {
//             ll res = 0;
//             for (auto c : s)
//             {
//                 res = res * k + c - '0';
//             }
//             arr.push_back(res);
//         }
//         sort(arr.begin(), arr.end(), greater<ll>());
//     }
// };
