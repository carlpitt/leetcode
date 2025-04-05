pub struct Solution;

impl Solution {
    #[allow(clippy::cast_sign_loss)]
    pub fn min_k_bit_flips(mut nums: Vec<i32>, k: i32) -> i32 {
        let k = k as usize;
        let mut ans = 0;
        let mut curr = 0;

        for i in 0..nums.len() {
            if i >= k && nums[i - k] > 1 {
                curr -= 1;
            }

            if curr % 2 == nums[i] {
                if i + k > nums.len() {
                    return -1;
                }

                nums[i] = 2;
                curr += 1;
                ans += 1;
            }
        }

        ans
    }
}
