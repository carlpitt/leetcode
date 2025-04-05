pub struct Solution;

impl Solution {
    #[allow(clippy::cast_sign_loss)]
    pub fn arithmetic_triplets(nums: Vec<i32>, diff: i32) -> i32 {
        let mut count = [false; 201];
        let mut ans = 0;

        for num in nums {
            if num >= 2 * diff
                && count[(num - diff) as usize]
                && count[(num - 2 * diff) as usize]
            {
                ans += 1;
            }

            count[num as usize] = true;
        }

        ans
    }
}
