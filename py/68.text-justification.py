#
# @lc app=leetcode id=68 lang=python3
#
# [68] Text Justification
#

# @lc code=start
class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        w = len(words)
        left = 0
        right = 0
        cur_len = 0
        res = []
        while left != w:
            if right == w:
                s = []
                while left != right:
                    s.append(words[left])
                    left += 1
                res.append(" ".join(s)+(maxWidth-len(" ".join(s)))*" ")
            elif cur_len+len(words[right])+right-left > maxWidth:
                if left+1 == right:
                    res.append(words[left]+" "*(maxWidth-cur_len))
                    left += 1
                else:
                    blank_num = (maxWidth-cur_len)//(right-left-1)
                    add_one_cnt = (maxWidth-cur_len) % (right-left-1)
                    s = []
                    while left != right:
                        s.append(words[left])
                        left += 1
                        if left == right:
                            break
                        if add_one_cnt:
                            s.append(" "*(blank_num+1))
                            add_one_cnt -= 1
                        else:
                            s.append(" "*(blank_num))
                    res.append(''.join(s))
                cur_len = 0
            else:
                cur_len += len(words[right])
                right += 1
        return res


# @lc code=end
