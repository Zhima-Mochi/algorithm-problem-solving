/*
 * @lc app=leetcode id=593 lang=cpp
 *
 * [593] Valid Square
 */
#include <vector>
#include <cmath>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
    {
        vector<vector<int>> temp(3);
        temp[0] = vec(p2, p1);
        temp[1] = vec(p3, p1);
        temp[2] = vec(p4, p1);
        vector<int> len_square(3);
        len_square[0] = temp[0][0] * temp[0][0] + temp[0][1] * temp[0][1];
        len_square[1] = temp[1][0] * temp[1][0] + temp[1][1] * temp[1][1];
        len_square[2] = temp[2][0] * temp[2][0] + temp[2][1] * temp[2][1];
        return check(temp, len_square, 0, 1, 2) || check(temp, len_square, 0, 2, 1) || check(temp, len_square, 1, 2, 0);
    }
    bool check(vector<vector<int>> &temp, vector<int> &len_square, int i, int j, int k)
    {
        if (len_square[i] > 0 && len_square[i] == len_square[j] && len_square[i] + len_square[j] == len_square[k])
        {
            return is_orthogonal(temp[i], temp[j]) && is_orthogonal(vec(temp[k], temp[i]), vec(temp[k], temp[j]));
        }
        else
        {
            return false;
        }
    }
    bool is_orthogonal(const vector<int> &n1, const vector<int> &n2)
    {
        return n1[0] * n2[0] == -n1[1] * n2[1];
    }
    vector<int> vec(const vector<int> &n1, const vector<int> &n2)
    {
        return {n2[0] - n1[0], n2[1] - n1[1]};
    }
};
// @lc code=end
