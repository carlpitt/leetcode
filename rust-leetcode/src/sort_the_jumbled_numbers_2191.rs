pub struct Solution;

impl Solution {
    #[allow(clippy::cast_sign_loss)]
    pub fn sort_jumbled(mapping: &[i32], nums: &[i32]) -> Vec<i32> {
        let mut pairs = Vec::with_capacity(nums.len());

        for (i, num) in nums.iter().enumerate() {
            let mut num = *num as usize;

            if num == 0 {
                pairs.push((mapping[0], i));

                continue;
            }

            let mut x = 0;
            let mut pow_ten = 1;

            while num > 0 {
                x += mapping[num % 10] * pow_ten;
                pow_ten *= 10;
                num /= 10;
            }

            pairs.push((x, i));
        }

        pairs.sort_unstable();

        let mut ans = Vec::with_capacity(pairs.len());

        for (_, num) in pairs {
            ans.push(nums[num]);
        }

        ans
    }
}
