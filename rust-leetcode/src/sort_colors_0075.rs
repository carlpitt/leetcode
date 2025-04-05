pub struct Solution;

impl Solution {
    pub fn sort_colors(nums: &mut [i32]) {
        let mut red = 0;
        let mut white = 0;
        let mut blue = nums.len() - 1;

        while white <= blue {
            match nums[white] {
                0 => {
                    nums.swap(red, white);
                    red += 1;
                    white += 1;
                }
                1 => {
                    white += 1;
                }
                _ => {
                    // 2
                    nums.swap(white, blue);
                    blue = blue.saturating_sub(1);
                }
            }
        }
    }
}
