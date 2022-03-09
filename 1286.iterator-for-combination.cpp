/*
 * @lc app=leetcode id=1286 lang=cpp
 *
 * [1286] Iterator for Combination
 */
#include <string>
using namespace std;
// @lc code=start
class CombinationIterator
{
    int mask = 0;
    int character_len;
    bool has_next = true;
    string chars;

public:
    CombinationIterator(string characters, int combinationLength)
    {
        chars = characters;
        character_len = characters.size();
        for (int i = 0; i != combinationLength; ++i)
        {
            mask |= 1 << (character_len - 1 - i);
        }
    }

    string next()
    {
        string res;
        for (int i = 0; i != character_len; ++i)
        {
            if (mask & (1 << (character_len - 1 - i)))
            {
                res.push_back(chars[i]);
            }
        }
        int rightest_bit = mask & -mask;
        if (rightest_bit != 1)
        {
            mask ^= rightest_bit;
            mask |= rightest_bit >> 1;
        }
        else
        {
            int right_cont_bit = 0;
            for (int i = 0; i != character_len; ++i)
            {
                if (mask & (1 << i))
                {
                    right_cont_bit |= (1 << i);
                }
                else
                {
                    break;
                }
            }

            mask ^= right_cont_bit;
            if (mask == 0)
            {
                has_next = false;
            }
            else
            {
                int rightest_bit = mask & -mask;
                mask ^= rightest_bit;
                mask |= rightest_bit >> 1;
                while (((right_cont_bit << 1) & mask) == 0)
                {
                    right_cont_bit <<= 1;
                }
                mask |= right_cont_bit;
            }
        }
        return res;
    }

    bool hasNext()
    {
        return has_next;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end
