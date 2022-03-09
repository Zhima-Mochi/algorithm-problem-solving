/*
 * @lc app=leetcode id=927 lang=cpp
 *
 * [927] Three Equal Parts
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> threeEqualParts(vector<int> &arr)
    {
        int len = arr.size();
        int cur_head = 0;
        while (cur_head != len && arr[cur_head] == 0)
        {
            ++cur_head;
        }
        if (cur_head == len)
        {
            return vector<int>({0, len - 1});
        }
        int one_count = 0;
        for (int i = cur_head; i != len; ++i)
        {
            if (arr[i] == 1)
            {
                ++one_count;
            }
        }
        if (one_count % 3 != 0)
        {
            return vector<int>({-1, -1});
        }
        int tail_0_count = 0;
        for (int i = len - 1; arr[i] == 0; --i)
        {
            ++tail_0_count;
        }
        int cur = cur_head;

        for (int count = 0, bound = one_count / 3; count != bound; ++cur)
        {
            if (arr[cur] == 1)
            {
                ++count;
            }
        }
        for (int count = 0; count != tail_0_count; ++cur, ++count)
        {
            if (arr[cur] != 0)
            {
                return vector<int>({-1, -1});
            }
        }

        auto left = cur - 1;

        if (len - cur < 2 * (left + 1 - cur_head))
        {
            return vector<int>({-1, -1});
        }

        while (arr[cur] == 0)
        {
            ++cur;
        }

        if (len - cur < 2 * (left + 1 - cur_head))
        {
            return vector<int>({-1, -1});
        }

        for (int i = cur_head; i != left + 1; ++i, ++cur)
        {
            if (arr[i] != arr[cur])
            {
                return vector<int>({-1, -1});
            }
        }

        if (len - cur < (left + 1 - cur_head))
        {
            return vector<int>({-1, -1});
        }

        int right = cur;
        while (arr[cur] == 0)
        {
            ++cur;
        }

        if (len - cur != left + 1 - cur_head)
        {
            return vector<int>({-1, -1});
        }

        for (int i = cur_head; i != left + 1; ++i, ++cur)
        {
            if (arr[i] != arr[cur])
            {
                return vector<int>({-1, -1});
            }
        }

        return vector<int>({left, right});
    }
};
// @lc code=end
//[0,0,0,0,1,0,0,1,1,0,0,0,1,0,0,0,0,0,1,0,0,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,0,1,0,0,0,0,0]  [1,1,0,0,1]
