import java.util.TreeSet;

class Solution {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int indexDiff, int valueDiff) {
        // if (nums == null || nums.length < 2 || indexDiff < 1 || valueDiff < 0) {
        //     return false;
        // }

        TreeSet<Long> set = new TreeSet<>();
        for (int i = 0; i < nums.length; i++) {
            Long num = (long) nums[i];

            // Find the smallest number >= nums[i] - valueDiff
            Long floor = set.floor(num + valueDiff);
            if (floor != null && floor >= num - valueDiff) {
                return true;
            }

            set.add(num);

            // Maintain the size of the set to be at most indexDiff
            if (i >= indexDiff) {
                set.remove((long) nums[i - indexDiff]);
            }
        }

        return false;
    }
}
