/*
 * @lc app=leetcode id=718 lang=cpp
 *
 * [718] Maximum Length of Repeated Subarray
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        int len1 = nums1.size();
        int len2 = nums2.size();
        auto max_val = 0;
        for (int i = 0; i <= len1 - max_val; ++i)
        {
            auto sub_max_val = 0;
            for (int j = 0, k = i; sub_max_val + min((len2 - j), (len1 - k)) > max_val && j < len2 && k < len1; ++j, ++k)
            {
                if (nums1[k] == nums2[j])
                {
                    ++sub_max_val;
                }
                else
                {
                    max_val = max(max_val, sub_max_val);
                    sub_max_val = 0;
                }
            }
            max_val = max(max_val, sub_max_val);
        }
        nums1.swap(nums2);
        swap(len1, len2);
        //The following code is same with previous one
        for (int i = 0; i <= len1 - max_val; ++i)
        {
            auto sub_max_val = 0;
            for (int j = 0, k = i; sub_max_val + min((len2 - j), (len1 - k)) > max_val && j < len2 && k < len1; ++j, ++k)
            {
                if (nums1[k] == nums2[j])
                {
                    ++sub_max_val;
                }
                else
                {
                    max_val = max(max_val, sub_max_val);
                    sub_max_val = 0;
                }
            }
            max_val = max(max_val, sub_max_val);
        }
        return max_val;
        
    }
};
// @lc code=end
// if (nums1.size() < nums2.size())
        // {
        //     nums1.swap(nums2);
        // }
        // int len1 = nums1.size();
        // int len2 = nums2.size();
        // int max_val = 0;
        // vector<int> vec;
        // for (int j = 0; j != len2; ++j)
        // {
        //     if (nums1[0] == nums2[j])
        //     {
        //         vec.push_back(1);
        //     }
        //     else
        //     {
        //         vec.push_back(0);
        //     }
        // }

        // for (int i = 1; i != len1; ++i)
        // {
        //     auto row_max_value = vec[0];
        //     auto max_value_col_pos = 0;
        //     for (int j = len2 - 1; j != 0; --j)
        //     {
        //         if (nums1[i] == nums2[j])
        //         {
        //             vec[j] = (1 + vec[j - 1]);
        //             if (vec[j] > row_max_value)
        //             {
        //                 row_max_value = vec[j];
        //                 max_value_col_pos = j;
        //             }
        //         }
        //         else
        //         {
        //             vec[j] = 0;
        //         }
        //     }
        //     if (row_max_value <= max_val - max((len1 - i), (len2 - max_value_col_pos)))
        //     {
        //         break;
        //     }
        //     vec[0] = (nums1[i] == nums2[0]);
        //     max_val = max(max_val, row_max_value);
        // }
        // return max_val;