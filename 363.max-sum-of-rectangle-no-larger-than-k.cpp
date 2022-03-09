/*
 * @lc app=leetcode id=363 lang=cpp
 *
 * [363] Max Sum of Rectangle No Larger Than K
 */
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{

public:
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k)
    {
        int height = matrix.size(), width = matrix[0].size();
        int res = -1000000;
        for (int i = 0; i != height; ++i)
        {
            vector<int> cols_sum(width, 0);
            for (int m = i; m != height; ++m)
            {
                for (int n = 0; n != width; ++n)
                {
                    cols_sum[n] += matrix[m][n];
                }
                set<int> oset;
                oset.insert(0);
                int accum_sum = 0;
                for (auto &col_sum : cols_sum)
                {
                    accum_sum += col_sum;
                    set<int>::iterator siter;
                    if ((siter = oset.lower_bound(accum_sum - k)) != oset.end())
                    {
                        res = max(res, accum_sum - *siter);
                        if (res == k)
                        {
                            return res;
                        }
                    }
                    oset.insert(accum_sum);
                }
            }
        }

        return res;
    }
};
// @lc code=end

// class Solution
// {
//     void check(int start_pos, int end_pos, bool add_width, int &res, vector<vector<int>> &matrix, int &k)
//     {
//     }

// public:
//     int maxSumSubmatrix(vector<vector<int>> &matrix, int k)
//     {
//         int height = matrix.size() + 1, width = matrix[0].size() + 1;
//         matrix.push_back(vector<int>(width - 1, 0));
//         for (auto &row : matrix)
//         {
//             row.push_back(0);
//         }

//         int res = -1000000;

//         for (int i = height - 2; i != -1; --i)
//         {
//             for (int j = width - 2; j != -1; --j)
//             {
//                 matrix[i][j] += matrix[i + 1][j] + matrix[i][j + 1] - matrix[i + 1][j + 1];
//             }
//         }
//         pair<int, int> max_pos, min_pos;
//         int max_val = -100, min_val = 100;

//         for (int m = height - 1; m != 0; --m)
//         {
//             for (int n = width - 1; n != 0; --n)
//             {
//                 for (int i = m - 1; i != -1; --i)
//                 {
//                     for (int j = n - 1; j != -1; --j)
//                     {
//                         helpler(i, j, m, n, res, matrix, k);
//                         if (res == k)
//                         {
//                             return k;
//                         }
//                     }
//                 }
//             }
//         }

//         return res;
//     }
//     void helpler(int &i, int &j, int &m, int &n, int &res, vector<vector<int>> &matrix, int &k)
//     {
//         auto val = matrix[i][j] - matrix[i][n] - matrix[m][j] + matrix[m][n];
//         if (val <= k)
//         {
//             res = max(res, val);
//         }
//     }
// };
