/*
 * @lc app=leetcode id=1220 lang=cpp
 *
 * [1220] Count Vowels Permutation
 */
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
// @lc code=start
class Matrix
{
public:
    Matrix(vector<vector<int>> a) : m(a) {}

    Matrix operator*(Matrix &right)
    {
        int mod = 1000000007;
        auto len = this->m.size();
        Matrix new_m(vector<vector<int>>(len, vector<int>(len, 0)));
        for (int i = 0; i != len; i++)
        {
            for (int j = 0; j != len; j++)
            {
                for (int k = 0; k != len; k++)
                {
                    new_m.m[i][k] += (this->m)[i][j] + right.m[j][k];
                    new_m.m[i][k] %= mod;
                }
            }
        }
        return new_m;
    }
    vector<vector<int>> m;
};
class Solution
{

public:
    vector<Matrix> vm = {Matrix(vector<vector<int>>{{0, 1, 1, 0, 1}, {1, 0, 1, 0, 0}, {0, 1, 0, 1, 0}, {0, 0, 1, 0, 0}, {0, 0, 1, 1, 0}})};
    int countVowelPermutation(int n)
    {
        auto m = n / 2;
        while (m)
        {
            vm.push_back(vm.back() * vm.back());
            m /= 2;
        }
        int mod = 1000000007;
        
        vector<int> count(5, 1);
        while (n != 1)
        {
            vector<int> next_count(5, 0);
            next_count[0] += (count[1] + count[2]) % mod + count[4];
            next_count[1] += count[0] + count[2];
            next_count[2] += count[1] + count[3];
            next_count[3] += count[2];
            next_count[4] += count[2] + count[3];
            n--;
            transform(next_count.begin(), next_count.end(), count.begin(), [mod](int a)
                      { return a % mod; });
        }
        return accumulate(count.begin(), count.end(), static_cast<long>(0)) % mod;
    }
};
// @lc code=end
