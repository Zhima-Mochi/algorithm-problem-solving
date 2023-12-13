/*
 * @lc app=leetcode id=2454 lang=cpp
 *
 * [2454] Next Greater Element IV
 */
#include <vector>
#include <functional>
using namespace std;
// @lc code=start
// t:O(n), s:O(n)
class Solution
{
public:
    vector<int> secondGreaterElement(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> gt_idx(n, n), sec_gt_idx(n, n);
        vector<int> ans(n, -1);

        function<int(int)> get_gt_idx = [&](int pos)
        {
            auto cur = pos + 1;
            auto val = nums[pos];
            while (cur != n && nums[cur] <= val)
            {
                if (nums[cur] == val)
                {
                    return gt_idx[cur];
                }
                cur = gt_idx[cur];
            }
            return cur;
        };

        function<int(int)> get_sec_gt_idx = [&](int pos)
        {
            auto cur = pos + 1;
            auto val = nums[pos];
            int cnt = 0;
            while (cur != n && cnt != 2)
            {
                if (nums[cur] == val)
                {
                    if (cnt == 1)
                    {
                        return gt_idx[cur];
                    }
                    else
                    {
                        return sec_gt_idx[cur];
                    }
                }
                else if (nums[cur] > val)
                {
                    cnt += 1;
                    if (cnt == 2)
                    {
                        return cur;
                    }
                    cur += 1;
                }
                else
                {
                    cur = gt_idx[cur];
                }
            }
            return n;
        };
        for (int i = n - 2; i != -1; i--)
        {
            gt_idx[i] = get_gt_idx(i);
            sec_gt_idx[i] = get_sec_gt_idx(i);
            ans[i] = sec_gt_idx[i] == n ? -1 : nums[sec_gt_idx[i]];
        }

        return ans;
    }
};
// @lc code=end
