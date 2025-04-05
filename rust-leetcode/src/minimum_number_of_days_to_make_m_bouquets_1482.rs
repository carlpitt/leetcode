pub struct Solution;

impl Solution {
    #[allow(clippy::cast_sign_loss)]
    pub fn min_days(bloom_day: &[i32], m: i32, k: i32) -> i32 {
        let mut ans = -1;
        let mut left = i32::MAX;
        let mut right = 1;

        for &day in bloom_day {
            left = left.min(day);
            right = right.max(day);
        }

        while left <= right {
            let mid = left + (right - left) / 2;
            let mut flowers = 0;
            let mut bouquets = 0;

            for &day in bloom_day {
                if day > mid {
                    flowers = 0;
                } else {
                    flowers += 1;

                    // if flowers == k {
                    //     bouquets += 1;
                    //     flowers = 0;
                    // }

                    bouquets += flowers / k;
                    flowers %= k;
                }
            }

            if bouquets < m {
                left = mid + 1;
            } else {
                ans = mid;
                right = mid - 1;
            }
        }

        ans
    }
}
