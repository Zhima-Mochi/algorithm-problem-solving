/*
 * @lc app=leetcode id=1455 lang=java
 *
 * [1455] Check If a Word Occurs As a Prefix of Any Word in a Sentence
 */

// @lc code=start
class Solution {
    public int isPrefixOfWord(String sentence, String searchWord) {
        int pos = 0;
        int searchWord_width = searchWord.length();
        int index = 1;
        while (pos != -1) {
            while (!Character.isAlphabetic(sentence.charAt(pos))) {
                ++pos;
            }
            boolean match = true;
            for (int i = 0; i != searchWord_width; ++i) {
                if (sentence.charAt(pos + i) != searchWord.charAt(i)) {
                    match = false;
                    break;
                }
            }
            if (match) {
                return index;
            }
            ++index;
            pos = sentence.indexOf(' ', pos);
        }
        return -1;
    }
}
// @lc code=end
