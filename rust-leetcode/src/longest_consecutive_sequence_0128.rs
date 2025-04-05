use std::collections::HashSet;

pub struct Solution;

impl Solution {
    pub fn longest_consecutive(nums: Vec<i32>) -> i32 {
        let num_set = nums.into_iter().collect::<HashSet<_>>();
        let mut ans = 0;

        for num in &num_set {
            if num_set.contains(&(num - 1)) {
                continue;
            }

            let mut x = num + 1;

            while num_set.contains(&x) {
                x += 1;
            }

            ans = ans.max(x - num);
        }

        ans
    }
}
