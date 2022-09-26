#include <vector>
#include<unordered_set>
using namespace std;
class Solution
{
public:
    vector<int> missingTwo(vector<int> &nums)
    {
        int w = nums.size();
        unordered_set<int>seen;
        for (int i = 0; i != w; ++i)
        {
            int n = abs(nums[i]);
            if (n <= w)
            {
                nums[n - 1] *= -1;
            }
            else
            {
                seen.insert(n);
            }
        }
        vector<int> res;
        for (int i = 0; i != w; ++i)
        {
            if (nums[i] > 0)
            {
                res.push_back(i + 1);
            }
        }
        int cur = w + 1;
        while (res.size() < 2)
        {
            if (!seen.count(cur))
            {
                res.push_back(cur);
            }
            ++cur;
        }
        return res;
    }
};