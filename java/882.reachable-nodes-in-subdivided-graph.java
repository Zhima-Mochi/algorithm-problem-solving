import java.util.ArrayList;
import java.util.Arrays;
import java.util.SortedSet;
import java.util.TreeSet;

/*
* @lc app=leetcode id=882 lang=java
*
* [882] Reachable Nodes In Subdivided Graph
*/
// @lc code=start

import java.util.NavigableSet;

class Solution {
    public static class Pair<K, V> {
        public K first;
        public V second;

        public Pair(K elem0, V elem1) {
            this.first = elem0;
            this.second = elem1;
        }
    }

    public int reachableNodes(int[][] edges, int maxMoves, int n) {
        int res = 1;
        List<Pair<Integer, Integer>>[] umap = new ArrayList[n];
        for (int i = 0; i < n; ++i) {
            umap[i] = new ArrayList<>();
        }
        for (var edge : edges) {
            umap[edge[1]].add(new Pair(edge[0], edge[2]));
            umap[edge[0]].add(new Pair(edge[1], edge[2]));
        }
        int[] restMoves = new int[n];
        Arrays.fill(restMoves, -1);
        restMoves[0] = maxMoves;
        NavigableSet<Integer> q = new TreeSet<Integer>((l, r) -> {
            if (restMoves[l] == restMoves[r]) {
                return r - l;
            } else {
                return restMoves[r] - restMoves[l];
            }
        });
        q.add(0);
        while (!q.isEmpty()) {
            var elem = q.first();
            q.remove(elem);
            for (Pair<Integer, Integer> mp : umap[elem]) {
                int currentRestMove = restMoves[elem] - mp.second;
                if (currentRestMove >= 1) {
                    if (restMoves[mp.first] == -1) {
                        ++res;
                        restMoves[mp.first] = 0;
                    }
                    if (restMoves[mp.first] < currentRestMove - 1) {
                        q.remove(mp.first); // it is necessary
                        restMoves[mp.first] = currentRestMove - 1;
                        q.add(mp.first);
                    }
                }
            }
        }
        for (int i = 0; i != n; ++i) {
            if (restMoves[i] == -1) {
                restMoves[i] = 0;
            }
        }
        for (var edge : edges) {
            res += Math.min(restMoves[edge[0]] + restMoves[edge[1]], edge[2]);
        }
        return res;
    }
}
// @lc code=end
