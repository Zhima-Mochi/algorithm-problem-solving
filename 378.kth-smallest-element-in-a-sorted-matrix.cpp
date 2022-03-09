/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start

class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int width = matrix.size();
        int left = matrix[0][0];
        int right = matrix[width - 1][width - 1];
        while (left < right)
        {
            auto mid = left + (right - left) / 2;
            auto count = 0;
            int i = 0;
            int j = width - 1;
            auto max_value = matrix[0][0];
            while (i != width && j != -1)
            {
                if (matrix[i][j] <= mid)
                {
                    max_value = max(max_value, matrix[i][j]);
                    count += (j + 1);
                    ++i;
                }
                else
                {
                    --j;
                }
            }
            if (count == k)
            {
                return max_value;
            }
            else if (count < k)
            {
                left = mid + 1;
            }
            else
            {
                right = max_value;
            }
        }
        return right;
    }
};
// @lc code=end

// using iter = vector<int>::iterator;
// using iter_pair = pair<iter, iter>;
// static bool compf(iter_pair &a, iter_pair &b)
// {

//     return (*a.first) > (*b.first);
// };

// int width = matrix.size();

// if (k > width * width / 2)
// {
//     k = width * width - k + 1;
//     multiset<int, greater<int>> st;
//     for (int i = width - 1; i != -1; --i)
//     {
//         for (int j = width - 1; j != -1; --j)
//         {

//             if ((st.size() > k && matrix[i][j] < *prev(st.end())) || (width - i) * (width - j) > k)
//             {
//                 break;
//             }
//             st.insert(matrix[i][j]);
//         }
//     }
//     auto itr = st.begin();
//     advance(itr, k - 1);
//     return *itr;
// }
// else
// {
//     multiset<int> st;
//     for (int i = 0; i != width; ++i)
//     {
//         for (int j = 0; j != width; ++j)
//         {
//             if ((st.size() > k && matrix[i][j] > *prev(st.end())) || (i + 1) * (j + 1) > k)
//             {
//                 break;
//             }
//             st.insert(matrix[i][j]);
//         }
//     }
//     auto itr = st.begin();
//     advance(itr, k - 1);
//     return *itr;
// }
// return 0;

// vector<pair<iter, iter>> vec;
// int height = matrix.size(), width = matrix[0].size();
// for (auto &row : matrix)
// {
//     vec.push_back({row.begin(), row.end()});
// }
// make_heap(vec.begin(), vec.end(), compf);
// while (k - 1)
// {
//     pop_heap(vec.begin(), vec.end(), compf);
//     auto min = vec.back();
//     vec.pop_back();
//     ++min.first;
//     if (min.first != min.second)
//     {
//         vec.push_back(min);
//         push_heap(vec.begin(), vec.end(), compf);
//     }
//     k--;
// };
// pop_heap(vec.begin(), vec.end(), compf);
// auto min = vec.back();
// return *min.first;