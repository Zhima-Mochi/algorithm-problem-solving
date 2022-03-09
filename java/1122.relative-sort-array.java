import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;
import java.util.stream.Collectors;

/*
 * @lc app=leetcode id=1122 lang=java
 *
 * [1122] Relative Sort Array
 */

// @lc code=start
class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        int[] count = new int[1001];
        for (int i = 0; i < arr1.length; ++i) {
            ++count[arr1[i]];
        }
        int cur = 0;
        for (var n : arr2) {
            while (count[n] != 0) {
                arr1[cur++] = n;
                --count[n];
            }
        }
        for (var i=0;i<count.length;++i) {
            while (count[i] != 0) {
                arr1[cur++] = i;
                --count[i];
            }
        }
        return arr1;
    }
}
// @lc code=end

// class Solution {
// public int[] relativeSortArray(int[] arr1, int[] arr2) {
// Map<Integer, Integer> comp_order = new HashMap<>();
// for (int i = 0; i != arr2.length; ++i) {
// comp_order.put(arr2[i], i);
// }
// List<Integer> list =
// Arrays.stream(arr1).boxed().collect(Collectors.toList());;
// Collections.sort(list, new MyComp(comp_order));
// return list.stream().mapToInt(i->i).toArray();
// }
// }

// class MyComp implements Comparator<Integer> {
// Map<Integer, Integer> comp_order;

// MyComp(Map<Integer, Integer> _comp_order) {
// comp_order = _comp_order;
// }

// @Override
// public int compare(Integer l, Integer r) {
// if (comp_order.containsKey(l) && comp_order.containsKey(r)) {
// return comp_order.get(l) - comp_order.get(r);
// } else if (comp_order.containsKey(l)) {
// return -1;
// } else if (comp_order.containsKey(r)) {
// return 1;
// } else {
// return l - r;
// }
// }
// }