use std::collections::HashMap;

pub struct Solution;

impl Solution {
    #[allow(clippy::cast_possible_truncation)]
    #[allow(clippy::cast_possible_wrap)]
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut map = HashMap::new();

        for (i, num) in nums.into_iter().enumerate() {
            match map.get(&(target - num)) {
                Some(&left) => {
                    return vec![left as i32, i as i32];
                }
                None => {
                    map.insert(num, i);
                }
            }
        }

        Vec::new()
    }
}
