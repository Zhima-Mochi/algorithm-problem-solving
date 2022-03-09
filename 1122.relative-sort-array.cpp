/*
 * @lc app=leetcode id=1122 lang=cpp
 *
 * [1122] Relative Sort Array
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        unordered_map<int, int> comp_order;
        for (int i = 0, len = arr2.size(); i != len; ++i)
        {
            comp_order[arr2[i]] = i;
        }
        sort(arr1.begin(), arr1.end(), [&comp_order](int &l, int &r)
             {
                 if (comp_order.count(l) && comp_order.count(r))
                 {
                     return comp_order[l] < comp_order[r];
                 }
                 else if (comp_order.count(l))
                 {
                     return true;
                 }
                 else if (comp_order.count(r))
                 {
                     return false;
                 }
                 else
                 {
                     return l < r;
                 }
             });
        return arr1;
    }
};
// @lc code=end
