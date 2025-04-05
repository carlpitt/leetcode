pub struct Solution;

impl Solution {
    #[allow(clippy::cast_sign_loss)]
    pub const fn min_patches(nums: &[i32], n: i32) -> i32 {
        // let mut x = 1;
        // let mut i = 0;
        // let mut ans = 0;

        // while x <= n as u32 {
        //     if i < nums.len() && nums[i] as u32 <= x {
        //         x += nums[i] as u32;
        //         i += 1;
        //     } else {
        //         x *= 2;
        //     }
        //     ans += 1;
        // }

        // ans - i as i32

        let mut x = 1;
        let mut i = 0;
        let mut ans = 0;

        while x <= n as u32 {
            if i < nums.len() && nums[i] as u32 <= x {
                x += nums[i] as u32;
                i += 1;
            } else {
                x *= 2;
                ans += 1;
            }
        }

        ans
    }
}
