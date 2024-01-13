/*
 * @lc app=leetcode id=2289 lang=cpp
 *
 * [2289] Steps to Make Array Non-decreasing
 */
#include <vector>
using namespace std;
// @lc code=start
// t:O(n), s:O(n)
class Solution {
public:
    int totalSteps(vector<int> &nums) {
        int ans = 0;
        vector<pair<int, int>> st;
        for (auto num : nums) {
            int maxT = 0;
            while (!st.empty() && st.back().first <= num) {
                maxT = max(maxT, st.back().second);
                st.pop_back();
            }
            maxT = st.empty() ? 0 : maxT + 1;
            ans = max(ans, maxT);
            st.push_back({num, maxT});
        }
        return ans;
    }
};
// @lc code=end
