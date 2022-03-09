/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 */
#include <unordered_map>
#include <stack>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> umap;
        stack<int> st;
        for (auto &n : nums2)
        {
            if (st.empty())
            {
                st.push(n);
            }
            else
            {
                while (!st.empty() && st.top() < n)
                {
                    umap[st.top()] = n;
                    st.pop();
                }
                st.push(n);
            }
        }
        for (auto &n : nums1)
        {
            if (umap.count(n))
            {
                n = umap[n];
            }
            else
            {
                n = -1;
            }
        }
        return nums1;
    }
};
// @lc code=end
