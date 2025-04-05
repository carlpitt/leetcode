pub struct Solution;

impl Solution {
    #[allow(clippy::cast_sign_loss)]
    pub fn min_increment_for_unique(nums: Vec<i32>) -> i32 {
        // let n = nums.len();

        // O(n * log(n))

        // nums.sort_unstable();

        // let mut ans = 0;

        // for i in 1..n {
        //     if nums[i - 1] >= nums[i] {
        //         ans += nums[i - 1] - nums[i] + 1;
        //         nums[i] = nums[i - 1] + 1;
        //     }
        // }

        // ans

        // O(max(n, max_num))

        let mut max_num = 0;

        for &num in &nums {
            max_num = max_num.max(num as usize);
        }

        let mut freq = vec![0; max_num + 1];

        for num in nums {
            freq[num as usize] += 1;
        }

        let mut ans = 0;

        for i in 0..max_num {
            if freq[i] > 1 {
                let extra = freq[i] - 1;
                freq[i + 1] += extra;
                ans += extra;
            }
        }

        let extra = freq[max_num] - 1;

        ans + extra * (extra + 1) / 2
    }
}
