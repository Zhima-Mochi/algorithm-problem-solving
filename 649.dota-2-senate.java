/*
 * @lc app=leetcode id=649 lang=java
 *
 * [649] Dota2 Senate
 */

// @lc code=start
class Solution {
    public String predictPartyVictory(String senate) {
        int left_r = 0;
        int left_d = 0;
        int right_r = 0;
        int right_d = 0;
        int width = senate.length();
        var senate_arr=senate.toCharArray();
        for (int i = 0; i != width; ++i)
        {
            if (senate_arr[i] == 'R')
            {
                right_d = Math.max(i, right_d);
                while (right_d != width && senate_arr[right_d] != 'D')
                {
                    ++right_d;
                }
                if (right_d != width)
                {
                    senate_arr[right_d] = 'X';
                }
                else
                {
                    while (left_d < i && senate_arr[left_d] != 'D')
                    {
                        ++left_d;
                    }
                    if (left_d == i)
                    {
                        return "Radiant";
                    }
                    else
                    {
                        senate_arr[left_d++] = 'X';
                    }
                }
            }
            else if (senate_arr[i] == 'D')
            {

                right_r = Math.max(i, right_r);
                while (right_r != width && senate_arr[right_r] != 'R')
                {
                    ++right_r;
                }
                if (right_r != width)
                {
                    senate_arr[right_r] = 'X';
                }
                else
                {
                    while (left_r < i && senate_arr[left_r] != 'R')
                    {
                        ++left_r;
                    }
                    if (left_r == i)
                    {
                        return "Dire";
                    }
                    else
                    {
                        senate_arr[left_r++] = 'X';
                    }
                }
            }
        }
        StringBuilder next=new StringBuilder();
        for (char c : senate_arr)
        {
            if (c != 'X')
            {
                next.append(c);
            }
        }
        return predictPartyVictory(next.toString());
    }
}
// @lc code=end

