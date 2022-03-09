#
# @lc app=leetcode id=1455 lang=python3
#
# [1455] Check If a Word Occurs As a Prefix of Any Word in a Sentence
#

# @lc code=start
class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        pos = 0
        index = 1
        while pos != -1:
            while not sentence[pos].isalpha():
                pos += 1
            if sentence.startswith(searchWord, pos):
                return index
            index += 1
            pos = sentence.find(' ', pos)
        return -1
# @lc code=end
