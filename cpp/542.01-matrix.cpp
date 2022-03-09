/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 */
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
    int height;
    int width;

public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        height = mat.size();
        width = mat[0].size();
        if (mat[0][0] == 1)
        {
            mat[0][0] = 10001;
        }
        for (int i = 1; i != height; ++i)
        {
            if (mat[i][0] != 0)
            {
                mat[i][0] = mat[i - 1][0] + 1;
            }
        }
        for (int j = 1; j != width; ++j)
        {
            if (mat[0][j] != 0)
            {
                mat[0][j] = mat[0][j - 1] + 1;
            }
        }
        for (int i = 1; i != height; ++i)
        {
            for (int j = 1; j != width; ++j)
            {
                if (mat[i][j] != 0)
                {
                    mat[i][j] = min(mat[i - 1][j], mat[i][j - 1]) + 1;
                }
            }
        }
        for (int i = height - 2; i != -1; --i)
        {
            if (mat[i][width - 1] != 0)
            {
                mat[i][width - 1] = min(mat[i][width - 1], mat[i + 1][width - 1] + 1);
            }
        }
        for (int j = width - 2; j != -1; --j)
        {
            if (mat[height - 1][j] != 0)
            {
                mat[height - 1][j] = min(mat[height - 1][j], mat[height - 1][j + 1] + 1);
            }
        }
        for (int i = height - 2; i != -1; --i)
        {
            for (int j = width - 2; j != -1; --j)
            {
                if (mat[i][j] != 0)
                {
                    mat[i][j] = min(mat[i][j], min(mat[i + 1][j], mat[i][j + 1]) + 1);
                }
            }
        }

        return mat;
    }
};
// @lc code=end
// //BFS
// class Solution
// {
//     int height;
//     int width;

// public:
//     vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
//     {
//         height = mat.size();
//         width = mat[0].size();
//         queue<int> q;
//         for (int i = 0; i != height; ++i)
//         {
//             for (int j = 0; j != width; ++j)
//             {
//                 if (mat[i][j] == 0)
//                 {
//                     q.push((i << 15) + j);
//                 }
//                 else
//                 {
//                     mat[i][j] = 2000;
//                 }
//             }
//         }
//         int count = 0;
//         while (!q.empty())
//         {
//             int len = q.size();
//             while (len--)
//             {
//                 int row = q.front() >> 15;
//                 int col = q.front() % (1 << 15);
//                 q.pop();
//                 if (mat[row][col] < count)
//                 {
//                     continue;
//                 }
//                 mat[row][col] = count;
//                 if (row > 0)
//                 {
//                     q.push(((row - 1) << 15) + col);
//                 }
//                 if (row < height - 1)
//                 {
//                     q.push(((row + 1) << 15) + col);
//                 }
//                 if (col > 0)
//                 {
//                     q.push((row << 15) + col - 1);
//                 }
//                 if (col < width - 1)
//                 {
//                     q.push((row << 15) + col + 1);
//                 }
//             }
//             ++count;
//         }
//         return mat;
//     }
// };