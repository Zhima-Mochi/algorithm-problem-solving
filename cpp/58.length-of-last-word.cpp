/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        auto right_bound=s.find_last_not_of(' ');
        if (right_bound==-1){
            return 0;
        }
        return right_bound-s.find_last_of(' ',right_bound);
    }
};
// @lc code=end

