/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */
#include <string>
#include <stack>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isPalindrome(string s)
    {
        int left = 0, right = s.size() - 1;
        stack<char> st;
        while (true)
        {
            while (!isalpha(s[left]) && !isdigit(s[left]))
            {
                left++;
                if (left >= right)
                {
                    return true;
                }
            }
            st.push(tolower(s[left]));
            while (!isalpha(s[right]) && !isdigit(s[right]))
            {
                right--;
                if (left >= right)
                {
                    return true;
                }
            }
            if (st.top() != tolower(s[right]))
            {
                return false;
            }
            else
            {
                left++;
                right--;
                if (left >= right)
                {
                    return true;
                }
                st.pop();
            }
        }
        return true;
        // string ab_string;
        // for(auto & a:s){
        //     if(isalpha(a)||isdigit(a)){
        //         ab_string.push_back(tolower(a));
        //     }
        // }
        // auto len=ab_string.size();
        // auto middle=len/2;
        // for(int i=0;i!=middle;i++){
        //     if(ab_string[i]!=ab_string[len-1-i]){
        //         return false;
        //     }
        // }
        // return true;
    }
};
// @lc code=end
