/*
 * @lc app=leetcode id=384 lang=cpp
 *
 * [384] Shuffle an Array
 */
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;
// @lc code=start
class Solution
{
public:
    Solution(vector<int> &nums)
        : n(nums), shu_n(nums), len(nums.size())
    {
        srand(time(nullptr));
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset()
    {
        return n;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle()
    {
        for (int i = 0; i != len; ++i)
        {
            swap(shu_n[i], shu_n[rand() % len]);
        }
        return shu_n;
    }

private:
    vector<int> n;
    vector<int> shu_n;
    size_t len;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end
