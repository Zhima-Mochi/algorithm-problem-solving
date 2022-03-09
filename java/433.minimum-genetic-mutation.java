import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.concurrent.LinkedBlockingDeque;

/*
 * @lc app=leetcode id=433 lang=java
 *
 * [433] Minimum Genetic Mutation
 */

// @lc code=start
class Solution {
    public int minMutation(String start, String end, String[] bank) {
        Set<String> bank_set = new HashSet<>();
        for (var s : bank) {
            bank_set.add(s);
        }
        Queue<String> q = new LinkedList<>();
        q.add(start);
        int round = 0;
        Set<String> used_gen = new HashSet<>();
        used_gen.add(start);
        while (!q.isEmpty()) {
            ++round;
            int q_len = q.size();
            while (q_len-- != 0) {
                var cur_gene = q.poll();
                for (var s : bank) {
                    if (canMutate(cur_gene, s)) {
                        if (s.equals(end)) {
                            return round;
                        } else if (!used_gen.contains(s)) {
                            used_gen.add(s);
                            q.add(s);
                        }
                    }
                }
            }
        }
        return -1;
    }

    Boolean canMutate(String og, String mut) {
        byte count = 0;
        for (int i = 0; i != 8; ++i) {
            if (og.charAt(i) != mut.charAt(i)) {
                ++count;
            }
        }
        return count == 1;
    }
}
// @lc code=end
