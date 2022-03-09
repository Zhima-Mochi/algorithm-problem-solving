/*
 * @lc app=leetcode id=461 lang=cpp
 *
 * [461] Hamming Distance
 */
#include<bitset>
using namespace std;
// @lc code=start
class Solution {
public:
    int hammingDistance(int x, int y) {
        bitset<32> b(x^y);
        return b.count();
    }
};
// @lc code=end

