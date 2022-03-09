/*
 * @lc app=leetcode id=519 lang=cpp
 *
 * [519] Random Flip Matrix
 */
#include <vector>
#include <random>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
    unordered_map<int, int> seen;
    int height;
    int width;
    default_random_engine gen;
    uniform_int_distribution<int> dist = uniform_int_distribution<int>(0, INT32_MAX);
    int total;

public:
    Solution(int m, int n)
    {
        height = m;
        width = n;
        total = m * n;
    }
    vector<int> flip()
    {
        int choose = dist(gen) % (total--);
        int res = seen.count(choose) ? seen[choose] : choose;
        seen[choose] = seen.count(total) ? seen[total] : total;
        return {res / width, res % width};
    }

    void reset()
    {
        seen.clear();
        total = height * width;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
// @lc code=end

// class Solution
// {
//     vector<vector<bool>> mat;
//     int height;
//     int width;
//     vector<int> rest_count;
//     default_random_engine gen;
//     uniform_int_distribution<int> dist = uniform_int_distribution<int>(0, INT32_MAX);

// public:
//     Solution(int m, int n)
//     {
//         height = m;
//         width = n;
//         mat = vector<vector<bool>>(m, vector<bool>(n));
//         rest_count = vector<int>(m, n);
//     }
//     vector<int> flip()
//     {
//         int denominator = 0;
//         vector<int> res = {0, 0};
//         for (int i = 0; i != height; ++i)
//         {
//             if(rest_count[i]==0){
//                 continue;
//             }
//             ++denominator;
//             if (dist(gen) % denominator * width <= rest_count[i] - 1)
//             {
//                 res[0]=i;
//             }
//         }
//         --rest_count[res[0]];
//         denominator = 0;
//         for (int j = 0; j != width; ++j)
//         {
//             if(mat[res[0]][j]){
//                 continue;
//             }
//             ++denominator;
//             if (dist(gen) % denominator == 0)
//             {
//                 res[1]=j;
//             }
//         }
//         mat[res[0]][res[1]] = true;
//         return res;
//     }

//     void reset()
//     {
//         for (auto &row_elem : mat)
//         {
//             fill(row_elem.begin(), row_elem.end(), false);
//             fill(rest_count.begin(), rest_count.end(), width);
//         }
//     }
// };

// class Solution
// {
//     vector<vector<bool>> mat;
//     vector<int> rest_count;
//     int height;
//     int width;
//     default_random_engine gen;
//     uniform_int_distribution<int> dist = uniform_int_distribution<int>(0, INT32_MAX);
//     int total_rest;

// public:
//     Solution(int m, int n)
//     {
//         height = m;
//         width = n;
//         mat = vector<vector<bool>>(m, vector<bool>(n));
//         rest_count = vector<int>(m, n);
//         total_rest = m * n;
//     }
//     vector<int> flip()
//     {
//         int row = 0;
//         int col = 0;
//         int choose = dist(gen) % total_rest;
//         while (row < height)
//         {
//             choose -= rest_count[row];
//             if (choose < 0)
//             {
//                 break;
//             }
//             ++row;
//         }
//         --rest_count[row];
//         while (col < width)
//         {
//             if (!mat[row][col])
//             {
//                 ++choose;
//             }
//             if (choose == 0)
//             {
//                 break;
//             }
//             ++col;
//         }
//         mat[row][col] = true;
//         --total_rest;
//         return {row, col};
//     }

//     void reset()
//     {
//         for (auto &row_elem : mat)
//         {
//             fill(row_elem.begin(), row_elem.end(), false);
//         }
//         fill(rest_count.begin(), rest_count.end(), width);
//         total_rest = height * width;
//     }
// };