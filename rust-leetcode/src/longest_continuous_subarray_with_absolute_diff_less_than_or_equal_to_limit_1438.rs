use std::collections::VecDeque;

pub struct Solution;

impl Solution {
    #[allow(clippy::cast_possible_truncation)]
    #[allow(clippy::cast_possible_wrap)]
    pub fn longest_subarray(nums: &[i32], limit: i32) -> i32 {
        let mut max_deque = VecDeque::new();
        let mut min_deque = VecDeque::new();
        let mut ans = 0;
        let mut j = 0;

        for i in 0..nums.len() {
            let num = nums[i];

            while !max_deque.is_empty() && num > *max_deque.back().unwrap() {
                max_deque.pop_back();
            }

            while !min_deque.is_empty() && num < *min_deque.back().unwrap() {
                min_deque.pop_back();
            }

            max_deque.push_back(num);
            min_deque.push_back(num);

            let max_value = *max_deque.front().unwrap();
            let min_value = *min_deque.front().unwrap();

            if max_value - min_value > limit {
                let num = nums[j];

                if max_value == num {
                    max_deque.pop_front();
                }

                if min_value == num {
                    min_deque.pop_front();
                }

                j += 1;
            }

            ans = ans.max(i - j + 1);
        }

        ans as i32
    }
}
