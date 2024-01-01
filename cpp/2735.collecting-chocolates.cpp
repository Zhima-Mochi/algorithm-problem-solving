#include <vector>
#include <numeric>
using namespace std;

class Solution
{
public:
    long long minCost(vector<int> &nums, int x)
    {
        int n = nums.size();
        long long ans = accumulate(nums.begin(), nums.end(), 0LL);
        vector<int> cur = nums;
        for (long long i = 1; i != n; ++i)
        {
            long long cost = i * x;
            for (int j = 0; j != n; ++j)
            {
                cur[j] = min(cur[j], nums[(j + i) % n]);
                cost += cur[j];
            }
            ans = min(ans, cost);
        }
        return ans;
    }
};