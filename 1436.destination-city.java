import java.awt.List;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;

import org.graalvm.compiler.nodes.DeoptimizingNode.DeoptAfter;

/*
 * @lc app=leetcode id=1436 lang=java
 *
 * [1436] Destination City
 */

// @lc code=start
class Solution {
    public String destCity(List<List<String>> paths) {
        Set<String> depart_place = new HashSet<>();
        for (List<String> pr : paths) {
            depart_place.add(pr.get(0));
        }
        for (List<String> pr : paths) {
            if (!depart_place.contains(pr.get(1))) {
                return pr.get(1);
            }
        }
        return "";
    }
}
// @lc code=end
