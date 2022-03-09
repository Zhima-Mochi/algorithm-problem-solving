#
# @lc app=leetcode id=811 lang=python3
#
# [811] Subdomain Visit Count
#
from collections import Counter
from typing import *
# @lc code=start


class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        record = Counter()
        for cpdomain in cpdomains:
            pos = cpdomain.find(' ')
            num = int(cpdomain[:pos])
            record[cpdomain[pos+1:]] += num
            while (pos := cpdomain.find('.', pos+1)) != -1:
                record[cpdomain[pos+1:]] += num
        res = []
        for cpdomain, num in record.items():
            res.append(str(num)+' '+cpdomain)
        return res

# @lc code=end
