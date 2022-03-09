/*
 * @lc app=leetcode id=1338 lang=cpp
 *
 * [1338] Reduce Array Size to The Half
 */
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minSetSize(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        vector<int> len;
        auto num = arr[0];
        auto count = 0;
        for (auto &val : arr)
        {
            if (val == num)
            {
                count++;
            }
            else
            {
                len.push_back(count);
                count = 1;
                num = val;
            }
        }
        len.push_back(count);
        sort(len.begin(), len.end(),greater());
        auto width = arr.size();
        auto vec_width = len.size();
        auto sum = 0;
        for (int i = 0; i != vec_width; ++i)
        {
            sum += len[i];
            if (sum >= width / 2)
            {
                return i + 1;
            }
        }
        return 1;
        // unordered_map<int, int> mp;
        // for (auto &v : arr)
        // {
        //     ++mp[v];
        // }
        // vector<int> vec;
        // for (auto &val : mp)
        // {
        //     vec.push_back(val.second);
        // }
        // make_heap(vec.begin(), vec.end());
        // //sort(vec.begin(), vec.end(), greater());
        // auto width = arr.size();
        // auto vec_width = vec.size();
        // auto sum = 0;
        // for (int i = 0; i != vec_width; ++i)
        // {
        //     pop_heap(vec.begin(), vec.end());
        //     sum += vec.back();
        //     if (sum >= width / 2)
        //     {
        //         return i + 1;
        //     }
        //     vec.pop_back();
        // }
        // return 1;
    }
};
// @lc code=end
