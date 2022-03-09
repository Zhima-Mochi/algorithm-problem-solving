#
# @lc app=leetcode id=676 lang=python3
#
# [676] Implement Magic Dictionary
#
from collections import defaultdict
# @lc code=start


class MagicDictionary:

    def __init__(self):
        self.len_word_map = defaultdict(list)

    def buildDict(self, dictionary: List[str]) -> None:
        for word in dictionary:
            self.len_word_map[len(word)].append(word)

    def search(self, searchWord: str) -> bool:
        for word in self.len_word_map[len(searchWord)]:
            if searchWord == word:
                continue
            different = 0
            for i in range(len(searchWord)):
                if searchWord[i] != word[i]:
                    different += 1
                    if different > 1:
                        break
            if different == 1:
                return True
        return False


# Your MagicDictionary object will be instantiated and called as such:
# obj = MagicDictionary()
# obj.buildDict(dictionary)
# param_2 = obj.search(searchWord)
# @lc code=end
