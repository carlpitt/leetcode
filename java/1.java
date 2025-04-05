// Two sum

import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.stream.Collectors;

class Solution {
  public int[] twoSum(int[] nums, int target) {
    int index = 0;
    HashMap<Integer, Integer> numsH = new HashMap<Integer, Integer>();
    List<Integer> list = Arrays.stream(nums).boxed().collect(Collectors.toList());

    if ((nums[0] + nums[nums.length - 1]) == target) {
      return new int[] {0, nums.length - 1};
    }

    if ((nums[nums.length - 2] + nums[nums.length - 1]) == target) {
      return new int[] {nums.length - 2, nums.length - 1};
    }

    for (int setNums : nums) {
      int ans = target - setNums;

      if (numsH.containsValue(ans)) {
        return new int[] {list.indexOf(ans), index};
      }

      numsH.put(index, setNums);

      ++index;
    }

    return nums;
  }
}
