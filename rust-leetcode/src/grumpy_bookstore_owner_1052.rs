pub struct Solution;

impl Solution {
    #[allow(clippy::cast_sign_loss)]
    pub fn max_satisfied(
        customers: &[i32],
        grumpy: &[i32],
        minutes: i32,
    ) -> i32 {
        let minutes = minutes as usize;

        let mut total = 0;
        let mut max_diff = 0;

        for i in 0..minutes {
            total += customers[i] * (1 - grumpy[i]);
            max_diff += customers[i] * grumpy[i];
        }

        let mut diff = max_diff;

        for i in minutes..customers.len() {
            total += customers[i] * (1 - grumpy[i]);
            diff += customers[i] * grumpy[i]
                - customers[i - minutes] * grumpy[i - minutes];
            max_diff = max_diff.max(diff);
        }

        total + max_diff
    }
}
