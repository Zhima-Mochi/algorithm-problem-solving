/*
 * @lc app=leetcode id=866 lang=cpp
 *
 * [866] Prime Palindrome
 */
// @lc code=start

// t:O(N), s:O(1)
class Solution
{
public:
    int primePalindrome(int n)
    {
        long long start = 1;
        while (start * start * 1000 <= n)
        {
            start *= 10;
        }
        for (; start != 100000; start *= 10)
        {
            for (int is_odd = 1; is_odd != -1; --is_odd)
            {
                for (int i = start, end = start * 10; i != end; ++i)
                {
                    if (start != 1 && i / start % 2 == 0)
                    {
                        continue;
                    }
                    int val = i;
                    int right = is_odd ? i / 10 : i;
                    while (right)
                    {
                        val *= 10;
                        val += right % 10;
                        right /= 10;
                    }
                    if (val >= n && is_prime(val))
                    {
                        return val;
                    }
                }
            }
        }
        return -1;
    }
    bool is_prime(int num)
    {
        if (num == 1)
        {
            return false;
        }
        else if (num == 2)
        {
            return true;
        }
        else if (num % 2 == 0)
        {
            return false;
        }
        for (int i = 3; i * i <= num; i += 2)
        {
            if (num % i == 0)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
