#
# @lc app=leetcode id=722 lang=python3
#
# [722] Remove Comments
#
from typing import *
# @lc code=start


class Solution:
    def removeComments(self, source: List[str]) -> List[str]:
        is_comment = False
        new_source = []

        def helpler(src: str, is_comment: bool) -> Tuple[str, int]:
            if is_comment:
                end_comment_pos = src.find("*/")
                if end_comment_pos != -1:
                    is_comment = False
                    return helpler(src[end_comment_pos+2:], is_comment)
                else:
                    return ("", is_comment)
            else:
                start_comment_pos = src.find("/*")
                start_comment_pos = len(
                    src) if start_comment_pos == -1 else start_comment_pos
                start_line_comment_pos = src.find("//")
                start_line_comment_pos = len(
                    src) if start_line_comment_pos == -1 else start_line_comment_pos
                if start_line_comment_pos < start_comment_pos:
                    return (src[0:start_line_comment_pos], is_comment)
                elif start_comment_pos != len(src):
                    is_comment = True
                    rest_src, is_comment = helpler(
                        src[start_comment_pos + 2:], is_comment)
                    return (src[0:start_comment_pos]+rest_src, is_comment)
                else:
                    return (src, is_comment)
        for src in source:
            prev_is_comment = is_comment
            src, is_comment = helpler(src, is_comment)
            if prev_is_comment and not is_comment:
                new_source[-1] += src
            elif src != "":
                new_source.append(src)
        return new_source
# @lc code=end
