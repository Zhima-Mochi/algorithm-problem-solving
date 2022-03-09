/*
 * @lc app=leetcode id=969 lang=cpp
 *
 * [969] Pancake Sorting
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
// t:O(N^2), s:O(N)
class Solution
{
public:
    vector<int> pancakeSort(vector<int> &arr)
    {
        int w = arr.size();
        vector<int> res;
        int n = w;
        while (n)
        {
            if (arr.back() == n)
            {
                arr.pop_back();
            }
            else
            {
                vector<int> next_arr;
                int i = n - 1;
                for (; i != -1; --i)
                {
                    if (arr[i] == n)
                    {
                        if (i != 0)
                        {
                            res.push_back(i + 1);
                        }
                        res.push_back(n);
                        break;
                    }
                    next_arr.push_back(arr[i]);
                }
                for (int j = 0; j != i; ++j)
                {
                    next_arr.push_back(arr[j]);
                }
                arr = move(next_arr);
            }
            --n;
        }
        return res;
    }
};
// @lc code=end
