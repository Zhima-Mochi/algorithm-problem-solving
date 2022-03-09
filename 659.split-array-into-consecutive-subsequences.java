import java.util.PriorityQueue;

/*
 * @lc app=leetcode id=659 lang=java
 *
 * [659] Split Array into Consecutive Subsequences
 */

// @lc code=start
class Solution {
    class Pair implements Comparable<Pair> {
        Integer first;
        Integer second;

        public Pair(Integer _first, Integer _second) {
            this.first = _first;
            this.second = _second;
        }

        @Override
        public int compareTo(Pair o) {
            return ((this.first - o.first) << 15) + this.second - o.second;
        }
    }

    public boolean isPossible(int[] nums) {
        PriorityQueue<Pair> pos_len_queue = new PriorityQueue<>();
        for (int n : nums) {
            while (!pos_len_queue.isEmpty() && n > pos_len_queue.peek().first + 1 && pos_len_queue.peek().second >= 3) {
                pos_len_queue.poll();
            }
            if (pos_len_queue.isEmpty()) {
                pos_len_queue.add(new Pair(n, 1));
            } else if (n == pos_len_queue.peek().first) {
                pos_len_queue.add(new Pair(n, 1));
            } else if (n == pos_len_queue.peek().first + 1) {
                var elem = pos_len_queue.poll();
                elem.first += 1;
                elem.second += 1;
                pos_len_queue.add(elem);
            } else {
                return false;
            }
        }
        while (!pos_len_queue.isEmpty()) {
            if (pos_len_queue.poll().second < 3) {
                return false;
            }
        }
        return true;
    }
}
// @lc code=end
