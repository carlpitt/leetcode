pub struct Solution;

impl Solution {
    pub fn number_of_subarrays(nums: &[i32], mut k: i32) -> i32 {
        let mut ans = 0;
        let mut evens = 0;
        let mut i = 0;

        for num in nums {
            if num % 2 == 1 {
                k -= 1;
                evens = 0;
            }

            while k == 0 {
                k += nums[i] % 2;
                i += 1;
                evens += 1;
            }

            ans += evens;
        }

        ans
    }
}
