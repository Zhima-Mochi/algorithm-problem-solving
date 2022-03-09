/*
 * @lc app=leetcode id=935 lang=cpp
 *
 * [935] Knight Dialer
 */

#include <vector>
#include <numeric>
using namespace std;
// @lc code=start
// t:O(log(n)), s:O(1);
int mod = 1000000007;
class Matrix
{
public:
    vector<vector<long long>> M;
    Matrix()
    {
        M = vector<vector<long long>>(4, vector<long long>(4));
        // {0}, {1,3,7,9}, {2,8}, {4,6}
        M[0][3] = 1;
        M[1][2] = M[1][3] = 2;
        M[2][1] = 1;
        M[3][0] = 2;
        M[3][1] = 1;
    }
    Matrix(vector<vector<long long>> &m)
    {
        M = m;
    }
    Matrix operator*(Matrix &r)
    {
        vector<vector<long long>> res(4, vector<long long>(4));
        for (int i = 0; i != 4; ++i)
        {
            for (int j = 0; j != 4; ++j)
            {
                for (int k = 0; k != 4; ++k)
                {
                    res[i][k] += this->M[i][j] * r.M[j][k];
                    res[i][k] %= mod;
                }
            }
        }
        return Matrix(res);
    }
    Matrix &operator*=(Matrix &r)
    {
        vector<vector<long long>> res(4, vector<long long>(4));
        for (int i = 0; i != 4; ++i)
        {
            for (int j = 0; j != 4; ++j)
            {
                for (int k = 0; k != 4; ++k)
                {
                    res[i][k] += this->M[i][j] * r.M[j][k];
                    res[i][k] %= mod;
                }
            }
        }
        M = res;
        return *this;
    }
    vector<long long> operator*(vector<long long> &r)
    {
        vector<long long> res(4);
        for (int i = 0; i != 4; ++i)
        {
            for (int j = 0; j != 4; ++j)
            {
                res[i] += M[i][j] * r[j];
            }
            res[i] %= mod;
        }
        return res;
    }
};
class Solution
{
public:
    int knightDialer(int n)
    {
        if (n == 1)
        {
            return 10;
        }
        vector<vector<long long>> identity(4, vector<long long>(4));
        for (int i = 0; i != 4; ++i)
        {
            identity[i][i] = 1;
        }
        vector<long long> res = {1, 4, 2, 2};
        Matrix res_matrix = Matrix(identity);
        Matrix m = Matrix();
        n -= 1;
        while (n)
        {
            if (n & 1)
            {
                res_matrix *= m;
            }
            m *= m;
            n >>= 1;
        }
        res = res_matrix * res;
        return accumulate(res.begin(), res.end(), 0LL) % mod;
    }
};
// @lc code=end