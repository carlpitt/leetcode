pub struct Solution;

impl Solution {
    pub fn product_except_self(nums: &[i32]) -> Vec<i32> {
        let n = nums.len();
        let mut ans = vec![1; n];
        let mut prefix = 1;
        let mut suffix = 1;

        for i in 0..n {
            ans[i] *= prefix;
            prefix *= nums[i];
            ans[n - i - 1] *= suffix;
            suffix *= nums[n - i - 1];
        }

        ans
    }
}
