#
# @lc app=leetcode id=1761 lang=python3
#
# [1761] Minimum Degree of a Connected Trio in a Graph
#
from collections import defaultdict
# @lc code=start


class Solution:
    def minTrioDegree(self, n: int, edges: List[List[int]]) -> int:
        graphs = defaultdict(set)
        conn_pts = defaultdict(list)
        for edge in edges:
            graphs[edge[0]].add(edge[1])
            graphs[edge[1]].add(edge[0])
        for edge in edges:
            if len(graphs[edge[0]]) < len(graphs[edge[1]]):
                conn_pts[edge[0]].append(edge[1])
            elif len(graphs[edge[0]]) > len(graphs[edge[1]]):
                conn_pts[edge[1]].append(edge[0])
            else:
                if edge[0] < edge[1]:
                    conn_pts[edge[0]].append(edge[1])
                else:
                    conn_pts[edge[1]].append(edge[0])
        pts = list(range(1, n+1))
        pts.sort(key=lambda x: len(graphs[x]))
        INT_MAX = (1 << 31)-1
        res = INT_MAX
        for pt in pts:
            o_pts = conn_pts[pt]
            w = len(o_pts)
            if len(graphs[pt])*3-6 >= res:
                break
            for i in range(w):
                for j in range(i+1, w):
                    if o_pts[i] in graphs[o_pts[j]] or o_pts[j] in graphs[o_pts[i]]:
                        res = min(
                            res, len(graphs[pt])+len(graphs[o_pts[j]])+len(graphs[o_pts[i]])-6)
        return -1 if res == INT_MAX else res

# @lc code=end
