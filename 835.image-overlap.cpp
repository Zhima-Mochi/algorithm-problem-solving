/*
 * @lc app=leetcode id=835 lang=cpp
 *
 * [835] Image Overlap
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
// T:O(N*N) S:O(N*N)
class Solution
{
    int width;

public:
    int largestOverlap(vector<vector<int>> &img1, vector<vector<int>> &img2)
    {
        width = img1.size();
        vector<int> record1, record2;
        unordered_map<int, int> cnt;
        for (int i = 0; i != width * width; ++i)
        {
            if (img1[i / width][i % width])
            {
                record1.push_back(((i / width) << 6) + (i % width));
            }
            if (img2[i / width][i % width])
            {
                record2.push_back(((i / width) << 6) + (i % width));
            }
        }
        for (auto n : record1)
        {
            for (auto m : record2)
            {
                ++cnt[n - m];
            }
        }
        int res = 0;
        for (auto &&[a, b] : cnt)
        {
            res = max(res, b);
        }
        return res;
    }
};
// @lc code=end

// // T:O(N*N*N*N) S:O(1)
// class Solution
// {
//     int width;

// public:
//     int largestOverlap(vector<vector<int>> &img1, vector<vector<int>> &img2)
//     {
//         width = img1.size();
//         int res = 0;
//         for (int i = 0; i != 2 * width - 1; ++i)
//         {
//             for (int j = 0; j != 2 * width - 1; ++j)
//             {
//                 res = max(res, overlap(i, j, img1, img2));
//             }
//         }
//         return res;
//     }
//     int overlap(int i, int j, vector<vector<int>> &img1, vector<vector<int>> &img2)
//     {
//         int res = 0;
//         if (i < width && j < width)
//         {
//             for (int m = 0; m <= i; ++m)
//             {
//                 for (int n = 0; n <= j; ++n)
//                 {
//                     if (img1[width - 1 - i + m][width - 1 - j + n] == 1 && img2[m][n] == 1)
//                     {
//                         ++res;
//                     }
//                 }
//             }
//         }
//         else if (i < width)
//         {
//             j -= width;
//             for (int m = 0; m <= i; ++m)
//             {
//                 for (int n = 0; n <= j; ++n)
//                 {
//                     if (img1[width - 1 - i + m][n] == 1 && img2[m][width - 1 - j + n] == 1)
//                     {
//                         ++res;
//                     }
//                 }
//             }
//         }
//         else if (j < width)
//         {
//             i -= width;
//             for (int m = 0; m <= i; ++m)
//             {
//                 for (int n = 0; n <= j; ++n)
//                 {
//                     if (img1[m][width - 1 - j + n] == 1 && img2[width - 1 - i + m][n] == 1)
//                     {
//                         ++res;
//                     }
//                 }
//             }
//         }
//         else
//         {
//             i -= width;
//             j -= width;
//             for (int m = 0; m <= i; ++m)
//             {
//                 for (int n = 0; n <= j; ++n)
//                 {
//                     if (img1[m][n] == 1 && img2[width - 1 - i + m][width - 1 - j + n] == 1)
//                     {
//                         ++res;
//                     }
//                 }
//             }
//         }
//         return res;
//     }
// };
