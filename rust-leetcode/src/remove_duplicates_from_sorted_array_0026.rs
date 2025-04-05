pub struct Solution;

impl Solution {
    pub fn remove_duplicates(nums: &mut [i32]) -> usize {
        let mut ans = 1;

        for i in 1..nums.len() {
            if nums[i - 1] != nums[i] {
                nums[ans] = nums[i];
                ans += 1;
            }
        }

        ans
    }
}
