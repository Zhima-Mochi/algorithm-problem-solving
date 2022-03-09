#
# @lc app=leetcode id=648 lang=python3
#
# [648] Replace Words
#
from typing import *
from collections import defaultdict
# @lc code=start


class TrieNode:
    def __init__(self):
        self.has_word = False
        self.word = ''
        self.next = {}


class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        root = TrieNode()
        width = len(sentence)
        for dict in dictionary:
            cur = root
            for c in dict:
                if c not in cur.next:
                    cur.next[c] = TrieNode()
                cur = cur.next[c]
                if cur.has_word:
                    break
            if not cur.has_word:
                cur.has_word = True
                cur.word = dict
                cur.next={}

        def replaced_word(root, sentence, pos):
            while pos != width and sentence[pos] != ' ':
                if sentence[pos] in root.next:
                    root = root.next[sentence[pos]]
                    if root.has_word:
                        break
                else:
                    return ''
                pos += 1
            return root.word
        pos = 0
        res = []
        while True:
            dict_word = replaced_word(root, sentence, pos)
            next_pos = sentence.find(' ', pos)
            if dict_word == '':
                if next_pos != -1:
                    res.append(sentence[pos:next_pos])
                else:
                    res.append(sentence[pos:])
            else:
                res.append(dict_word)
            if next_pos != -1:
                pos = next_pos+1
            else:
                break
        return ' '.join(res)
# @lc code=end
